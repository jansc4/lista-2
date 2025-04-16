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
#include "ProteinSequence.h"

/**
 * @class RNASequence
 * @brief Klasa reprezentująca sekwencję RNA.
 *
 * Klasa dziedziczy po klasie Sequence i dodaje metody specyficzne dla sekwencji RNA,
 * takie jak komplementacja oraz transkrypcja do białka.
 */
class RNASequence : public Sequence {
public:
    /**
     * @brief Konstruktor klasy RNASequence.
     *
     * Inicjalizuje obiekt RNASequence z identyfikatorem i sekwencją zasad RNA.
     * Przekazuje dane do klasy bazowej Sequence, z dozwolonymi znakami A, U, C, G.
     *
     * @param identifier Identyfikator sekwencji RNA.
     * @param data Ciąg zasad RNA.
     */
    RNASequence(const std::string& identifier, const std::string& data);

    /**
     * @brief Metoda komplementująca sekwencję RNA.
     *
     * Zwraca komplementarną sekwencję RNA, gdzie:
     * A ↔ U, U ↔ A, C ↔ G, G ↔ C.
     *
     * @return Komplementarna sekwencja RNA.
     */
    std::string complement() const override;

    /**
     * @brief Metoda translacji RNA do białka.
     *
     * Zwraca obiekt klasy ProteinSequence, reprezentujący translację sekwencji RNA
     * do sekwencji aminokwasów.
     *
     * @return Obiekt klasy ProteinSequence reprezentujący translację RNA do białka.
     */
    ProteinSequence transcribe() const;
};
