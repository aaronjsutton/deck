/**
 * deck.c
 * @file A library for handing the construction and manipulation
 * of a simulated deck of cards.
 *
 * Copyright © 2018, Aaron Sutton <aaronjsutton@icloud.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 Allocate a new deck.

 @return Pointer to a newly allocated deck.
 */
deck *deck_alloc() {
  return malloc(sizeof(deck));
}

/**
 Free a deck pointer.

 @param d The pointer to be freed.
 */
void deck_free(deck *d) {
  free(d);
}

/**
 Fill a deck with cards.
 Fills a `deck` with a standard 52-card set.

 @param d Pointer of the deck to fill.
 */
void deck_fill(deck *d) {
  int s, r;
  d->total = 0;
  for (s = clubs; s <= spades; s++) {
    for (r = RANK_ACE; r <= RANK_KING; r++) {
      card c = {s, r};
      d->cards[d->total++] = c;
    }
  }
}
