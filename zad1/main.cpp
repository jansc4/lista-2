/*
* @author Jan Nowak
 */
#include <iostream>
#include "Wielomian.h"

int main() {
    // Tworzymy przykładowe wielomiany
    Wielomian w1({1, 2});  // 1 + 2x
    Wielomian w2({3, 4});  // 3 + 4x

    // Testujemy operator dodawania
    Wielomian w3 = w1 + w2;
    std::cout << "Wielomian po dodaniu: " << w3.toString() << std::endl;

    // Testujemy operator odejmowania
    Wielomian w4 = w1 - w2;
    std::cout << "Wielomian po odjęciu: " << w4.toString() << std::endl;

    // Testujemy operator mnożenia
    Wielomian w5 = w1 * w2;
    std::cout << "Wielomian po mnożeniu: " << w5.toString() << std::endl;

    // Testujemy operator złożony +=
    w1 += w2;
    std::cout << "Wielomian po dodaniu (+=): " << w1.toString() << std::endl;

    // Testujemy operator złożony -=
    w1 -= w2;
    std::cout << "Wielomian po odjęciu (-=): " << w1.toString() << std::endl;

    // Testujemy operator złożony *=
    w1 *= w2;
    std::cout << "Wielomian po mnożeniu (*=): " << w1.toString() << std::endl;

    // Testujemy funkcję do obliczenia wartości wielomianu dla x
    float x = 2.0;
    std::cout << "Wartość wielomianu w punkcie x = " << x << ": " << w1(x) << std::endl;

    return 0;
}
