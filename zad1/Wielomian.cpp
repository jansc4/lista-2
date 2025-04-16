/*
* @author Jan Nowak
 */
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Wielomian.h"

Wielomian::Wielomian(const std::vector<float>& parameters) {
    if (!checkList(parameters)) {
        throw std::invalid_argument("Vectors can not be empty and at least one parameters need to greater than 0");
    }
    this->parameters = parameters;
}

bool Wielomian::checkList(const std::vector<float>& parameters) {

    if (!parameters.empty()) {
        for (float val : parameters) {
            if (val != 0.0f) return true;
        }
    }
    return false;
}



int Wielomian::stopien() const {
    for (int i = parameters.size() - 1; i >= 0; --i) {
        if (parameters[i] != 0.0f) {
            return i;
        }
    }
    throw std::logic_error("Wielomian zerowy nie ma zdefiniowanego stopnia.");
}


std::string Wielomian::toString() const {
    std::ostringstream out;
    bool first = true;

    for (int i = parameters.size() - 1; i >= 0; --i) {
        float coef = parameters[i];

        if (coef == 0) continue;

        // Dodaj znak
        if (!first) {
            out << (coef > 0 ? " + " : " - ");
        } else if (coef < 0) {
            out << "-";
        }

        float absCoef = std::fabs(coef);
        if (absCoef != 1 || i == 0) {
            out << absCoef;
        }

        if (i > 0) {
            out << "x";
            if (i > 1) {
                out << "^" << i;
            }
        }

        first = false;
    }

    if (first) {
        return "0";  // Wszystkie współczynniki były zerowe
    }

    return out.str();
}

float Wielomian::operator()(float x) const {
    float result = 0;
    float xPower = 1;

    for (float coef : parameters) {
        result += coef * xPower;
        xPower *= x;
    }

    return result;
}


Wielomian Wielomian::operator+(const Wielomian& other) const {
    const auto& a = this->parameters;
    const auto& b = other.parameters;

    size_t maxSize = std::max(a.size(), b.size());
    std::vector<float> result(maxSize, 0.0f);

    for (size_t i = 0; i < a.size(); ++i) {
        result[i] += a[i];
    }

    for (size_t i = 0; i < b.size(); ++i) {
        result[i] += b[i];
    }

    return Wielomian(result);
}

Wielomian Wielomian::operator-(const Wielomian& other) const {
    const auto& a = this->parameters;
    const auto& b = other.parameters;

    size_t maxSize = std::max(a.size(), b.size());
    std::vector<float> result(maxSize, 0.0f);

    for (size_t i = 0; i < a.size(); ++i) {
        result[i] += a[i];
    }

    for (size_t i = 0; i < b.size(); ++i) {
        result[i] -= b[i];
    }

    return Wielomian(result);
}

Wielomian Wielomian::operator*(const Wielomian& other) const {
    const auto& a = this->parameters;
    const auto& b = other.parameters;
    std::vector<float> result(a.size() + b.size() - 1, 0.0f);

    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b.size(); ++j) {
            result[i + j] += a[i] * b[j];
        }
    }

    return Wielomian(result);
}

Wielomian& Wielomian::operator+=(const Wielomian& other) {
    *this = *this + other;
    return *this;
}

Wielomian& Wielomian::operator-=(const Wielomian& other) {
    *this = *this - other;
    return *this;
}

Wielomian& Wielomian::operator*=(const Wielomian& other) {
    *this = *this * other;
    return *this;
}

const std::vector<float> &Wielomian::getParam() const {
    return parameters;
}

void Wielomian::setParam(std::vector<float> &param) {
    this->parameters = param;
}





