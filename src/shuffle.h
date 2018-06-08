/**
 * @file shuffle.h
 * Shuffling algorithms for a deck of cards.
 *
 * Copyright © 2018, Aaron Sutton <aaronjsutton@icloud.com>
 */

#include "deck.h"

#define RIFFLE_STACK_MAX	4

void deck_riffle_shuffle(deck*);
void fisher_yates(deck*);
