#pragma once

#include <random>

class Random
{
public:
    template<typename T>
    static T get(int min, int max)
    {
        static std::random_device m_device{};

        std::mt19937 generator(m_device());
        std::uniform_int_distribution<std::mt19937::result_type> distributor(min, max);

        return distributor(generator);
    }
};