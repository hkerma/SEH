#include <systemc.h>
#ifndef SOURCE_H
#define SOURCE_H

SC_MODULE(Source){
 public:
  sc_in<bool> Clk;
  
  sc_fifo_out<float> Out;

  void Comportement();

  SC_CTOR(Source){
    SC_THREAD(Comportement);
    sensitive << Clk.pos();
  }
};
#endif
