/*
* @author Jan Nowak
 */
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "DNASequence.h"

TEST_CASE("DNASequence: Konstruktor i toString") {
    DNASequence dna("seq1", "ATCG");
    REQUIRE(dna.toString() == ">seq1\nATCG\n");
    REQUIRE(dna.getLength() == 4);
}

TEST_CASE("DNASequence: Mutacja") {
    DNASequence dna("seq2", "ATCG");
    dna.mutate(2, 'T');
    REQUIRE(dna.toString() == ">seq2\nATTG\n");
}

TEST_CASE("DNASequence: Znalezienie motywu") {
    DNASequence dna("seq3", "ATATAT");
    auto result = dna.findMotif("AT");
    REQUIRE(result == std::vector<size_t>{0, 2, 4});
}

TEST_CASE("DNASequence: Komplement") {
    DNASequence dna("seq4", "ATCG");
    REQUIRE(dna.complement() == "TAGC");
}

TEST_CASE("DNASequence: Transkrypcja do RNA") {
    DNASequence dna("seq5", "ATCG");
    RNASequence rna = dna.transcribe();
    REQUIRE(rna.toString() == ">seq5_RNA\nAUCG\n");
}