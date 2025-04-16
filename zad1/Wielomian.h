//
// Created by jan on 07.04.2025.
//

#include "vector"
#include "string"

#ifndef LISTA2_WIELOMIAN_H
#define LISTA2_WIELOMIAN_H



class Wielomian {
    private:
        std::vector<float> parameters;
    public:
        //Konstruktor
        explicit Wielomian(const std::vector<float>& parameters);

        // Metody
        [[nodiscard]] int stopien() const;
        [[nodiscard]] std::string toString() const;
        float operator()(float x) const;
        static bool checkList(std::vector<float>& parameters);

        // Operatory matematyczne
        Wielomian operator+(const Wielomian& other) const;
        Wielomian operator-(const Wielomian& other) const;
        Wielomian operator*(const Wielomian& other) const;

        // Operatory złożone
        Wielomian& operator+=(const Wielomian& other);
        Wielomian& operator-=(const Wielomian& other);
        Wielomian& operator*=(const Wielomian& other);

        // Gettery
        [[nodiscard]] const std::vector<float>& getParam() const;
        void setParam(std::vector<float>& param);


};
#endif //LISTA2_WIELOMIAN_H
