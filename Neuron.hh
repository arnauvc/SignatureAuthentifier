#ifndef NEURON_HH
#define NEURON_HH

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Neuron{

    private:
        
        struct Connection{
            double weight;
            double deltaWeight;
        };
        
        typedef vector<Neuron> Layer;
        
        double eta = 0.15;   // [0.0..1.0] overall net training rate
        double alpha = 0.5; // [0.0..n] multiplier of last weight change (momentum)
        
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        double randomWeight();
        double sumDOW(const Layer &nextLayer) const;
        
        double m_outputVal;
        vector<Connection> m_outputWeights;
        unsigned m_myIndex;
        double m_gradient;

    public:

        Neuron();

        Neuron(unsigned numOutputs, unsigned myIndex);

        ~Neuron();

        void setOutputVal(double val);

        double getOutputVal() const;

        void updateInputWeights(Layer &prevLayer);

        void calcHiddenGradients(const Layer &nextLayer);

        void calcOutputGradients(double targetVal);

        void feedForward(const Layer &prevLayer);

};

#endif
