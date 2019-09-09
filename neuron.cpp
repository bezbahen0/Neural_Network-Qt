#include "neuron.h"

void Neuron::updateWeights(Layer& prevLayer)
{
    for(auto i = prevLayer.begin(); i != prevLayer.end(); ++i)
    {
        double oldDeltaWeight = i -> outWeights[index].delta_weight;
        double newDeltaWeight = learningRate * i -> getOutput() * gradient + alpha * oldDeltaWeight;

        i -> outWeights[index].delta_weight = newDeltaWeight;
        i -> outWeights[index].weight += newDeltaWeight;
    }
}

double Neuron::accumulate(const Layer& nextLayer)
{
    double sum = 0.0;
    for(unsigned i = 0; i < nextLayer.size(); ++i)
    {
        sum += outWeights[i].weight * nextLayer[i].gradient;
    }
    return sum;
}

void Neuron::calculateHiddenGradients(const Layer& nextLayer)
{
    double dow = accumulate(nextLayer);
    gradient = dow * Neuron::derivative_activation_f(output);
}

void Neuron::calculateOutputGradients(double target)
{
    double delta = target - output;
    gradient = delta * Neuron::derivative_activation_f(output);
}

void Neuron::feedForward(const Layer& prevLayer)
{
    double sum = 0.0;
    for(auto i = prevLayer.begin(); i != prevLayer.end(); ++i)
    {
        sum += i -> getOutput() * i -> outWeights[index].weight;
    }
    output = Neuron::activation_f(sum);

}

Neuron::Neuron(unsigned output, unsigned index)
{
    this -> index = index;
    for(unsigned i = 0; i != output; ++i)
    {
        outWeights.push_back(Connection());
        outWeights.back().weight = random();
    }
}
