#pragma once
#include <iostream>

void dummy() {
  int* x = new int;
  int val = 1;      // FIX 1: Initialize the variable

  if (val > 0) {
    *x = 5;
  }

  delete x;         // FIX 2: Free the memory
}
