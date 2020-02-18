#include "fft8.h"
#include <systemc.h>

complex_t weights[4] = W;

void Fft8::Comportement(){

  sc_int<23> tmp_in_re[8], tmp_in_im[8];
  sc_int<23> tmp_out_re[8], tmp_out_im[8];
  
  In_data_request = 0;
  Out_data_valid = 0;
  
  int in_data_count = 0;
  int out_data_count = 0;
  
  while(true){
    while(in_data_count != 8){
      In_data_request = 1;
      wait();
      if(In_data_valid){
	tmp_in_re[in_data_count] = In_re;
	tmp_in_im[in_data_count] = In_im;
	++in_data_count;
      }
      In_data_request = 0;
    }
    
    in_data_count = 0;
    fft(tmp_in_re, tmp_in_im, tmp_out_re, tmp_out_im);
    
    while(out_data_count != 8){
      Out_data_valid = 1;
      Out_re = tmp_out_re[out_data_count];
      Out_im = tmp_out_im[out_data_count];
      wait();
      if(Out_data_request){
	++out_data_count;
      }
      Out_data_valid = 0;
    }
    
    out_data_count = 0;    
  }
}

void fft(sc_int<23>* in_re, sc_int<23>* in_im, sc_int<23>* out_re, sc_int<23>* out_im){
  
  complex_t in[8], out[8], stage1[8], stage2[8];

  for(int i = 0; i < 8; ++i){
    in[i].real = in_re[i];
    in[i].imag = in_im[i];
  }

  // First stage
  but(&weights[0], &in[0], &in[4], &stage1[0], &stage1[1]);
  but(&weights[0], &in[2], &in[6], &stage1[2], &stage1[3]);
  but(&weights[0], &in[1], &in[5], &stage1[4], &stage1[5]);
  but(&weights[0], &in[3], &in[7], &stage1[6], &stage1[7]);

  // Second stage
  but(&weights[0], &stage1[0], &stage1[2], &stage2[0], &stage2[2]);
  but(&weights[2], &stage1[1], &stage1[3], &stage2[1], &stage2[3]);
  but(&weights[0], &stage1[4], &stage1[6], &stage2[4], &stage2[6]);
  but(&weights[2], &stage1[5], &stage1[7], &stage2[5], &stage2[7]);
                
  // Etape 3
  but(&weights[0], &stage2[0], &stage2[4], &out[0], &out[4]);
  but(&weights[1], &stage2[1], &stage2[5], &out[1], &out[5]);
  but(&weights[2], &stage2[2], &stage2[6], &out[2], &out[6]);
  but(&weights[3], &stage2[3], &stage2[7], &out[3], &out[7]);

  // Unparsing arrays
  for(int i = 0; i < 8; ++i){
    out_re[i] = out[i].real;
    out_im[i] = out[i].imag;
  }  
}

void but(complex_t *weight, complex_t *in0, complex_t *in1, complex_t *out0, complex_t *out1){
  out0->real = (in0->real + ((in1->real * weight->real) - (in1->imag * weight->imag)));
  out0->imag = (in0->imag + ((in1->real * weight->imag) + (in1->imag * weight->real)));
  out1->real = (in0->real - ((in1->real * weight->real) - (in1->imag * weight->imag)));
  out1->imag = (in0->imag - ((in1->real * weight->imag) + (in1->imag * weight->real)));
}

 
  
