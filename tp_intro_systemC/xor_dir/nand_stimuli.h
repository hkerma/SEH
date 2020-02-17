#include <systemc.h>
#ifndef NAND_STIMULI_H
#define NAND_STIMULI_H

SC_MODULE(Nand_stimuli)
{
 public :
  sc_in_clk clk;
  sc_out<bool> s1,s2;
      
  SC_CTOR(Nand_stimuli)
    {
      SC_THREAD (stim);
      sensitive << clk.pos();
    }
 private : 
  void stim ();
  
};

#endif
