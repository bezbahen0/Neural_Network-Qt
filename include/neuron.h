#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <cmath>

class Neuron;
typedef std::vector<Neuron> Layer;


struct Connection
{
    double weight;
    double delta_weight;
};

class Neuron
{
private:
    const double learningRate = 0.01;
    const double alpha = 0.2;
    static double activation_f(double value){return tanh(value); }
    //static double activation_f(double value){return 1 / (1 + exp(-value)); }
    static double derivative_activation_f(double value){return 1 - tanh(value) * tanh(value); }
    //static double derivative_activation_f(double value){return activation_f(value) * (1 - activation_f(value)); }
    static double random(){return rand() / double(RAND_MAX); }
    double accumulate(const Layer& nextLayer);
    double output;
    std::vector<Connection> outWeights;
    unsigned index;
    double gradient;
public:
    Neuron(unsigned output, unsigned index);
    double getOutput() const {return output; }
    void setOutput(double value){output = value; }
    void feedForward(const Layer& prevLayer);
    void calculateOutputGradients(double target);
    void calculateHiddenGradients(const Layer& nextLayer);
    void updateWeights(Layer& prevLayer);
};

#endif // NEURON_H
