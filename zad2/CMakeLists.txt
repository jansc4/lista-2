# Dodanie głównych plików źródłowych
add_executable(zad2 main.cpp DNASequence.cpp RNASequence.cpp ProteinSequence.cpp)

# Dodanie testów dla każdej klasy
add_executable(zad2_tests_DNA testDNA.cpp DNASequence.cpp)
add_executable(zad2_tests_RNA testRNA.cpp RNASequence.cpp)
add_executable(zad2_tests_Protein testProtein.cpp ProteinSequence.cpp)

# Linkowanie z Catch2
target_link_libraries(zad2_tests_DNA PRIVATE Catch2::Catch2WithMain)
target_link_libraries(zad2_tests_RNA PRIVATE Catch2::Catch2WithMain)
target_link_libraries(zad2_tests_Protein PRIVATE Catch2::Catch2WithMain)

# Rejestracja testów w CMake
add_test(NAME zad2_tests_DNA COMMAND zad2_tests_DNA)
add_test(NAME zad2_tests_RNA COMMAND zad2_tests_RNA)
add_test(NAME zad2_tests_Protein COMMAND zad2_tests_Protein)
