/*
* @author Jan Nowak
 * https://www.w3schools.com/cpp/cpp_inheritance.asp
* https://www.w3schools.com/cpp/cpp_inheritance_multilevel.asp
* https://www.w3schools.com/cpp/cpp_inheritance_access.asp
* https://www.w3schools.com/cpp/cpp_polymorphism.asp
* https://pl.wikipedia.org/wiki/Transkrypcja_(genetyka)
* https://pl.wikipedia.org/wiki/Translacja_(genetyka)
 */
#pragma once

#include "Sequence.h"

/**
 * @class ProteinSequence
 * @brief Klasa reprezentująca sekwencję aminokwasów (białko).
 *
 * Dziedziczy po klasie Sequence i implementuje wymaganą metodę complement(),
 * mimo że nie ma biologicznego odpowiednika komplementu dla sekwencji białkowych.
 */
class ProteinSequence : public Sequence {
public:
    /**
     * @brief Konstruktor klasy ProteinSequence.
     *
     * Inicjalizuje sekwencję białkową, weryfikując dozwolone znaki.
     *
     * @param identifier Identyfikator sekwencji.
     * @param data Ciąg aminokwasów reprezentowany jako łańcuch znaków.
     */
    ProteinSequence(const std::string& identifier, const std::string& data);

    /**
     * @brief Metoda komplementująca (wymagana przez klasę bazową).
     *
     * W biologii sekwencje białkowe nie mają komplementu.
     * Funkcja może zwrócić pusty string lub kopię samej sekwencji
     * jako placeholder.
     *
     * @return Pusty ciąg lub kopia sekwencji.
     */
    std::string complement() const override;
};
