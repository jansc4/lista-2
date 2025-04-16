//
// Created by jan on 07.04.2025.
//

#include <stdexcept>
#include "Wielomian.h"

Wielomian::Wielomian(const std::vector<float> &parameters) {

}

bool Wielomian::checkList(std::vector<float> &parameters) {
    if (parameters.empty()){
        throw invalid_argument("Vectors can not be empty");
    }
    return false;
}

int Wielomian::stopien() const {
    return 0;
}

std::string Wielomian::toString() const {
    return std::string();
}

float Wielomian::operator()(float x) const {
    return 0;
}

Wielomian Wielomian::operator+(const Wielomian &other) const {
    return Wielomian(std::vector());
}

Wielomian Wielomian::operator-(const Wielomian &other) const {
    return Wielomian(std::vector());
}

Wielomian Wielomian::operator*(const Wielomian &other) const {
    return Wielomian(std::vector());
}

Wielomian &Wielomian::operator+=(const Wielomian &other) {
    return <#initializer#>;
}

Wielomian &Wielomian::operator-=(const Wielomian &other) {
    return <#initializer#>;
}

Wielomian &Wielomian::operator*=(const Wielomian &other) {
    return <#initializer#>;
}

const std::vector<float> &Wielomian::getParam() const {
    return <#initializer#>;
}

void Wielomian::setParam(std::vector<float> &param) {

}



//TODO checkList

