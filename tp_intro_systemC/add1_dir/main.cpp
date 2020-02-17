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
#include "add1.h"
#include "add1_stimuli.h"
int sc_main(int ac, char *av[])
{
  sc_trace_file *tf;
  // signals
  sc_signal<bool> A;
  sc_signal<bool> B;
  sc_signal<bool> C_in;
  sc_signal<bool> C_out;
  sc_signal<bool> S;
  // instanciate
  Add1 add1("add1");
  Stimuli stimuli1("stimuli1");
  sc_clock clk ("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
  // link
  add1.A(A);
  add1.B(B);
  add1.C_in(C_in);
  add1.C_out(C_out);
  add1.S(S);
  
  stimuli1.clk(clk);
  stimuli1.A(A);
  stimuli1.B(B);
  stimuli1.C_in(C_in);
  
  // Waves:
  tf = sc_create_vcd_trace_file("waves");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, clk, "clk");
  sc_trace(tf,A,"A");
  sc_trace(tf,B,"B");
  sc_trace(tf,C_in,"C_in");
  sc_trace(tf,S,"S");
  sc_trace(tf,C_out,"C_out");
  sc_start(500, SC_NS);
  sc_close_vcd_trace_file(tf);
  return 0;
}
