/**
 * @file shuffle.c
 * Functions for shuffling decks of cards.
 *
 * Copyright © 2018, Aaron Sutton <aaronjsutton@icloud.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuffle.h"

/**
 Shuffle a deck using an algorithm that mimics a
 riffle shuffle.

 @param d The deck to shuffle.
 */
void deck_riffle_shuffle(deck *d) {
  int i;
  deck *copy, *cut, *s;
  copy = deck_alloc();
  memcpy(copy->cards, d->cards, sizeof(card) * d->total);
  copy->total = d->total;

  cut = deck_alloc();
  cut = deck_cut(copy);

  s = deck_alloc();
  for (i = 0; i < copy->total; i++) {
    deck_add(s, &copy->cards[i]);
    deck_add(s, &cut->cards[i]);
  }
  memcpy(d->cards, s->cards, sizeof(card) * s->total);

}

