//
//  deal.c
//  example
//
//  Created by Aaron Sutton on 6/5/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "../src/deck.h"

int main(int argc, const char * argv[]) {
  // Allocate a new deck.
  deck *p;
  p = deck_alloc();
  // Fill the deck with the 52-card standard.
  deck_fill(p);
  // Shuffle the deck.
  for (int i = 0; i <= 3; i++) {
    deck_riffle_shuffle(p);
  }

  // Deal until our deck runs out of cards.
  while (p->total > 0) {
    // Draw a card from the top of the deck.
    card *c = deck_draw(p);

    // Get a printable string of the card.
    char *desc = card_unicode(c);

    // Print out which card we dealt.
    printf("You dealt %s \n", desc);
  }

  // Clean up and exit.
  deck_free(p);
  return 0;
}

