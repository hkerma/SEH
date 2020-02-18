#include "sink.h"
#include <systemc.h>
#include <iostream>

void Sink::Comportement(){
  ofstream stream;
  stream.open("output_samples.txt");

  float tmp_val;
  
  if(!stream)
    cerr << "Erreur d'ouverture du fichier" << endl;
  wait();
  
  while(true){
    if (In.num_available() == 16) {
      for (int i=0; i < 16; ++i){
	tmp_val = In.read();
	stream << tmp_val << endl;
      }
    } else {
      cout << "Waiting for fifo_out to be full" << endl;
    }
    wait();
  }
};
