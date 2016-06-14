#ifndef GENETICS_H
#define GENETICS_H
#include "GeneticPopulation.h"
#include "GeneticIndividual.h"
#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>

std::vector<GeneticIndividual> generatePopulation(const std::string& geneticElements, const int& chromosomeLength, const int& populationSize);
std::string generateChromosome(const std::string& geneticElements, const int& chromosomeLength);

#endif
