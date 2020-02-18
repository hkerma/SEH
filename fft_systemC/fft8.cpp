#include "fft8.h"
#include <systemc.h>

void Fft8::Comportement(){

  float tmp_in[16];
  float tmp_out[16];

  int data_out = 0;
  
  while(true){
    if (In.num_available() == 16) {
      for(int i = 0; i < 16; ++i){
	tmp_in[i] = In.read();
	tmp_out[i] = tmp_in[i]; //simulate fft
      }
      data_out = 1;
    }
    
    if (Out.num_free() == 16 and data_out) {
      for(int i = 0; i < 16; ++i){
	Out.write(tmp_out[i]);
      }
      data_out = 0;
    }
    wait();
  }
};
