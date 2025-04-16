/*
* @author Jan Nowak
 */

#include "DNASequence.h"
#include "RNASequence.h"

// Konstruktor
DNASequence::DNASequence(const std::string& identifier, const std::string& data)
    : Sequence(identifier, data, {'A', 'T', 'C', 'G'}) {}

// Komplement DNA
std::string DNASequence::complement() const {
    std::string comp = data;
    for (char& ch : comp) {
        if (ch == 'A') ch = 'T';
        else if (ch == 'T') ch = 'A';
        else if (ch == 'C') ch = 'G';
        else if (ch == 'G') ch = 'C';
    }
    return comp;
}

// Transkrypcja do RNA
RNASequence DNASequence::transcribe() const {
    std::string rnaData = data;
    for (char& ch : rnaData) {
        if (ch == 'T') ch = 'U';  // Zmiana T na U
    }
    return RNASequence(identifier + "_RNA", rnaData);
}
