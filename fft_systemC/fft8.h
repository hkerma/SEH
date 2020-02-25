#include <systemc.h>
#ifndef FFT8_H
#define FFT8_H

fixed_pt W_fixed[4][2] {{1.0, 0.0}, {0.7071067812, -0.7071067812}, {0.0, -1.0}, {0.7071067812, -0.7071067812}};

typedef struct complex_s complex_t;

struct complex_s {
  fixed_pt real;
  fixed_pt imag;
};

void fft(fixed_pt*, fixed_pt*, fixed_pt*, fixed_pt*);
void but(complex_t*, complex_t*, complex_t*, complex_t*, complex_t*);

SC_MODULE(Fft8){
 public:
  sc_in<bool> Clk;

  sc_in<fixed_pt> In_re, In_im;
  sc_out<fixed_pt> Out_re, Out_im;
  
  sc_in<bool> In_data_valid, Out_data_request;
  sc_out<bool> Out_data_valid, In_data_request;

  void Comportement();

  SC_CTOR(Fft8){
    SC_THREAD(Comportement);
    sensitive << Clk.pos();
  }
};
#endif
