/*
* @author Jan Nowak
 */


#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include <catch2/internal/catch_preprocessor_internal_stringify.hpp>

#include "Wielomian.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/internal/catch_assertion_handler.hpp"
#include "catch2/internal/catch_compiler_capabilities.hpp"
#include "catch2/internal/catch_decomposer.hpp"
#include "catch2/internal/catch_result_type.hpp"
#include "catch2/internal/catch_test_macro_impl.hpp"
#include "catch2/internal/catch_test_registry.hpp"

TEST_CASE("Operator dodawania dla wielomianów", "[operator+]")
 {
    Wielomian w1({1, 2});   // 1 + 2x
    Wielomian w2({3, 4});   // 3 + 4x
    Wielomian expected({4, 6});  // 4 + 6x

    Wielomian result = w1 + w2;
    REQUIRE(result.getParam() == expected.getParam());
}

TEST_CASE("Operator odejmowania dla wielomianów", "[operator-]") {
    Wielomian w1({5, 6, 1});   // 5 + 6x + x²
    Wielomian w2({2, 3});      // 2 + 3x
    Wielomian expected({3, 3, 1});  // 3 + 3x + x²

    Wielomian result = w1 - w2;
    REQUIRE(result.getParam() == expected.getParam());
}

TEST_CASE("Operator mnożenia dla wielomianów", "[operator*]") {
    Wielomian w1({1, 2});   // 1 + 2x
    Wielomian w2({3, 4});   // 3 + 4x
    Wielomian expected({3, 10, 8});  // 3 + 10x + 8x²

    Wielomian result = w1 * w2;
    REQUIRE(result.getParam() == expected.getParam());
}

TEST_CASE("Operator += dla wielomianów", "[operator+=]") {
    Wielomian w1({1, 2});   // 1 + 2x
    Wielomian w2({3, 4});   // 3 + 4x
    Wielomian expected({4, 6});  // 4 + 6x

    w1 += w2;
    REQUIRE(w1.getParam() == expected.getParam());
}

TEST_CASE("Operator -= dla wielomianów", "[operator-=]") {
    Wielomian w1({5, 6, 1});   // 5 + 6x + x²
    Wielomian w2({2, 3});      // 2 + 3x
    Wielomian expected({3, 3, 1});  // 3 + 3x + x²

    w1 -= w2;
    REQUIRE(w1.getParam() == expected.getParam());
}

TEST_CASE("Operator *= dla wielomianów", "[operator*=]") {
    Wielomian w1({1, 2});   // 1 + 2x
    Wielomian w2({3, 4});   // 3 + 4x
    Wielomian expected({3, 10, 8});  // 3 + 10x + 8x²

    w1 *= w2;
    REQUIRE(w1.getParam() == expected.getParam());
}
