//#include "main.h"
// void Top::INIT()
// {
//   in1 = 0;
//   in2 = 0;
//   out1 = 1;
// }

// SC_MODULE_EXPORT(Top);
/* fichier main.cpp */

#include <systemc.h>
#include "ff.h"
#include "ff_stimuli.h"
int sc_main(int ac, char *av[])
{
  sc_trace_file *tf;
  // signals
  sc_signal<bool> in1;
  sc_signal<bool> out1;
  sc_signal<bool> out2;

  // instanciate
  Ff ff1("ff1");
  Ff_stimuli stimuli1("stimuli1");
  sc_clock clk ("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
  // link
  ff1.D(in1);
  ff1.Clk(clk);
  ff1.Q(out1);
  ff1.Qb(out2);
  stimuli1.clk(clk);
  stimuli1.s1(in1);
  // Waves:
  tf = sc_create_vcd_trace_file("waves");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, clk, "clk");
  sc_trace(tf,in1,"in1");
  sc_trace(tf,out1,"out1");
  sc_trace(tf,ff1.signal_not_clk, "notclk"); //monitoring
  sc_trace(tf,out2,"out2");
  sc_start(500, SC_NS);
  sc_close_vcd_trace_file(tf);
  return 0;
}
