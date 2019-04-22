#include <iostream>
#include <cstdio>
#include <string>

#include "common.h"
#include "quworld.h"
#include "qudotconfig.h"

void doSomeQuantum() {
   QuWorld myWorld(5, 1, ONE_AMP64);
   myWorld.setDotAmplitude(2, ZERO, ROOT2);
   myWorld.setDotAmplitude(2, ONE, ROOT2);
   myWorld.setDotAmplitude(5, ZERO, ROOT2);
   myWorld.setDotAmplitude(5, ONE, ROOT2);   
   
   myWorld.swapQubits(2,4);
   myWorld.swapQubits(5,1);
   for (int i=0; i < 10; i++) {
      std::cout << myWorld.measure() << std::endl;
   }
}

int main(int argc, char *argv[]) {
   std::cout << "QuDot Kratos Virtual Machine |001>" << std::endl;

   QuDotConfig config;
   int arg_ptr = 1;
   std::string filename;
   while (arg_ptr < argc) {
       std::string arg = std::string(argv[arg_ptr]);
       if (arg.compare("-qubits") == 0) {
          arg_ptr++;
          config.setNumQubits(std::stoi(std::string(argv[arg_ptr])));     
       } else if (arg.compare("-stack") == 0) {
          arg_ptr++;
          config.setStackSize(std::stoi(std::string(argv[arg_ptr])));
       } else if (arg.compare("-ensemble") == 0) {
          arg_ptr++;
          config.setEnsembleSize(std::stoi(std::string(argv[arg_ptr])));
       } else if (arg.compare("-print") == 0) {
          config.setPrintResults(true);
       } else if (arg.compare("-multiverse") == 0) {
          arg_ptr++;
          config.setMultiverseSize(std::stoi(std::string(argv[arg_ptr])));
       } else {
          filename = std::string(argv[arg_ptr]);
       }
       arg_ptr++;
   }

   if (filename.size() == 0) {
      std::cerr << "no input file found" << std::endl;
      return 1;
   }
   
   printf("QuDotConfig: qubits: %d, ensemble: %d, multiverse: %d, stack: %d\n", config.getNumQubits(), config.getEnsembleSize(),
         config.getMultiverseSize(), config.getStackSize());

   return 0;
}
