/*
* @author Jan Nowak
 */
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "ProteinSequence.h"

TEST_CASE("ProteinSequence: Konstruktor i toString") {
    ProteinSequence prot("prot1", "MAK");
    REQUIRE(prot.toString() == ">prot1\nMAK\n");
    REQUIRE(prot.getLength() == 3);
}

TEST_CASE("ProteinSequence: Mutacja") {
    ProteinSequence prot("prot2", "MAK");
    prot.mutate(1, 'L');
    REQUIRE(prot.toString() == ">prot2\nMLK\n");
}

TEST_CASE("ProteinSequence: Znalezienie motywu") {
    ProteinSequence prot("prot3", "MAKMAK");
    auto result = prot.findMotif("AK");
    REQUIRE(result == std::vector<size_t>{1, 4});
}
