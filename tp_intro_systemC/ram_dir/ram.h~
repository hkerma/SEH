#include <systemc.h>
#include "xor.h"
#include "nand.h"
#ifndef ADD1_H
#define ADD1_H

SC_MODULE(Add1)
{

 public:
  sc_in<bool> A,B,C_in;
  sc_out<bool> S,C_out;

  sc_signal<bool> signal_xor_c, signal_xor, signal_nand1, signal_nand2, signal_nand_s;

  Nand *nand1, *nand2, *nand_s;
  Xor *xor1, *xor_c;
  
  SC_CTOR(Add1)
  {
    xor1 = new Xor("xor1");
    xor_c = new Xor("xor_c");

    nand1 = new Nand("nand1");
    nand2 = new Nand("nand2");
    nand_s = new Nand("nand_s");

    xor1->A(A);
    xor1->B(B);
    xor1->S(signal_xor);
    xor_c->A(signal_xor);
    xor_c->B(C_in);
    xor_c->S(S);

    nand1->A(A);
    nand1->B(B);
    nand1->S(signal_nand1);
    nand2->A(C_in);
    nand2->B(signal_xor);
    nand2->S(signal_nand2);
    nand_s->A(signal_nand1);
    nand_s->B(signal_nand2);
    nand_s->S(C_out);
    
  }
};

#endif
