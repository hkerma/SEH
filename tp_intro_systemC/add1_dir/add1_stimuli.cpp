#include <systemc.h>
#include "add1_stimuli.h"

void Stimuli::Stim()
{
  A = 0;
  B = 0;
  C_in = 0;
  wait();
  A = 1;
  wait();
  B = 1;
  wait();
  C_in = 1;
  wait();
  A = 0;
  wait();
  A = 1;
  B = 0;
  wait();
  B = 1;
  wait(8);
};
 
