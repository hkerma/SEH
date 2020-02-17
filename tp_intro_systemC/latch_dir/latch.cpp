#include <systemc.h>
#include "latch.h"

void Latch::Comportement(){
  if (E){
    Q = D;
    Qb = !D;
  }
};
