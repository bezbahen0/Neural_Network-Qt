#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"
#include <vector>

class Network
{
private:
    std::vector<Layer> layers;
    double error;
public:
    Network(const std::vector<unsigned> &layout);
    void feedForward(const std::vector<double> &inputsValues);
    void backProp(const std::vector<double> &targets);
    void getResult(std::vector<double> &results);
    std::vector<Layer> getLayer(){return layers; }

};

#endif // NETWORK_H
