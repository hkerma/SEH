#include "global.h"
#include "source.h"
#include <systemc.h>
#include <iostream>

void Source::Comportement(){
  ifstream stream;
  stream.open("input_samples.txt");

  float tmp_re, tmp_im;
  fixed_pt fixed_re, fixed_im;
  Data_valid = 0;
  int eof = 0;
  
  if(!stream)
    cerr << "Erreur d'ouverture du fichier" << endl;
  wait();

  while(true){
    if(Data_request && !eof){
      if(stream >> tmp_re && stream >> tmp_im){
	Data_valid = 1;
	Out_re = tmp_re;
	Out_im = tmp_im;
	wait();
	Data_valid = 0;
      } else {
	eof = 1;
	stream.close();
      }
    } else {
      Data_valid = 0;
    }
    wait();
  }
}
