#include "add1.h"
#include "add1_stimuli.h"
#define ADDR_SIZE = 8
#define WORD_SIZE = 16

SC_MODULE (Top) {
  // signals
 
  sc_clock clk;
  sc_signal<bool> reset;
  sc_signal<bool> data_enable;
  sc_signal<bool> write_enable;
  sc_signal<sc_int<ADDR_SIZE>> address;
  sc_signal<sc_int<WORD_SIZE>> data;

  // instanciate
  Ram ram;
  Ram_stimuli stimuli;

  void INIT();
 SC_CTOR(Top)
   : clk("clk", 2, SC_NS, 0.5),
    data_enable ("data_enable"),
    write_enable ("write_enable"),
    reset ("reset"),
    address ("address"),
    data ("data"),
    ram ("ram"),
    stimuli("stimuli")
      {
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
	stimuli.data(data)
	  }
};
