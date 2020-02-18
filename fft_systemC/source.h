#include <systemc.h>
#ifndef SOURCE_H
#define SOURCE_H

SC_MODULE(Source){
 public:
  sc_in<bool> Clk;
  sc_in<bool> Data_request;
  sc_out<bool> Data_valid;
  
  sc_out<float> Out_re;
  sc_out<float> Out_im;

  void Comportement();

  SC_CTOR(Source){
    SC_THREAD(Comportement);
    sensitive << Clk.pos();
  }
};
#endif
