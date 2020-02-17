#include <systemc.h>
#ifndef XOR_STIMULI_H
#define XOR_STIMULI_H

SC_MODULE(Xor_stimuli)
{
 public :
  sc_in_clk clk;
  sc_out<bool> s1,s2;
      
  SC_CTOR(Xor_stimuli)
    {
      SC_THREAD (stim);
      sensitive << clk.pos();
    }
 private : 
  void stim ();
  
};

#endif
