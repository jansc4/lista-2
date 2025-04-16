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
#include "RNASequence.h"

/**
 * @class DNASequence
 * @brief Klasa reprezentująca sekwencję DNA.
 *
 * Klasa dziedziczy po klasie Sequence i dodaje metody specyficzne dla sekwencji DNA,
 * takie jak komplementacja oraz transkrypcja do RNA.
 */
class DNASequence : public Sequence {
public:
    /**
     * @brief Konstruktor klasy DNASequence.
     *
     * Inicjalizuje obiekt DNASequence z identyfikatorem i sekwencją zasad DNA.
     * Przekazuje dane do klasy bazowej Sequence, z dozwolonymi znakami A, T, C, G.
     *
     * @param identifier Identyfikator sekwencji DNA.
     * @param data Ciąg zasad DNA.
     */
    DNASequence(const std::string& identifier, const std::string& data);

    /**
     * @brief Metoda komplementująca sekwencję DNA.
     *
     * Zwraca komplementarną sekwencję DNA, gdzie:
     * A ↔ T, T ↔ A, C ↔ G, G ↔ C.
     *
     * @return Komplementarna sekwencja DNA.
     */
    std::string complement() const override;

    /**
     * @brief Metoda transkrypcji DNA do RNA.
     *
     * Zwraca obiekt klasy RNASequence, reprezentujący transkrypcję sekwencji DNA.
     * W procesie transkrypcji zasada T w DNA jest zamieniana na U w RNA.
     *
     * @return Obiekt klasy RNASequence reprezentujący transkrypcję DNA.
     */
    RNASequence transcribe() const;
};





