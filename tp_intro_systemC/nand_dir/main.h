#include "nand.h"
#include "nand_stimuli.h"
SC_MODULE (Top) {
  // signals
 
  sc_clock clk;
  sc_signal<bool> in1;
  sc_signal<bool> in2;
  sc_signal<bool> out1;

  // instanciate
  Nand nand1;
  Nand_stimuli stimuli1;

  void INIT();
  SC_CTOR(Top)
    : clk("clk", 2, SC_NS, 0.5),
    in1 ("in1"),
    in2 ("in2"),
    out1 ("out1"),
    nand1 ("nand1"),
    stimuli1("STIMULI")
      {
	nand1.A(in1);
	nand1.B(in2);
	nand1.S(out1);
	stimuli1.clk(clk);
	stimuli1.s1(in1);
	stimuli1.s2(in2);
      }
};
