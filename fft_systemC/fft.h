#include <systemc.h>
#include "fft8.h"
#include "sink.h"
#include "source.h"

#ifndef FFT_H
#define FFT_H

SC_MODULE(Fft){
 public:
  sc_in<bool> Clk, Enable;
  sc_fifo<float> *fifo_in, *fifo_out;
    
  Fft8 *fft8;
  Source *source;
  Sink *sink;
  
  SC_CTOR(Fft){

    fft8 = new Fft8("fft8");
    source = new Source("source");
    sink = new Sink("sink");

    fifo_in = new sc_fifo<float>("fifo_in", 16);
    fifo_out = new sc_fifo<float>("fifo_out", 16);
    
    fft8->Clk(Clk);
    fft8->In(*fifo_in);
    fft8->Out(*fifo_out);

    source->Clk(Clk);
    source->Out(*fifo_in);

    sink->Clk(Clk);
    sink->In(*fifo_out);
  }
};
#endif
