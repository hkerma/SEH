#include "latch.h"
#include "latch_stimuli.h"
SC_MODULE (Top) {
  // signals
 
  sc_clock clk;
  sc_signal<bool> in1;
  sc_signal<bool> in2;
  sc_signal<bool> out1;
  sc_signal<bool> out2;

  // instanciate
  Latch latch1;
  Stimuli stimuli1;

  void INIT();
  SC_CTOR(Top)
    : clk("clk", 2, SC_NS, 0.5),
    in1 ("in1"),
    in2 ("in2"),
    out1 ("out1"),
    out2("out2"),
    latch1 ("latch1"),
    stimuli1("stimuli1")
      {
	latch1.E(in1);
	latch1.D(in2);
	latch1.Q(out1);
	latch1.QB(out2);
	stimuli1.clk(clk);
	stimuli1.s1(in1);
	stimuli1.s2(in2);
      }
};
