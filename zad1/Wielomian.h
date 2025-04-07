//
// Created by jan on 07.04.2025.
//

#include "vector"

#ifndef LISTA2_WIELOMIAN_H
#define LISTA2_WIELOMIAN_H

namespace std {

    class Wielomian {
        private:
            vector<float> parameters;
        public:
            Wielomian(vector<float> &parameters);

            void setParameters(const vector<float> &parameters);

            [[nodiscard]] const vector<float> &getParameters() const;

            void printWielomian();

    };

} // std

#endif //LISTA2_WIELOMIAN_H
