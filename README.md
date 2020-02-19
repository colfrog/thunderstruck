# Thunderstruck

## Compilation

Thunderstruck utilise CMake pour compiler le projet. Son comportement est programmé dans CMakeLists.txt, qui est bien commenté. Le coeur du jeu est dans une librairie appelée libWWIII. Tous les headers de libWWIII sont exposés aux programmes tests et à la demo, on peut alors les inclure avec `#include <Header.h>`.

CMake nous permet de définir une version, elle est à l'entête du CMakeLists.txt. Nous allons augmenter la version de 0.0.1 pour un changement mineur (finir les armes, le magasin), de 0.1 pour un changement majeur (ajout de la classe Jeu), et de 1 lorsque le jeu est terminé. S'il vous plaît, n'augmentez pas la version si les tests de la nouvelle classe ne sont pas faits.

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

À partir de la ligne de commande, dans thunderstruck:

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Pour recompiler, sauf si CMakeLists.txt a changé, vous avez seulement à rééxécuter `make` dans le répertoire build.

Si CMakeLists.txt a changé, il faut rééxécuter `cmake ..` dans le répertoire build avant.