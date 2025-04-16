/*
* @author Jan Nowak
 */

#include "RNASequence.h"
#include <map>
#include <string>

RNASequence::RNASequence(const std::string& identifier, const std::string& data)
    : Sequence(identifier, data, {'A', 'U', 'C', 'G'}) {}

std::string RNASequence::complement() const {
    std::string comp = data;
    for (char& ch : comp) {
        if (ch == 'A') ch = 'U';
        else if (ch == 'U') ch = 'A';
        else if (ch == 'C') ch = 'G';
        else if (ch == 'G') ch = 'C';
    }
    return comp;
}

ProteinSequence RNASequence::transcribe() const {
    static const std::map<std::string, char> codonTable = {
        {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
        {"UGU", 'C'}, {"UGC", 'C'},
        {"GAU", 'D'}, {"GAC", 'D'},
        {"GAA", 'E'}, {"GAG", 'E'},
        {"UUU", 'F'}, {"UUC", 'F'},
        {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'},
        {"CAU", 'H'}, {"CAC", 'H'},
        {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'},
        {"AAA", 'K'}, {"AAG", 'K'},
        {"UUA", 'L'}, {"UUG", 'L'}, {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
        {"AUG", 'M'},
        {"AAU", 'N'}, {"AAC", 'N'},
        {"UAG", 'O'},
        {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
        {"CAA", 'Q'}, {"CAG", 'Q'},
        {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'}, {"AGA", 'R'}, {"AGG", 'R'},
        {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'}, {"AGU", 'S'}, {"AGC", 'S'},
        {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
        {"UGA", 'U'},
        {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
        {"UGG", 'W'},
        {"UAU", 'Y'}, {"UAC", 'Y'},
        {"UGA", '*'}, {"UAA", '*'}, {"UAG", '*'}
    };

    std::string proteinData;
    for (size_t i = 0; i + 2 < data.size(); i += 3) {
        std::string codon = data.substr(i, 3);
        auto it = codonTable.find(codon);
        if (it != codonTable.end()) {
            if (it->second == '*') break;  // Stop codon
            proteinData += it->second;
        } else {
            proteinData += 'X';  // Nieznany kodon
        }
    }

    return ProteinSequence(identifier + "_PROT", proteinData);
}

