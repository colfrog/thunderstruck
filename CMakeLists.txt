# La version de Thunderstruck est définie ici
set(THUNDERSTRUCK_VERSION 0.1.0)

# Définir le projet comme nouveau pour utiliser la version 0.0.1
cmake_policy(SET CMP0048 NEW)
# Définir le projet lui-même comme un projet C++ et y rattacher sa version
project(thunderstruck LANGUAGES CXX VERSION ${THUNDERSTRUCK_VERSION})
# La version minimale de CMake requise est 3.12. C'est la version utilisée par VS2017.
cmake_minimum_required(VERSION 3.10)
# Activer le système de tests de CMake
enable_testing()
# Activer les symboles de déboguage
set(CMAKE_BUILD_TYPE Debug)

### Set le standard C++ à 2017 et enforce-le
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

### Compile libWWIII comme une librairie
file(GLOB_RECURSE WWIII_SOURCE_FILES "libWWIII/*.cpp" "libWWIII/*.h")
add_library(WWIII STATIC ${WWIII_SOURCE_FILES})
# Installe la liste des items dans le fichier de compilation
configure_file(libWWIII/listes_des_items.txt
	${CMAKE_CURRENT_BINARY_DIR}/listes_des_items.txt COPYONLY)

### Compile la demo comme exécutable lié à libWWIII
file(GLOB DEMO_SOURCE_FILES "demo/*.cpp" "demo/*.h")
add_executable(demo ${DEMO_SOURCE_FILES})
target_link_libraries(demo $<TARGET_FILE:WWIII>)
add_dependencies(demo WWIII)

### Compile l'interface Qt
# Utiliser les outils Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
# Trouver les extensions pour une application Qt Widgets
find_package(Qt5 COMPONENTS Widgets REQUIRED)
# Trouver tous les fichiers .cpp et .h dans qt_ui/
file(GLOB_RECURSE QT_UI_SOURCE_FILES "qt_ui/*.cpp" "qt_ui/*.h")
# Définition de l'exécutable à partir des fichiers sources
add_executable(qt_ui ${QT_UI_SOURCE_FILES})
# Lie l'interface Qt à libWWIII
target_link_libraries(qt_ui $<TARGET_FILE:WWIII>)
# Déclare que l'interface dépend de libWWIII
add_dependencies(qt_ui WWIII)
## Liste des librairies Qt utilisées pour l'interface
target_link_libraries(qt_ui Qt5::Widgets)

# Créer un target test sous lequel tous les tests s'effectueront
add_custom_target(tests DEPENDS WWIII)

### Trouve les headers et la librairie de WWIII
include_directories(libWWIII)
link_directories(libWWIII)

### Définit tous les fichiers .cc dans tests/ comme un test
file(GLOB WWIII_TESTS "tests/*.cc")
# Pour chaque nom de fichier .cc
foreach(test_source IN ITEMS ${WWIII_TESTS})
	# Prend son nom et met le dans test_name
	get_filename_component(test_name ${test_source} NAME_WE)
	# Compile le test
	add_executable(${test_name} ${test_source})
	# Lie le test à libWWIII
	target_link_libraries(${test_name} $<TARGET_FILE:WWIII>)
	# On dépend du target test
	add_dependencies(${test_name} tests)
	# Ajoute le test à la liste de tests
	add_test(NAME ${test_name} COMMAND $<TARGET_FILE:${test_name}>)
endforeach(test_source)
