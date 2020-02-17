#include "add1.h"
#include "add1_stimuli.h"
SC_MODULE (Top) {
  // signals
 
  sc_clock clk;
  sc_signal<bool> A;
  sc_signal<bool> B;
  sc_signal<bool> C_in
  sc_signal<bool> C_out;
  sc_signal<bool> S;

  // instanciate
  Add1 add1;
  Add1_stimuli stimuli1;

  void INIT();
  SC_CTOR(Top)
    : clk("clk", 2, SC_NS, 0.5),
    A ("A"),
    B ("B"),
    C ("C"),
    S ("S"),
    C_out ("C_out"),
    add1 ("ff1"),
    stimuli1("stimuli")
      {
	add1.A(A);
	add1.B(B);
	add1.C_in(C_in);
	add1.S(S);
	add1.C_out(C_out);
	stimuli1.clk(clk);
	stimuli1.A(A);
	stimuli1.B(B);
	stimuli1.C_in(C_in);
      }
};
