#include "zad4.hpp"

TEST_CASE("Test jedzenia warzyw", "[zad4]")
{
    std::vector< Warzywo > v{};
    CHECK_THROWS_AS(jedzOstatnieWarzywa(v, 10, std::cout), std::logic_error);

    v.emplace_back("cukinia", 3.14, 42);
    v.emplace_back("batat", 3.13, 43);
    v.emplace_back("ziemniak", 3.12, 44);
    std::stringstream ss1{};
    std::stringstream ss2{};
    v[1].opis(ss1);
    v[0].opis(ss1);
    jedzOstatnieWarzywa(v, 2, ss2);
    CHECK(ss1.str() == ss2.str());

    v.emplace_back("cebula", 3.11, 45);
    std::stringstream ss3{};
    std::stringstream ss4{};
    v[2].opis(ss3);
    v[1].opis(ss3);
    jedzOstatnieWarzywa(v, 2, ss4);
    CHECK(ss3.str() == ss4.str());
}
