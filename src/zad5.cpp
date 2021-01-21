#include "zad5.hpp"

TEST_CASE("Test liczenia kolejnych warzyw", "[zad5]")
{
    std::vector< Warzywo > v = {
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
    };

    CHECK(liczKolejneWarzywa(v.cbegin(), v.cend(), v.size(), "abc"));

    std::deque< Warzywo > d = {
        {"abcd", 3.14, 1},
        {"abcd", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abc", 3.14, 1},
        {"abcd", 3.14, 1},
        {"abc", 3.14, 1},
        {"abcd", 3.14, 1},
        {"abc", 3.14, 1},
    };

    CHECK(liczKolejneWarzywa(d.cbegin(), d.cend(), 3, "abc"));
    CHECK(liczKolejneWarzywa(d.cbegin(), d.cend(), 2, "abcd"));
    CHECK_FALSE(liczKolejneWarzywa(d.cbegin(), d.cend(), 3, "abcd"));
}
