#include "pch.h"
#include "RandomGenerator.h"

#include <random>
#include <chrono>

int RandomGenerator::GetInteger(int begin, int end)
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(begin, end);
	return distribution(generator);
}

double RandomGenerator::GetDouble(double begin, double end)
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(begin, end);
	return distribution(generator);
}