#include <systemc.h>
#ifndef FFT_H
#define FFT_H
#include "fft8.h"
#include "sink.h"
#include "source.h"

SC_MODULE(Fft){
 public:
  sc_in<bool> Clk;
  sc_signal<fixed_pt> In_re, In_im, Out_re, Out_im;

  sc_signal<bool> In_data_valid, Out_data_valid, In_data_request, Out_data_request;
    
  Fft8 *fft8;
  Source *source;
  Sink *sink;
  
  SC_CTOR(Fft){

    fft8 = new Fft8("fft8");
    source = new Source("source");
    sink = new Sink("sink");
    
    fft8->Clk(Clk);
    fft8->In_re(In_re);
    fft8->In_im(In_im);
    fft8->Out_re(Out_re);
    fft8->Out_im(Out_im);
    
    fft8->In_data_valid(In_data_valid);
    fft8->In_data_request(In_data_request);
    fft8->Out_data_request(Out_data_request);
    fft8->Out_data_valid(Out_data_valid);

    source->Clk(Clk);
    source->Out_re(In_re);
    source->Out_im(In_im);
    source->Data_valid(In_data_valid);
    source->Data_request(In_data_request);

    sink->Clk(Clk);
    sink->In_re(Out_re);
    sink->In_im(Out_im);
    sink->Data_valid(Out_data_valid);
    sink->Data_request(Out_data_request);
  }
};
#endif
