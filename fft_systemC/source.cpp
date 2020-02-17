#include "source.h"
#include <systemc.h>
#include <iostream>

void Source::Comportement(){
  ifstream stream;
  stream.open("input_samples.txt");

  float tmp_val;
  
  if(!stream)
    cerr << "Erreur d'ouverture du fichier" << endl;
  wait();

  while(true){
    if(!stream.eof()){
      stream >> tmp_val;
      Out.write(tmp_val);
      wait();
    } else {
      cout << "End of file" << endl;
      stream.close();
      break;
      wait();
    }
  }
};
