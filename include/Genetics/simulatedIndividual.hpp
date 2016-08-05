#ifndef SIMULATED_INDIVIDUAL_H
#define SIMULATED_INDIVIDUAL_H
#include "Genetics/geneticIndividual.hpp"
#include "Game2D/dynamicGameObject.hpp"

class SimulatedIndividual : public DynamicGameObject, public GeneticIndividual {
    public:
        SimulatedIndividual(const std::string& chromosome, const sf::Texture& texture, int type, const sf::Vector2f& position = sf::Vector2f(0, 0));
    private:
        int speed;
};

#endif
