/*
* @author Jan Nowak
 */

#include "ProteinSequence.h"

// Konstruktor
ProteinSequence::ProteinSequence(const std::string& identifier, const std::string& data)
    : Sequence(identifier, data, {
        'A','C','D','E','F','G','H','I','K','L',
        'M','N','P','Q','R','S','T','V','W','Y'
    }) {}

// "Komplement" – nie ma biologicznie sensu dla białka, więc np. zwracamy oryginał lub pusty
std::string ProteinSequence::complement() const {
    return data;  // lub throw std::logic_error("Complement not defined for protein sequences");
}
