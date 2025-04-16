/*
* @author Jan Nowak
 */

#include "Sequence.h"
#include <stdexcept>
#include <algorithm>

// Konstruktor
Sequence::Sequence(const std::string& identifier, const std::string& data, const std::set<char>& validChars)
    : identifier(identifier), data(data), VALID_CHARS(validChars), length(data.size()) {
    for (char ch : data) {
        if (VALID_CHARS.find(ch) == VALID_CHARS.end()) {
            throw std::invalid_argument("Invalid character in sequence");
        }
    }
}

// Getter dla długości sekwencji
size_t Sequence::getLength() const {
    return length;
}

// Reprezentacja w formacie FASTA
std::string Sequence::toString() const {
    return ">" + identifier + "\n" + data + "\n";
}

// Mutacja – zmiana zasady w danym miejscu
void Sequence::mutate(size_t position, char value) {
    if (VALID_CHARS.find(value) == VALID_CHARS.end()) {
        throw std::invalid_argument("Invalid character for mutation");
    }
    if (position >= length) {
        throw std::out_of_range("Position out of range");
    }
    data[position] = value;
}

// Znalezienie motywu w sekwencji
std::vector<size_t> Sequence::findMotif(const std::string& motif) const {
    std::vector<size_t> positions;
    size_t pos = data.find(motif);
    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = data.find(motif, pos + 1);
    }
    return positions;
}


