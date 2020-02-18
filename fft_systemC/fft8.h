#include <systemc.h>
#ifndef FFT8_H
#define FFT8_H
#define W {					\
    {1, 0},					\
    {0.7071067812, -0.7071067812},		\
    {0, -1},					\
    {-0.7071067812, -0.7071067812}		\
  }

typedef struct complex_s complex_t;

struct complex_s {
  sc_int<23> real;
  sc_int<23> imag;
};

void fft(sc_int<23>*, sc_int<23>*, sc_int<23>*, sc_int<23>*);
void but(complex_t*, complex_t*, complex_t*, complex_t*, complex_t*);

SC_MODULE(Fft8){
 public:
  sc_in<bool> Clk;

  sc_in<sc_int<23>> In_re, In_im;
  sc_out<sc_int<23>> Out_re, Out_im;
  
  sc_in<bool> In_data_valid, Out_data_request;
  sc_out<bool> Out_data_valid, In_data_request;

  void Comportement();

  SC_CTOR(Fft8){
    SC_THREAD(Comportement);
    sensitive << Clk.pos();
  }
};
#endif
