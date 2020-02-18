#include "sink.h"
#include <systemc.h>
#include <iostream>

void Sink::Comportement(){
  ofstream stream;
  stream.open("output_samples.txt");

  Data_request = 0;

  if(!stream)
    cerr << "Erreur d'ouverture du fichier" << endl;
  wait();
  
  while(true){
    if (Data_valid){
      Data_request = 1;
      stream << In_re << endl;
      stream << In_im << endl;
      wait();
      Data_request = 0;
    } else {
    wait();
  }
}
