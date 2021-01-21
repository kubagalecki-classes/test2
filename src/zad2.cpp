#include "zad2.hpp"

TEST_CASE("Test polimorfizmu", "[zad2]")
{
    Zielony z;
    Kiszony k;

    for (int i = 0; i < 5; ++i)
    {
        auto hash_chrupania = std::hash< std::string >{}(jedzOgorek(&z));
        CHECK(hash_chrupania == CucumberLogger::green[i]);
    }

    for (int i = 0; i < 5; ++i)
    {
        auto hash_chrupania = std::hash< std::string >{}(jedzOgorek(&k));
        CHECK(hash_chrupania == CucumberLogger::pickle[i]);
    }

    for (int i = 5; i < 10; ++i)
    {
        auto hash_chrupania = std::hash< std::string >{}(jedzOgorek(&z));
        CHECK(hash_chrupania == CucumberLogger::green[i]);
    }
}
