#include <systemc.h>
#include "nand.h"
#ifndef XOR_H
#define XOR_H

SC_MODULE(Xor)
{

 public : 
  sc_in<bool> A,B; // bool peut etre remplace par sc_bit
  sc_out<bool> S;

  sc_signal<bool> signal_1, signal_21, signal_22;
  
  Nand *nand1, *nand21, *nand22, *nand3;
        
  SC_CTOR(Xor)
  {
    nand1 = new Nand("nand1");
    nand21 = new Nand("nand21");
    nand22 = new Nand("nand22");
    nand3 = new Nand("nand3");
    
    nand1->A(A);
    nand1->B(B);
    nand1->S(signal_1);
    
    nand21->A(A);
    nand21->B(signal_1);
    nand21->S(signal_21);
    
    nand22->A(signal_1);
    nand22->B(B);
    nand22->S(signal_22);
    
    nand3->A(signal_21);
    nand3->B(signal_22);
    nand3->S(S);
    
  }    
};
#endif
