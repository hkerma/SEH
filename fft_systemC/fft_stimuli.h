#ifndef FFT_STIMULI_H
#define FF_STIMULI_H
#include <systemc.h>

SC_MODULE(Fft_stimuli){
  sc_in<bool> Clk;
  sc_out<bool> Enable;

  void Stim();

  SC_CTOR(Fft_stimuli){
    SC_THREAD(Stim);
    sensitive << Clk.pos();
  }
};
#endif
