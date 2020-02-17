#include "ff.h"
#include "ff_stimuli.h"
SC_MODULE (Top) {
  // signals
 
  sc_clock clk;
  sc_signal<bool> in1;
  sc_signal<bool> in2;
  sc_signal<bool> out1;
  sc_signal<bool> out2;

  // instanciate
  Ff ff1;
  Ff_stimuli stimuli1;

  void INIT();
  SC_CTOR(Top)
    : clk("clk", 2, SC_NS, 0.5),
    in1 ("in1"),
    out1 ("out1"),
    out2 ("out2"),
    ff1 ("ff1"),
    stimuli1("STIMULI")
      {
	ff1.D(in1);
	ff1.Clk(clk);
	ff1.Q(out1);
	ff1.Qb(out2);
	stimuli1.clk(clk);
	stimuli1.s1(in1);
      }
};
