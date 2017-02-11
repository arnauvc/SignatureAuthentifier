
#ifndef TRAININGDATA_HH
#define TRAININGDATA_HH

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

class TrainingData{
    private:
        ifstream m_trainingDataFile;
    public:

        TrainingData();

        TrainingData(const string filename);
        
        ~TrainingData();
        
        bool isEof();

        void getTopology(vector<unsigned> &topology);

        unsigned getNextInputs(vector<double> &inputVals);
        
        unsigned getTargetOutputs(vector<double> &targetOutputVals);
};

#endif
