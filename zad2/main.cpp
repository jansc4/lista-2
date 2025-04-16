/*
* @author Jan Nowak
 */

#include "DNASequence.h"
#include "RNASequence.h"
#include "ProteinSequence.h"
#include <iostream>

int main() {
    try {
        // Tworzenie sekwencji DNA
        DNASequence dna("seq1", "ATGCAT");
        std::cout << "DNA (FASTA):\n" << dna.toString();

        // Mutacja
        dna.mutate(2, 'T');
        std::cout << "Po mutacji:\n" << dna.toString();

        // Komplement
        std::string comp = dna.complement();
        std::cout << "Komplementarna: " << comp << std::endl;

        // Szukanie motywu
        auto positions = dna.findMotif("AT");
        std::cout << "Motyw 'AT' znaleziony na pozycjach: ";
        for (auto p : positions) std::cout << p << " ";
        std::cout << "\n";

        // Transkrypcja do RNA
        RNASequence rna = dna.transcribe();
        std::cout << "RNA (FASTA):\n" << rna.toString();

        // Mutacja RNA
        rna.mutate(1, 'C');
        std::cout << "RNA po mutacji:\n" << rna.toString();

        // Komplement RNA
        std::cout << "Komplement RNA: " << rna.complement() << "\n";

        // Translacja do białka
        ProteinSequence protein = rna.transcribe();
        std::cout << "Białko (FASTA):\n" << protein.toString();

        // Mutacja białka
        protein.mutate(0, 'M');
        std::cout << "Białko po mutacji:\n" << protein.toString();

    } catch (std::exception& e) {
        std::cerr << "Błąd: " << e.what() << "\n";
    }

    return 0;
}
