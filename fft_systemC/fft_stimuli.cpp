#include <systemc.h>
#include "fft_stimuli.h"

void Fft_stimuli::Stim(){
  wait();
  Enable = 0;
  wait();
  Enable = 1;
  wait(16);
};
