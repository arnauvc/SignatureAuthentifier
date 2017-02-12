OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

all: Neuron.o Net.o TrainingData.o  program.o program.exe makeTrainingSamples  TrainingData executar_program clean
	
Neuron.o: Neuron.cc Neuron.hh
	g++ -c $(OPCIONS) Neuron.cc 
 
Net.o: Net.cc Net.hh
	g++ -c $(OPCIONS) Net.cc 
 
TrainingData.o: TrainingData.cc TrainingData.hh
	g++ -c $(OPCIONS) TrainingData.cc 
 
program.o: program.cc
	g++ -c $(OPCIONS) program.cc 
 
program.exe: program.o Neuron.o Net.o TrainingData.o
	g++ -o  program.exe program.o Neuron.o Net.o TrainingData.o
	
makeTrainingSamples: makeTrainingSamples.cc
	g++ -o makeTrainingSamples.exe makeTrainingSamples.cc 

TrainingData: makeTrainingSamples.exe
	./makeTrainingSamples.exe > TrainingData.txt 
executar_program: program.exe
	./program.exe

clean:
	rm *.o
