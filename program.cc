
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
#include "Net.hh"
#include "TrainingData.hh"


using namespace std;


void showVectorVals(string label, vector<double> &v)
{
    cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    TrainingData trainData("./TrainingData.txt");

    // e.g., { 3, 2, 1 }
    vector<unsigned> topology;
    trainData.getTopology(topology);

    Net myNet(topology);

    vector<double> inputVals, targetVals, resultVals;
    int trainingPass = 0;

    while (!trainData.isEof()) {
        ++trainingPass;
        cout << endl << "Pass " << trainingPass;

        // Get new input data and feed it forward:
        if (trainData.getNextInputs(inputVals) != topology[0]) {
            break;
        }
        //showVectorVals(": Inputs:", inputVals);
        myNet.feedForward(inputVals);

        // Collect the net's actual output results:
        myNet.getResults(resultVals);
        showVectorVals("Outputs:", resultVals);

        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals);
        assert(targetVals.size() == topology.back());

        myNet.backProp(targetVals);

        // Report how well the training is working, average over recent samples:
        cout << "Net recent average error: " << myNet.getRecentAverageError() << endl;
    }

    cout << endl << " Training Done" << endl;

    cout << "Write path of new picture file" << endl;
    string newpath;
   for(int i = 0; i < 11; ++i){
        string newpath  = "./testsi/input"+to_string(i)+".txt";
        vector<double> inputValues;
        ifstream m_trainingDataFile;
        
        m_trainingDataFile.open(newpath.c_str());
        string line;
        getline(m_trainingDataFile, line);
        stringstream ss(line);
        double valor;
        while (ss >> valor) {
            inputValues.push_back(valor);
        }
        myNet.feedForward(inputValues);
        myNet.getResults(resultVals);
        showVectorVals("Outputs from TRUE:", resultVals);
    }
     for(int i = 0; i < 3; ++i){
        string newpath  = "./testno/input"+to_string(i)+".txt";
        vector<double> inputValues;
        ifstream m_trainingDataFile;
        
        m_trainingDataFile.open(newpath.c_str());
        string line;
        getline(m_trainingDataFile, line);
        stringstream ss(line);
        double valor;
        while (ss >> valor) {
            inputValues.push_back(valor);
        }
        myNet.feedForward(inputValues);
        myNet.getResults(resultVals);
        showVectorVals("Outputs from FALSE:", resultVals);
    }
    
     for(int i = 0; i < 10; ++i){
        string newpath  = "./testimitar/input"+to_string(i)+".txt";
        vector<double> inputValues;
        ifstream m_trainingDataFile;
        
        m_trainingDataFile.open(newpath.c_str());
        string line;
        getline(m_trainingDataFile, line);
        stringstream ss(line);
        double valor;
        while (ss >> valor) {
            inputValues.push_back(valor);
        }
        myNet.feedForward(inputValues);
        myNet.getResults(resultVals);
        showVectorVals("Outputs from FORGE ", resultVals);
    }
    
      for(int i = 0; i < 5; ++i){
        string newpath  = "./testrandom/input"+to_string(i)+".txt";
        vector<double> inputValues;
        ifstream m_trainingDataFile;
        
        m_trainingDataFile.open(newpath.c_str());
        string line;
        getline(m_trainingDataFile, line);
        stringstream ss(line);
        double valor;
        while (ss >> valor) {
            inputValues.push_back(valor);
        }
        myNet.feedForward(inputValues);
        myNet.getResults(resultVals);
        showVectorVals("Outputs from RANDOM: ", resultVals);
    }
    
}
