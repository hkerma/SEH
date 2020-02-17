#include <systemc.h>
#include "ff_stimuli.h"

void Ff_stimuli::Stim()
{
  wait();
  s1 = 1;
  wait();
  wait();
  s1 = 0;
  wait(1);
  wait();
  s1 = 1;
  wait();
  wait();
  s1 = 0;
  wait(8);
};
 
