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
	cout <<"topology: 1000  400 50 1" << endl;
	vector< vector<double> > dataset;
	int numimatges = 26;	
	for(int i = 0; i < numimatges; ++i){
		dataset.push_back(vector<double> ());
		 ifstream m_trainingDataFile;
		string filename  = "./no/input"+to_string(i)+".txt";
			m_trainingDataFile.open(filename.c_str());
			 string line;
	    		getline(m_trainingDataFile, line);
	    		stringstream ss(line);
	    		double label;
	        		while (ss >> label) {
	              			dataset.back().push_back(label);
	       		 }
	       		dataset.back().push_back(-1.0);
	       		
	       		for(int f = 0; f < 50; ++f){
	       			dataset.push_back(dataset.back());
	       		}
	       		
    	}
    	int numimatgesbones = 26;

    	for(int i = 0; i < numimatgesbones; ++i){
		dataset.push_back(vector<double> ());
		 ifstream m_trainingDataFile;
		string filename  = "./si/input"+to_string(i)+".txt";
			m_trainingDataFile.open(filename.c_str());
			 string line;
	    		getline(m_trainingDataFile, line);
	    		stringstream ss(line);
	    		double label;
	        		while (ss >> label) {
	              			dataset.back().push_back(label);
	       		 }
	       		dataset.back().push_back(1.0);
	       		
	       		for(int f = 0; f < 50; ++f){
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
