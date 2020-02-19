set(THUNDERSTRUCK_VERSION 0.0.1)
cmake_policy(SET CMP0048 NEW)
project(thunderstruck LANGUAGES CXX VERSION ${THUNDERSTRUCK_VERSION})
cmake_minimum_required(VERSION 3.12)
enable_testing()

# Set le standard C++ à 2017
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compile libWWIII comme librairie
file(GLOB WWIII_SOURCE_FILES "libWWIII/*.cpp" "libWWIII/*.h")
add_library(WWIII SHARED ${WWIII_SOURCE_FILES})

# Compile la demo comme exécutable lié à libWWIII
file(GLOB DEMO_SOURCE_FILES "demo/*.cpp" "demo/*.h")
add_executable(demo ${DEMO_SOURCE_FILES})
target_link_libraries(demo WWIII)
add_dependencies(demo WWIII)

# Trouve les headers et la librairie de WWIII
include_directories(libWWIII)
link_directories(libWWIII)

# Définit tous les fichiers .cc dans tests/ comme un test
file(GLOB WWIII_TESTS "tests/*.cc")
# Pour chaque nom de fichier .cc
foreach(test_source IN ITEMS ${WWIII_TESTS})
	# Prend son nom et met le dans test_name
	get_filename_component(test_name ${test_source} NAME_WE)
	# Compile le test
	add_executable(${test_name} ${test_source})
	# Lie le test à libWWIII
	target_link_libraries(${test_name} WWIII)
	# Compile libWWIII avant le test
	add_dependencies(${test_name} WWIII)
	# Ajoute le test à la liste de tests
	add_test(NAME ${test_name} COMMAND $<TARGET_FILE:${test_name}>)
endforeach(test_source)
