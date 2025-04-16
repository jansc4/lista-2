/*
* @author Jan Nowak
 */
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "RNASequence.h"

TEST_CASE("RNASequence: Konstruktor i toString") {
    RNASequence rna("rna1", "AUCG");
    REQUIRE(rna.toString() == ">rna1\nAUCG\n");
    REQUIRE(rna.getLength() == 4);
}

TEST_CASE("RNASequence: Mutacja") {
    RNASequence rna("rna2", "AUCG");
    rna.mutate(1, 'A');
    REQUIRE(rna.toString() == ">rna2\nAACG\n");
}

TEST_CASE("RNASequence: Znalezienie motywu") {
    RNASequence rna("rna3", "AUAUAU");
    auto result = rna.findMotif("AU");
    REQUIRE(result == std::vector<size_t>{0, 2, 4});
}

TEST_CASE("RNASequence: Komplement") {
    RNASequence rna("rna4", "AUCG");
    REQUIRE(rna.complement() == "UAGC");
}

TEST_CASE("RNASequence: Translacja do białka") {
    RNASequence rna("rna5", "AUGGCU");
    ProteinSequence prot = rna.transcribe();
    REQUIRE(prot.getData() == "MA"); // A to AUG, GCU to A
}