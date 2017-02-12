#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;

int main(){
	cout <<"topology: 1000  200 1" << endl;
	vector< vector<double> > dataset;
	int numimatges = 3918;	
	for(int i = 0; i < numimatges; ++i){
		dataset.push_back(vector<double> ());
		 ifstream m_trainingDataFile;
		string filename  = "./datatext/input"+to_string(i)+".txt";
		m_trainingDataFile.open(filename.c_str());
		 string line;
    		getline(m_trainingDataFile, line);
    		stringstream ss(line);
    		double label;
        		while (ss >> label) {
              			dataset[i].push_back(label);
       		 }
       		dataset[i].push_back(0.0);
    	}
    	int numimatgesbones = 7;

    	for(int i = 0; i < numimatgesbones; ++i){
		dataset.push_back(vector<double> ());
		 ifstream m_trainingDataFile;
		string filename  = "./datatext_personal/input"+to_string(i)+".txt";
			m_trainingDataFile.open(filename.c_str());
			 string line;
	    		getline(m_trainingDataFile, line);
	    		stringstream ss(line);
	    		double label;
	        		while (ss >> label) {
	              			dataset.back().push_back(label);
	       		 }
	       		dataset.back().push_back(1.0);
	       		for(int f = 0; f < 475; ++f){
	       			dataset.push_back(dataset.back());
	       		}
    	}

    	random_shuffle( dataset.begin(),dataset.end() );

	for (int i = 0; i < dataset.size(); ++i){

		cout << "in: " ;
		for(int j = 0; j < dataset[i].size()-1 ; ++j) cout << dataset[i][j] << " " ; 
		cout << endl << "out: " << dataset[i].back() <<endl;
 	}
 	
}
