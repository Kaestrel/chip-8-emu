#include "chip.cpp"

int main() {

  Chip c(4096);
  c.execute(0xABCD);
  return 0;
}
