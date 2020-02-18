#include "source.h"
#include <systemc.h>
#include <iostream>

void Source::Comportement(){
  ifstream stream;
  stream.open("input_samples.txt");

  float tmp_re, tmp_im;
  Data_valid = 0;
  int eof = 0;
  
  if(!stream)
    cerr << "Erreur d'ouverture du fichier" << endl;
  wait();

  while(true){
    if(!eof){
      if(stream >> tmp_re && stream >> tmp_im){ //if end of file, read will return 0 !
	Data_valid = 1;
	Out_re = tmp_re;
	Out_im = tmp_im;
	Data_valid = 0;
      } else {
	eof = 1;
	stream.close();
	break;
	//going out of loop, end of file
      }
    }
    wait();
  }
};
