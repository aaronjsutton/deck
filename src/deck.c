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
  * Allocate a new deck.
  *
  * @returns Pointer to the newly allocated deck.
  */
deck *deck_alloc() {
  return malloc(sizeof(deck));
}

/**
  * Free a deck pointer.
  *
  * @param[in] d    The pointer to deinitialize and free.
  */
void deck_free(deck *d) {
  free(d);
}

/**
  * Fill a deck with cards.
  * Populates a `deck` with card values from
  * a standard 52-card deck.
  *
  * @param[in,out] d The deck to fill with cards.
  */
void deck_fill(deck *d) {
  
}
