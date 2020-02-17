#include "ff.h"
#include <systemc.h>

void Ff::Comportement(){
  signal_not_clk = !Clk;
};
