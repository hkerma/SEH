#include <systemc.h>
#include "fft.h"
#include "fft_stimuli.h"

int sc_main(int argc, char *argv[]){
  //Signal
  sc_signal<bool> signal_enable;
  
  //Instantiate
  Fft fft("fft");
  Fft_stimuli fft_stimuli("fft_stimuli");
  sc_clock Clk("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
  fft.Clk(Clk);
  fft.Enable(signal_enable);
  
  fft_stimuli.Clk(Clk);
  fft_stimuli.Enable(signal_enable);

  //Waves
  sc_trace_file *tf = sc_create_vcd_trace_file("trace");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, Clk, "clk");
  sc_trace(tf, signal_enable, "enable");
  fft.fifo_in->trace(tf);
  fft.fifo_out->trace(tf);
  sc_start(2000, SC_NS);
  cout << "Finished at " << sc_time_stamp() << "\n";
  sc_close_vcd_trace_file(tf);

  return 0;
}
