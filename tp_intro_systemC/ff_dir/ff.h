#include <systemc.h>
#include "latch.h"
#ifndef FF_H
#define FF_H

SC_MODULE(Ff)
{

 public : 
  sc_in<bool> Clk,D; // bool peut etre remplace par sc_bit
  sc_out<bool> Q,Qb;
  sc_signal<bool> signal_Q1;
  sc_signal<bool> signal_not_clk;
  sc_signal<bool> signal_null;

  void Comportement();
  Latch *latch1, *latch2;
        
  SC_CTOR(Ff)
  {
    SC_METHOD(Comportement);
    sensitive << Clk.pos() << Clk.neg();
    
    latch1 = new Latch("latch1");
    latch2 = new Latch("latch2");

    latch1->E(signal_not_clk);
    latch1->D(D);
    latch1->Q(signal_Q1);
    latch1->Qb(signal_null);

    latch2->D(signal_Q1);
    latch2->E(Clk);
    latch2->Q(Q);
    latch2->Qb(Qb);

    
  }    
};
#endif
