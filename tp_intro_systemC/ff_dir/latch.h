#ifndef LATCH_H
#define LATCH_H
#include <systemc.h>

SC_MODULE(Latch){
  sc_in<bool> E;
  sc_in<bool> D;
  sc_out<bool> Q;
  sc_out<bool> Qb;

  /*sc_signal<bool> qplus;
    sc_signal<bool> qbplus; //useless in fact (?) */
  
  void Comportement();
  
  SC_CTOR(Latch){
    SC_METHOD(Comportement);
    sensitive <<E <<D;
  }
};

#endif
    
    
