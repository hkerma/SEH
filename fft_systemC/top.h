#include <systemc.h>
#include "source.h"
#include "sink.h"
#include "fft.h"
#ifndef TOP_H
#define TOP_H

SC_MODULE(Top)
{
 public:
  sc_in<bool> Clk, Rst;
  sc_fifo<float> fifo_input, fifo_output;
  
  Source *source;
  Sink *sink;
  Fft *fft;

  SC_CTOR(Top){
    SC_METHOD(Comportement);
    sensitive << Clk.pos();

    source = new Source("source");
    sink = new Sink("sink");
    fft = new Fft("fft");

    source->Out(fifo_input);
    fft->In(fifo_input);
    fft->Out(fifo_output);
    sink->In(fifo_output);
  }
};
#endif
