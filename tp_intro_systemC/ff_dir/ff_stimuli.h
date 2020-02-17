#ifndef FF_STIMULI_H
#define FF_STIMULI_H
#include <systemc.h>

SC_MODULE(Ff_stimuli){
  sc_in_clk clk;
  sc_out<bool> s1;

  void Stim();

  SC_CTOR(Ff_stimuli){
    SC_THREAD(Stim);
    sensitive << clk.pos();
  }
};

#endif
