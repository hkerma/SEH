#include <systemc.h>
#ifndef NAND_H
#define NAND_H

SC_MODULE(Nand)
{

 public : 
  sc_in<bool> A,B; // bool peut etre remplace par sc_bit
  sc_out<bool> S;
  SC_CTOR(Nand)
  {
    SC_METHOD (Comportement);
    sensitive << A << B;
  }
 private :
  void Comportement();
    
};

#endif
