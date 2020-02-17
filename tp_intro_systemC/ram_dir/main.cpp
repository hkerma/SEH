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
#include "ram.h"
#include "ram_stimuli.h"


int sc_main(int ac, char *av[])
{
  sc_trace_file *tf;
  // signals
  sc_signal<bool> reset;
  sc_signal<bool> data_enable;
  sc_signal<bool> write_enable;
  sc_clock clk;

  sc_signal<sc_int<ADDR_SIZE>> address;
  sc_signal<sc_int<WORD_SIZE>> data;
  
  // instanciate
  Ram ram("ram");
  Stimuli stimuli("stimuli");
  sc_clock clk ("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
  // link
  ram.reset(reset);
  ram.data_enable(data_enable);
  ram.write_enable(write_enable);
  ram.clk(clk);
  ram.address(address);
  ram.data(data);
  
  stimuli.clk(clk);
  stimuli.reset(reset);
  stimuli.data_enable(data_enable);
  stimuli.write_enable(write_enable);
  stimuli.address(address);
  stimuli.data(data);
  
  // Waves:
  tf = sc_create_vcd_trace_file("waves");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, clk, "clk");
  sc_trace(tf,reset,"reset");
  sc_trace(tf,address,"address");
  sc_trace(tf,data,"data");
  sc_trace(tf,write_enable,"write_enable");
  sc_trace(tf,data_enable,"data_enable");
  sc_start(500, SC_NS);
  sc_close_vcd_trace_file(tf);
  return 0;
}
