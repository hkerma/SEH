#ifndef LATCH_STIMULI_H
#define LATCH_STIMULI_H
#include <systemc.h>

SC_MODULE(STIMULI){
  sc_in_clk clk;
  sc_out<bool> s1, s2;

  void STIM();

  SC_CTOR(STIMULI){
    SC_THREAD(STIM);
    sensitive << clk.pos();
  }
};

#endif
