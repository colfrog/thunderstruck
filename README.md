# Thunderstruck

## Compilation

Thunderstruck utilise CMake pour compiler le projet. Son comportement est programmé dans CMakeLists.txt, qui est bien commenté. Le coeur du jeu est dans une librairie appelée libWWIII. Tous les headers de libWWIII sont exposés aux programmes tests et à la demo, on peut alors les inclure avec `#include <Header.h>`.

CMake nous permet de définir une version, elle est à l'entête du CMakeLists.txt. Nous allons augmenter la version de 0.0.1 pour un changement mineur (finir les armes, le magasin), de 0.1 pour un changement majeur (ajout de la classe Jeu), et de 1 lorsque le jeu est terminé. S'il vous plaît, n'augmentez pas la version si les tests de la nouvelle classe ne sont pas faits. Essayer aussi de commencer les plus gros ajouts sur une nouvelle branche et de faire une pull request lorsque l'ajout est fait.

### Description du système de compilation

Tous les fichiers .cpp et .h dans libWWIII sont détectés, trackés pour les changements avec CMake et compilés dans une librairie.

demo est un exécutable compilé et lié à libWWIII, il contiendra la démonstration programmée avec la librairie libWWIII.

CMake est programmé pour transformer chaque fichier `.cc` dans tests/ en exécutable et l'ajouter aux tests. Alors, pour créer un nouveau test, on a qu'à ajouter un fichier `.cc` avec un main dans tests. Si la fonction main retourne 1, le test a échoué, et si elle retourne 0, le test est réussi. Des prints devraient aussi être utilisés pour pouvoir suivre l'exécution du test.

Généralement, on voudrait un fichier test par classe majeure, contenant une fonction par test qui retourne 0 si le test est réussi et 1 s'il a échoué. Le main devrait exécuter toutes les fonctions test et retourner leur valeur de retour si elle n'est pas 0.

```c
int test1() { return 0; }
int test2() { return 1; }

int main() {
	int ret = test1();
	if (ret != 0)
		return ret;

	ret = test2();
	return ret;
}

/* OU
int main() {
	int ret = test1();
	ret |= test2(); // 0 si test2 retourne 0, 1 si test2 retourne 1
	return ret;
}
 */
```

### Compiler sur votre plateforme

Si vous voulez utiliser quelque chose d'autre que VS2017 sur Windows, cherchez une extension cmake pour votre éditeur.

#### Windows

Avec VS2017, aller dans Fichier>Ouvrir>CMake et choisir CMakeLists.txt
dans le répertoire de Thunderstruck.

Lorsque VS2017 exécute cmake (par lui-même), il ajoute tous les tests dans sa liste de tests. Pour les gérer, aller dans Test>Fenêtres>Explorateur de tests.

#### Linux

Si vous avez un éditeur de texte, cherchez une extension cmake.

Pour compiler à partir de la ligne de commande, dans thunderstruck:

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Pour recompiler, sauf si CMakeLists.txt a changé, vous avez seulement à rééxécuter `make` dans le répertoire build.

Si CMakeLists.txt a changé, il faut rééxécuter `cmake ..` dans le répertoire build avant.

Pour exécuter les tests, exécuter `make test` dans le répertoire build.

## Fonctionnement de libWWIII

libWWIII présente une interface à un jeu par la classe [Jeu](libWWIII/Jeu.h).

Cette classe contient un objet [Niveau](libWWIII/Niveau.h).
Niveau contient un int qui représente le niveau actuel, et calcule
les variables qui dépendent de ce niveau. Ces variables sont des choses
comme la probabilité de dropper un item, le montant d'or à dropper,
la probabilité d'avancer (essentiellement la vitesse), le dégât infligé
par les ennemis et leur probabilité de spawner. De nouvelles variables
devraient être ajoutées au fur et à mesure qu'on construit le jeu.

La classe Jeu contient aussi une liste d'éléments.
Chaque [Élément](libWWIII/Element.h) peut être soit
un [Personnage](libWWIII/Personnage.h], une [Tour](libWWIII/Tour.h),
ou une [Lane](libWWIII/Lane.h). Lorsque le jeu avance d'un pas,
la méthode virtuelle step de chaque élément est appelée pour que chaque
objet dans le jeu accomplisse un action. La classe Jeu expose le Niveau
à chaque Élément pour qu'ils aient accès aux variables.

Chaque Personnage a une direction (où avancer, tirer), un nombre de vie,
un nom et des attribus.

L'action de la Tour est d'activer l'action du [Player](libWWIII/Player.h),
un Personnage. L'action du Player est de tranquillement regénérer sa vie.
Le Player sera exposé par la classe Jeu et manipulé directement
par le programme.

Le Player contient un [Shop](libWWIII/Shop.h). Le Shop contient une liste
pour chaque type d'[Item](libWWIII/Item.h). Ces types sont la classe
[Defense](libWWIII/Defense.h), [Weapon](libWWIII/Weapon.h) et
[Potion](libWWIII/Potion.h). Chacune a ses propres attribus et utilités,
et le Player contient une liste de chacune. Le premier de la liste est équipé.

La classe [Lane](libWWIII/Lane.h) contient une liste
d'[Enemy](libWWIII/Enemy.h), un autre Personnage.
Puisque Lane et Enemy contiennent tous les deux un pointeur au Niveau
du fait qu'ils sont des Éléments, Lane peut utiliser Niveau pour décider
quand spawner les Enemy, et il incrémente le niveau après avoir spawné
un certain nombre d'Enemy. Les Enemy sont tués par le Player qui contient
un pointeur à chaque Lane pour pouvoir les attaquer. Alors, l'attaque
inflicte du dégât à l'Enemy à l'avant selon le Weapon.

L'action de la classe Lane est d'actionner chaque Enemy, du plus à l'avant
aux plus à l'arrière, et d'ensuite décider d'en spawner un nouveau à l'aide
de Niveau.

L'action d'un Enemy est de demander au Niveau de le laisser avancer.
Lorsqu'il arrive au bout de la Lane, ce qu'il peut faire en ayant en mémoire
la distance de la Lane et un compteur de pas, il inflige du dégât à la Tour
si sa vie est supérieure à 0, ou au Player sinon. Il le fait en gardant un
pointeur à la Tour, qui inflige le dégât au Player si sa vie est 0.
