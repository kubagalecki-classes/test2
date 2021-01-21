#include <algorithm>
#include <cstdint>
#include <functional>
#include <random>
#include <string>
#include <vector>

std::string getRandomString(size_t n)
{
    static std::mt19937                          prng{std::random_device{}()};
    static std::uniform_int_distribution< char > dist{};
    std::string                                  s;
    s.reserve(n);
    std::generate_n(std::back_inserter(s), n, [&] { return dist(prng); });
    return s;
}

struct CucumberLogger
{
    static std::vector< size_t > green, pickle;
    static std::string           getGreen()
    {
        auto s = getRandomString(20);
        green.push_back(std::hash< std::string >{}("Zielony: " + s));
        return s;
    }
    static std::string getPickle()
    {
        auto s = getRandomString(20);
        pickle.push_back(std::hash< std::string >{}("Kiszony: " + s));
        return s;
    }
};

std::string chrupZielony()
{
    return CucumberLogger::getGreen();
}
std::string chrupKiszony()
{
    return CucumberLogger::getPickle();
}

std::vector< size_t > CucumberLogger::green{};
std::vector< size_t > CucumberLogger::pickle{};
