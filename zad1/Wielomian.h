/*
* @author Jan Nowak
 * https://www.w3schools.com/cpp/cpp_constructors.asp
 */
#pragma once

#include "string"
#include "vector"

#ifndef LISTA2_WIELOMIAN_H
#define LISTA2_WIELOMIAN_H


/**
 * @class Wielomian
 * @brief Klasa reprezentująca wielomian o dowolnym stopniu.
 *
 * Klasa ta umożliwia operacje na wielomianach, takie jak obliczanie wartości dla
 * zadanego punktu, obliczanie stopnia wielomianu, dodawanie, odejmowanie, mnożenie
 * wielomianów, oraz operacje złożone (np. +=, -=, *=).
 */
class Wielomian {
    private:
        std::vector<float> parameters; ///< Współczynniki wielomianu.

    public:
        /**
         * @brief Konstruktor klasy.
         *
         * Konstruktor tworzy wielomian na podstawie wektora współczynników.
         *
         * @param parameters Wektor współczynników wielomianu.
         */
        explicit Wielomian(const std::vector<float>& parameters);

        /**
         * @brief Oblicza stopień wielomianu.
         *
         * Funkcja zwraca stopień wielomianu, który jest równy indeksowi
         * najwyższego współczynnika. Zwraca 0, jeśli wielomian jest stały.
         *
         * @return Stopień wielomianu.
         */
        [[nodiscard]] int stopien() const;

        /**
         * @brief Zwraca tekstową reprezentację wielomianu.
         *
         * Funkcja generuje reprezentację wielomianu w postaci
         * "a_n * x^n + a_(n-1) * x^(n-1) + ... + a_1 * x + a_0".
         *
         * @return Tekstowa reprezentacja wielomianu.
         */
        [[nodiscard]] std::string toString() const;

        /**
         * @brief Oblicza wartość wielomianu dla zadanego x.
         *
         * Funkcja oblicza wartość wielomianu w punkcie x.
         *
         * @param x Punkt, dla którego obliczana jest wartość wielomianu.
         * @return Wartość wielomianu w punkcie x.
         */
        float operator()(float x) const;

        /**
         * @brief Sprawdza poprawność listy współczynników.
         *
         * Funkcja sprawdza, czy lista współczynników jest poprawna
         * (np. nie pusta).
         *
         * @param parameters Wektor współczynników do sprawdzenia.
         * @return Czy lista współczynników jest poprawna.
         */
        static bool checkList(const std::vector<float>& parameters);

        // Operatory matematyczne

        /**
         * @brief Dodaje dwa wielomiany.
         *
         * Funkcja zwraca nowy wielomian będący sumą dwóch wielomianów.
         *
         * @param other Drugi wielomian do dodania.
         * @return Nowy wielomian będący sumą obu.
         */
        Wielomian operator+(const Wielomian& other) const;

        /**
         * @brief Odejmuje dwa wielomiany.
         *
         * Funkcja zwraca nowy wielomian będący różnicą dwóch wielomianów.
         *
         * @param other Drugi wielomian do odjęcia.
         * @return Nowy wielomian będący różnicą obu.
         */
        Wielomian operator-(const Wielomian& other) const;

        /**
         * @brief Mnoży dwa wielomiany.
         *
         * Funkcja zwraca nowy wielomian będący wynikiem mnożenia dwóch
         * wielomianów.
         *
         * @param other Drugi wielomian do pomnożenia.
         * @return Nowy wielomian będący wynikiem mnożenia obu.
         */
        Wielomian operator*(const Wielomian& other) const;

        // Operatory złożone

        /**
         * @brief Operator złożony dodawania.
         *
         * Dodaje drugi wielomian do bieżącego wielomianu.
         *
         * @param other Drugi wielomian do dodania.
         * @return Bieżący wielomian po dodaniu.
         */
        Wielomian& operator+=(const Wielomian& other);

        /**
         * @brief Operator złożony odejmowania.
         *
         * Odejmuje drugi wielomian od bieżącego.
         *
         * @param other Drugi wielomian do odjęcia.
         * @return Bieżący wielomian po odjęciu.
         */
        Wielomian& operator-=(const Wielomian& other);

        /**
         * @brief Operator złożony mnożenia.
         *
         * Mnoży bieżący wielomian przez drugi.
         *
         * @param other Drugi wielomian do pomnożenia.
         * @return Bieżący wielomian po mnożeniu.
         */
        Wielomian& operator*=(const Wielomian& other);

        // Gettery i Settery

        /**
         * @brief Zwraca współczynniki wielomianu.
         *
         * Funkcja zwraca referencję do wektora współczynników.
         *
         * @return Wektor współczynników wielomianu.
         */
        [[nodiscard]] const std::vector<float>& getParam() const;

        /**
         * @brief Ustawia nowe współczynniki dla wielomianu.
         *
         * Funkcja ustawia nowe wartości współczynników dla wielomianu.
         *
         * @param param Nowe współczynniki do ustawienia.
         */
        void setParam(std::vector<float>& param);
};

#endif //LISTA2_WIELOMIAN_H
