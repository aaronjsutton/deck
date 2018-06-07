//
//  main.c
//  debug
//
//  Created by Aaron Sutton on 6/5/18.
//

#include <stdio.h>
#include "../src/deck.h"
#include "../src/shuffle.h"

int main(int argc, const char * argv[]) {
	// insert code here...
  deck *d, *c;
  d = deck_alloc();
  c = deck_alloc();

  deck_fill(d);
  for (int i = 0; i <= 3; i++) {
    deck_riffle_shuffle(d);
  }
  deck_free(d);
  deck_free(c);
	return 0;
}

