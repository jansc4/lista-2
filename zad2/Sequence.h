/*
* @author Jan Nowak
 * https://www.w3schools.com/cpp/cpp_inheritance.asp
* https://www.w3schools.com/cpp/cpp_inheritance_multilevel.asp
* https://www.w3schools.com/cpp/cpp_inheritance_access.asp
* https://www.w3schools.com/cpp/cpp_polymorphism.asp
* https://pl.wikipedia.org/wiki/Transkrypcja_(genetyka)
* https://pl.wikipedia.org/wiki/Translacja_(genetyka)
 */
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

#pragma once

/**
 * @class Sequence
 * @brief Klasa bazowa reprezentująca sekwencję genetyczną lub białkową.
 *
 * Klasa ta przechowuje informacje o identyfikatorze sekwencji, danych (ciągu zasad lub aminokwasów),
 * dozwolonych znakach oraz długości sekwencji. Zawiera również metody do modyfikacji sekwencji
 * oraz jej reprezentacji w formacie FASTA.
 */
class Sequence {
protected:
    std::string identifier;  ///< Identyfikator sekwencji
    std::string data;        ///< Sekwencja zasad lub aminokwasów
    const std::set<char> VALID_CHARS;  ///< Zbiór dozwolonych znaków
    size_t length;           ///< Długość sekwencji

public:
    /**
     * @brief Konstruktor klasy Sequence.
     *
     * Inicjalizuje sekwencję z identyfikatorem, danymi i zestawem dozwolonych znaków.
     * Sprawdza, czy wszystkie znaki w sekwencji są dozwolone.
     *
     * @param identifier Identfikator sekwencji.
     * @param data Ciąg danych (zasady lub aminokwasy).
     * @param validChars Zbiór dozwolonych znaków.
     * @throws std::invalid_argument Jeśli w sekwencji pojawią się niedozwolone znaki.
     */
    Sequence(const std::string& identifier, const std::string& data, const std::set<char>& validChars);

    /**
     * @brief Getter dla długości sekwencji.
     *
     * @return Długość sekwencji.
     */
    size_t getLength() const;

    /**
     * @brief Reprezentacja obiektu w formacie FASTA.
     *
     * Tworzy reprezentację tekstową sekwencji w formacie FASTA, który jest standardowym
     * sposobem przechowywania danych o sekwencjach.
     *
     * @return Reprezentacja sekwencji w formacie FASTA.
     */
    virtual std::string toString() const;

    /**
     * @brief Mutacja sekwencji.
     *
     * Zmienia zasady (lub aminokwas) w określonej pozycji w sekwencji na podaną wartość.
     *
     * @param position Pozycja w sekwencji, którą chcemy zmienić.
     * @param value Nowa zasada lub aminokwas.
     * @throws std::invalid_argument Jeśli podana zasada jest niedozwolona.
     * @throws std::out_of_range Jeśli podana pozycja jest poza zakresem sekwencji.
     */
    void mutate(size_t position, char value);

    /**
     * @brief Znalezienie motywu w sekwencji.
     *
     * Wyszukuje wszystkie wystąpienia zadanego motywu w sekwencji.
     *
     * @param motif Motyw do znalezienia w sekwencji.
     * @return Wektor zawierający pozycje, w których motyw występuje w sekwencji.
     */
    std::vector<size_t> findMotif(const std::string& motif) const;

    /**
     * @brief Metoda czysto wirtualna do obliczenia komplementu sekwencji.
     *
     * Ta metoda jest implementowana przez klasy pochodne (np. DNASequence, RNASequence).
     *
     * @return Komplementarna sekwencja.
     */
    virtual std::string complement() const = 0;
};



