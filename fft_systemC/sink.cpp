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
    tmp_val = In.read();
    stream << tmp_val << endl;
    wait();
  }
};
