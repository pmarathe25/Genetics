#ifndef SIMULATED_POPULATION_H
#define SIMULATED_POPULATION_H
#include "Genetics/simulatedIndividual.hpp"
#include "Genetics/geneticPopulation.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

class SimulatedPopulation : public GeneticPopulation {
    public:
        // Constructors.
        SimulatedPopulation(const std::string& geneticElements, const std::vector<std::string>& initialPopulationChromosomes, double mutationRate = 0);
        SimulatedPopulation(const std::string& geneticElements, int populationSize, int chromosomeLength, double mutationRate = 0);
        // Methods.
        virtual bool update(const sf::Time& frametime);
        void reproduce(const SimulatedIndividual& parentA, const SimulatedIndividual& parentB);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
        // Data members.
        std::vector<std::unique_ptr<SimulatedIndividual> > individuals;
};

#endif
