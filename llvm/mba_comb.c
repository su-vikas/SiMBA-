#include <stdint.h>

// 4554857727453019050*~(x|y) + 4554857727453019050*~(x|~y) +
// 13891886349992469251*~x, 3735936685*~x

// 4297347026588972322*(x^y) + 14149397050856466605*~(x&y) +
// 14149397050856466605*(x&y) + 4297347022853035637*~(x^y), 49374 +
// 3735936685*(x^y)


// Nop
// (((x ^ y) + 2 * (x & y)) - (4*(x&~y) - 2*~y - (x^y) + 2*~(x&~y)))

uint64_t mba(uint64_t x, uint64_t y) {
  // (x + y) * 49374 * (x + y) - (3735936685*~x)
  // 3735936685*~(x|y) + 3735936685*~(x|~y), 3735936685*~x
  return (49374 + 3735936685 * (x ^ y)) +
         (4554857727453019050 * ~(x | y) + 4554857727453019050 * ~(x | ~y) +
          13891886349992469251 * ~x) -
         (2 * ~(x | ~y) - (x ^ y) + 2 * x + (((x ^ y) + 2 * (x & y)) - (4*(x&~y) - 2*~y - (x^y) + 2*~(x&~y)))) *
             (18446744073709502242 * ~(x | ~y) +
              18446744073709502242 * (x | ~y)) *
             (2 * ~(x | ~y) - (x ^ y) + 2 * x) -
         (3735936685 * ~(x | y) + 3735936685 * ~(x | ~y)) + ((x ^ y) + 2 * (x & y));
}

uint64_t mba_keep(uint64_t x, uint64_t y) {
  // (x + y) * 49374 * (x + y) - (3735936685*~x)
  return (4297347026588972322 * (x ^ y) + 14149397050856466605 * ~(x & y) +
          14149397050856466605 * (x & y) + 4297347022853035637 * ~(x ^ y)) +
         (3735936685 * ~x) - (x + y) * 49374 * (x + y) - (3735936685 * ~x) + (x + y);
}