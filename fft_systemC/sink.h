#include <systemc.h>
#ifndef SINK_H
#define SINK_H

SC_MODULE(Sink){
 public:
  sc_in<bool> Clk;
  sc_in<bool> Data_valid;
  sc_out<bool> Data_request;
  
  sc_in<float> In_re;
  sc_in<float> In_im;

  void Comportement();

  SC_CTOR(Sink){
    SC_THREAD(Comportement);
    sensitive << Clk.pos();
  }
};
#endif
