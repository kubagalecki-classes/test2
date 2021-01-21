#include "zad3.hpp"

struct Zupa1
{
    unsigned gotujZupe(const Warzywo& w) const
    {
        std::stringstream ss{};
        w.opis(ss);
        auto op = ss.str();
        return std::accumulate(op.cbegin(), op.cend(), 0);
    }
};

struct Zupa2
{
    unsigned gotujZupe(const Warzywo& w) const
    {
        std::stringstream ss{};
        w.opis(ss);
        auto op = ss.str();
        return std::accumulate(op.cbegin(), op.cend(), 0) + 10;
    }
};

TEST_CASE("Test szablonu")
{
    Warzywo           w1{"cukinia", 3.14, 42};
    std::stringstream s1t{};
    w1.opis(s1t);
    auto string1t  = s1t.str();
    auto expected1 = std::accumulate(string1t.cbegin(), string1t.cend(), 0);
    expected1 *= expected1;
    CHECK(expected1 == gotujZupe(w1, Zupa1{}));

    Warzywo           w2{"cukinia", 3.14, 42};
    std::stringstream s2t{};
    w2.opis(s2t);
    auto string2t  = s2t.str();
    auto expected2 = std::accumulate(string2t.cbegin(), string2t.cend(), 0) + 10;
    expected2 *= expected2;
    CHECK(expected2 == gotujZupe(w2, Zupa2{}));
}
