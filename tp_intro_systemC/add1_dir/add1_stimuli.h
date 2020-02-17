#ifndef ADD1_STIMULI_H
#define ADD1_STIMULI_H
#include <systemc.h>

SC_MODULE(Stimuli){
  sc_in_clk clk;
  sc_out<bool> A,B,C_in;

  void Stim();

  SC_CTOR(Stimuli){
    SC_THREAD(Stim);
    sensitive << clk.pos();
  }
};

#endif
