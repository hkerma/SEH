#include "xor.h"
#include "xor_stimuli.h"
SC_MODULE (Top) {
  // signals
 
  sc_clock clk;
  sc_signal<bool> in1;
  sc_signal<bool> in2;
  sc_signal<bool> out1;

  // instanciate
  Xor xor1;
  Xor_stimuli stimuli1;

  void INIT();
  SC_CTOR(Top)
    : clk("clk", 2, SC_NS, 0.5),
    in1 ("in1"),
    in2 ("in2"),
    out1 ("out1"),
    xor1 ("xor1"),
    stimuli1("STIMULI")
      {
	xor1.A(in1);
	xor1.B(in2);
	xor1.S(out1);
	stimuli1.clk(clk);
	stimuli1.s1(in1);
	stimuli1.s2(in2);
      }
};
