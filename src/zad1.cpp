#include "zad1.hpp"

TEST_CASE("Test klasy Warzywo", "[zad1]")
{
    CHECK(Warzywo::getVeg() == 0);
    {
        const Warzywo     w1{"cukinia", 2.1, 42};
        std::stringstream s1;
        w1.opis(s1);
        CHECK(s1.str() == "cukinia: 2.1, 42\n");
        CHECK(Warzywo::getVeg() == 1);
    }
    CHECK(Warzywo::getVeg() == 0);
}
