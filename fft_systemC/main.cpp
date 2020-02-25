#include <systemc.h>
#include "global.h"
#include "fft.h"

int sc_main(int argc, char *argv[]){
  
  //Signal
  sc_signal<bool> signal_enable;
  
  //Instantiate
  Fft fft("fft");
  sc_clock Clk("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
  fft.Clk(Clk);

  //Waves
  sc_trace_file *tf = sc_create_vcd_trace_file("trace");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, Clk, "clk");
  
  sc_trace(tf, fft.In_re, "In_re");
  sc_trace(tf, fft.In_im, "In_im");
  sc_trace(tf, fft.Out_re, "Out_re");
  sc_trace(tf, fft.Out_im, "Out_im");

  sc_trace(tf, fft.In_data_valid, "In_data_valid");
  sc_trace(tf, fft.In_data_request, "In_data_request");
  sc_trace(tf, fft.Out_data_valid, "Out_data_valid");
  sc_trace(tf, fft.Out_data_request, "Out_data_request");
  
  sc_start(2000, SC_NS);
  cout << "Finished at " << sc_time_stamp() << "\n";
  sc_close_vcd_trace_file(tf);

  return 0;
}
