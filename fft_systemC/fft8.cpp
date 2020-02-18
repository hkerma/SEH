#include "fft8.h"
#include <systemc.h>

complex_t weights[4] = W;

void Fft8::Comportement(){

  float tmp_in[16];
  float tmp_out[16];

  int data_out = 0;
  
  while(true){
    if (In.num_available() == 16) {
      for(int i = 0; i < 16; ++i){
	tmp_in[i] = In.read();
	fft(tmp_in, tmp_out); //simulate fft
      }
      data_out = 1;
    }
    
    if (Out.num_free() == 16 and data_out) {
      for(int i = 0; i < 16; ++i){
	Out.write(tmp_out[i]);
      }
      data_out = 0;
    }
    wait();
  }
};

void fft(float* tmp_in, float* tmp_out){
  
  float re_in[8], im_in[8], re_out[8], im_out[8];
  complex_t in[8], out[8], stage1[8], stage2[8];

  // Parsing arrays
  for(int i = 0; i < 16; ++i){
    if(i%2){
      im_in[i/2] = *(tmp_in + i);
    } else {
      re_in[i/2] = *(tmp_in + i);
    }
  }
  for(int i = 0; i < 8; ++i){
    in[i].real = re_in[i];
    in[i].imag = im_in[i];
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
    re_out[i] = out[i].real;
    im_out[i] = out[i].imag;
  }
  for(int i = 0; i < 16; ++i){
    if(i%2){
      *(tmp_out + i) = im_out[i/2];
    } else {
      *(tmp_out + i) = re_out[i/2];
    }
  }
  
};

void but(complex_t *weight, complex_t *in0, complex_t *in1, complex_t *out0, complex_t *out1){
  out0->real = (in0->real + ((in1->real * weight->real) - (in1->imag * weight->imag)));
  out0->imag = (in0->imag + ((in1->real * weight->imag) + (in1->imag * weight->real)));
  out1->real = (in0->real - ((in1->real * weight->real) - (in1->imag * weight->imag)));
  out1->imag = (in0->imag - ((in1->real * weight->imag) + (in1->imag * weight->real)));
};

 
  
