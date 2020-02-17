#include "fft8.h"
#include <systemc.h>

void Fft8::Comportement(){
  while(true){
    Out.write(In.read());
    wait();
  }
};
