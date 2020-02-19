# Thunderstruck

## Compilation

Thunderstruck utilise CMake pour compiler le projet. Son comportement est programm� dans CMakeLists.txt, qui est bien comment�. Le coeur du jeu est dans une librairie appel�e libWWIII. Tous les headers de libWWIII sont expos�s aux programmes tests et � la demo, on peut alors les inclure avec `#include <Header.h>`.

CMake nous permet de d�finir une version, elle est � l'ent�te du CMakeLists.txt. Nous allons augmenter la version de 0.0.1 pour un changement mineur (finir les armes, le magasin), de 0.1 pour un changement majeur (ajout de la classe Jeu), et de 1 lorsque le jeu est termin�. S'il vous pla�t, n'augmentez pas la version si les tests de la nouvelle classe ne sont pas faits.

### Description du syst�me de compilation

Tous les fichiers .cpp et .h dans libWWIII sont d�tect�s, track�s pour les changements avec CMake et compil�s dans une librairie.

demo est un ex�cutable compil� et li� � libWWIII, il contiendra la d�monstration programm�e avec la librairie libWWIII.

CMake est programm� pour transformer chaque fichier `.cc` dans tests/ en ex�cutable et l'ajouter aux tests. Alors, pour cr�er un nouveau test, on a qu'� ajouter un fichier `.cc` avec un main dans tests. Si la fonction main retourne 1, le test a �chou�, et si elle retourne 0, le test est r�ussi. Des prints devraient aussi �tre utilis�s pour pouvoir suivre l'ex�cution du test.

G�n�ralement, on voudrait un fichier test par classe majeure, contenant une fonction par test qui retourne 0 si le test est r�ussi et 1 s'il a �chou�. Le main devrait ex�cuter toutes les fonctions test et retourner leur valeur de retour si elle n'est pas 0.

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

Si vous voulez utiliser quelque chose d'autre que VS2017 sur Windows, cherchez une extension cmake pour votre �diteur.

#### Windows

Avec VS2017, aller dans Fichier>Ouvrir>CMake et choisir CMakeLists.txt
dans le r�pertoire de Thunderstruck.

Lorsque VS2017 ex�cute cmake (par lui-m�me), il ajoute tous les tests dans sa liste de tests. Pour les g�rer, aller dans Test>Fen�tres>Explorateur de tests.

#### Linux

Si vous avez un �diteur de texte, cherchez une extension cmake.

� partir de la ligne de commande, dans thunderstruck:

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Pour recompiler, sauf si CMakeLists.txt a chang�, vous avez seulement � r��x�cuter `make` dans le r�pertoire build.

Si CMakeLists.txt a chang�, il faut r��x�cuter `cmake ..` dans le r�pertoire build avant.