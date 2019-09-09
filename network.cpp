#include "network.h"

void Network::feedForward(const std::vector<double> &inputsValues)
{
    for(unsigned i = 0; i != inputsValues.size(); ++i)
    {
        layers[0][i].setOutput(inputsValues[i]);
    }
    for(unsigned layerNum = 1; layerNum != layers.size(); ++layerNum)
    {
        for(unsigned n = 0; n != layers[layerNum].size() - 1; ++n)
        {
            layers[layerNum][n].feedForward(layers[layerNum - 1]);
        }
    }
}

void Network::getResult(std::vector<double> &results)
{
    results.clear();

    for(auto l = layers.back().begin(); l != layers.back().end() - 1; ++l)
    {
        results.push_back(l -> getOutput());
    }
}

void Network::backProp(const std::vector<double> &targets)
{
    Layer &outputLayer = layers.back();
    error = 0.0;

    for(unsigned n = 0; n != outputLayer.size() - 1; ++n)
    {
        double delta = targets[n] - outputLayer[n].getOutput();
        error += delta * delta;
    }
    error /= outputLayer.size() - 1;
    error = pow(error, 1/2);

    for(unsigned n = 0; n != outputLayer.size() - 1; ++n)
    {
        outputLayer[n].calculateOutputGradients(targets[n]);
    }

    for(auto layerNum = layers.size() - 2; layerNum != 0; --layerNum)
    {
        for(unsigned n = 0; n != layers[layerNum].size(); ++n)
        {
            layers[layerNum][n].calculateHiddenGradients(layers[layerNum + 1]);
        }
    }

    for(auto layerNum = layers.size() - 1; layerNum != 0; --layerNum)
    {
        for(unsigned n = 0; n != layers[layerNum].size() - 1; ++n)
        {
            layers[layerNum][n].updateWeights(layers[layerNum - 1]);
        }
    }
}

Network::Network(const std::vector<unsigned> &layout)
{
    error = 0;

    for(unsigned l = 0; l != layout.size(); ++l)
    {
        layers.push_back(Layer());
        unsigned output = l == layout.size() - 1 ? 0 : layout[l + 1];

        for(unsigned n = 0; n <= layout[l]; ++n)
        {
            layers.back().push_back(Neuron(output, n));
        }
        layers.back().back().setOutput(1);
    }
}
