/**
 * @file shuffle.c
 * Functions for shuffling decks of cards.
 *
 * Copyright © 2018, Aaron Sutton <aaronjsutton@icloud.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "shuffle.h"

/**
 Shuffle a deck using an algorithm that mimics a
 riffle shuffle.

 @note For best results on an un-shuffled deck,
 call this function multiple times.

 @param d The deck to shuffle.
 */
void deck_riffle_shuffle(deck *d) {
  int i, r;
  deck *copy, *cut, *s;
  copy = deck_alloc();
  memcpy(copy->cards, d->cards, sizeof(card) * d->total);
  copy->total = d->total;

  cut = deck_alloc();
  cut = deck_cut(copy);

  s = deck_alloc();
  srand((unsigned int)time(0));
  r = rand() % 2 == 0;
  for (i = 0; i < copy->total; i++) {
    if (r) {
      deck_add(s, &copy->cards[i]);
      deck_add(s, &cut->cards[i]);
    } else {
      deck_add(s, &cut->cards[i]);
      deck_add(s, &copy->cards[i]);
    }
  }
  memcpy(d->cards, s->cards, sizeof(card) * s->total);

}


/**
Shuffle the cards using the Fisher-Yates algorithm.

 @param d The deck to shuffle.
 */
void deck_fisher_yates_shuffle(deck *d) {
  int i, r;
  srand((unsigned int)time(0));
  for (i = d->total - 1; i >= 1; i--) {
    r = rand() % i;
    card *tmp = malloc(sizeof(card));
    memcpy(tmp, &d->cards[i], sizeof(card));
    d->cards[i] = d->cards[r];
    d->cards[r] = *tmp;
  }
}
