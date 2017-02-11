#ifndef NET_HH
#define NET_HH

//#define NDEBUG


#include <iostream>
#include <vector>
#include "Neuron.hh"
#include <cmath>
#include <assert.h>

using namespace std;

class Net{

    private:
        
        typedef vector<Neuron> Layer;
        
        vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
        double m_error;
        double m_recentAverageError;
        double m_recentAverageSmoothingFactor = 100.0;

    public:
        
        Net();
        
        ~Net();
        
        Net(const vector<unsigned> &topology);
        
        void feedForward(const vector<double> &inputVals);
        
        
        void backProp(const vector<double> &targetVals);
        
        void getResults(vector<double> &resultVals) const;
        
        double getRecentAverageError()const;

};

#endif
