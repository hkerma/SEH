#include <systemc.h>
#include "latch.h"

void Ram::Comportement(){
  
};

void Ram::Reset(){
  for(int i; i < RAM_SIZE; i++){
    mem[i] = 0;
  }
  
