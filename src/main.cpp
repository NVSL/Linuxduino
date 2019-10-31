/*
  main.cpp - Arduino main function
  (You can inlcude multiple Arduino.h headers if you use
   this folder, but you can't inlcude LinuxDuino.h)

  Copyright (c) 2016 Jorge Garza <jgarzagu@ucsd.edu>
*/

#include "Arduino.h"

int main(void)
{ 
  setup();
    
  for (;;) {
    loop();
  }
        
  return 0;
}