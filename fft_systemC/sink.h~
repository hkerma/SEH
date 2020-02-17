#include <systemc.h>
#ifndef SINK_H
#define SINK_H

SC_MODULE(Sink){
 public:
  sc_in<bool> Clk;
  sc_fifo_in<float> In;

  void Comportement();

  SC_CTOR(Sink){
    SC_THREAD(Comportement);
    sensitive << Clk.pos();
  }
};
#endif
