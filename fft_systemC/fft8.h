#include <systemc.h>
#ifndef FFT8_H
#define FFT8_H

SC_MODULE(Fft8){
 public:
  sc_in<bool> Clk;
  sc_fifo_in<float> In;
  sc_fifo_out<float> Out;

  void Comportement();

  SC_CTOR(Fft8){
    SC_THREAD(Comportement);
    sensitive << Clk.pos();
  }
};
#endif
