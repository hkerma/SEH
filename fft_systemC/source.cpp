#include "source.h"
#include <systemc.h>
#include <iostream>

void Source::Comportement(){
  ifstream stream;
  stream.open("input_samples.txt");

  float tmp_val;
  int eof = 0;
  
  if(!stream)
    cerr << "Erreur d'ouverture du fichier" << endl;
  wait();

  while(true){
    if(!eof){
      if(Out.num_free() == 16){
	for(int i = 0; i < 16; ++i){
	  if(stream >> tmp_val){ //if end of file, read will return 0 !
	    Out.write(tmp_val);
	  } else {
	    eof = 1;
	    stream.close();
	    break;
	    //going out of loop, end of file
	  }
	}
      } else {
	cout << "Waiting for fifo_in to be empty" << endl;
      }
    } else {
      cout << "End of file reached" << endl;
    }
    wait();
  }
};
