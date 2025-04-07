//
// Created by jan on 07.04.2025.
//

#include "Wielomian.h"

using namespace std;

Wielomian::Wielomian(vector<float> &parameters) : parameters(parameters){}

void Wielomian::setParameters(const vector<float> &parameters) {
    this->parameters = parameters;
}

[[nodiscard]] const vector<float> &Wielomian::getParameters() const {
    return parameters;
}

void Wielomian::printWielomian() {

}

//TODO checkList