/**
 * @file deck.c
 * A library for handing the construction and manipulation
 * of a simulated deck of cards.
 *
 * Copyright © 2018, Aaron Sutton <aaronjsutton@icloud.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "deck.h"
/**
 Allocate a new deck.

 @return Pointer to a newly allocated deck.
 */
deck *deck_alloc() {
  deck *d = malloc(sizeof(deck));
  d->cards = malloc(sizeof(card) * DECK_MAX_SIZE);
  d->total = 0;
  return d;
}

/**
 Free a deck pointer.

 @param d The pointer to be freed.
 */
void deck_free(deck *d) {
  free(d);
}

static
void deck_resize(deck *d, int cards) {
  d->cards = (card*)realloc(d->cards, sizeof(card) * cards);
  if (d->cards == NULL) {
    exit(1);
  }
}

/**
 Fill a deck with cards.
 Fills a `deck` with a standard 52-card set.

 @param d Pointer of the deck to fill.
 */
void deck_fill(deck *d) {
  int s, r;
  for (s = clubs; s <= spades; s++) {
    for (r = RANK_ACE; r <= RANK_KING; r++) {
      card c = {s, r};
      d->cards[d->total++] = c;
    }
  }
}

/**
 Add a card to a deck.

 @param d The deck to add to.
 @param c The card to be added to `d`.
 */
void deck_add(deck *d, card *c) {
  d->total++;
  deck_resize(d, d->total);
  d->cards[d->total - 1] = *c;
}

/**
 Cuts a deck in half.

 @note It is the caller's responsibility to free the returned
 deck pointer.

 @param o The deck to cut. This deck is modified in place.
 @return The cut-off half of the original deck.
 */
deck *deck_cut(deck *o) {
  deck *n;
  int c, i;

  n = deck_alloc();

  c = o->total / 2;
  for (i = 0; i <= c; i++) {
    n->cards[i] = o->cards[i];
  }
  for (i = c; i < o->total; i++) {
    o->cards[i - c] = o->cards[i];
    o->cards[i] = (card){0, 0};
  }
  deck_resize(o, c);
  o->total = c;
  n->total = c;
  return n;
}

/**
 Pick a card from the top of the deck.
 This method does remove the returned card from the deck.

 @param d The deck to pick from.
 @return The selected card.
 */
card *deck_pick(deck *d) {
  return &(d->cards[d->total - 1]);
}

/**
 Pick a random card from the deck.
 This method does remove the returned card from the deck.

 @param d The deck to pick from.
 @return The selected card.
 */
card *deck_pick_rand(deck *d) {
  int r;
  srand((unsigned int)time(0));
  r = rand() % d->total - 1;
  return &(d->cards[r]);
}

/**
 Draw a card from the deck.
 This method removes the card from the deck.

 @param d The deck to draw from.
 @return The drawn card.
 */
card *deck_draw(deck *d) {
  static card c;
  c = d->cards[--d->total];
  deck_resize(d, d->total);
  return &c;
}

/**
 Draw a random card from the deck.
 This method removes the drawn card from the deck.

 @param d The deck to draw from.
 @return The drawn card.
 */
card *deck_draw_rand(deck *d) {
  static card c;
  int i, r;
  srand((unsigned int)time(0));
  r = rand() %  d->total - 1;
  c = d->cards[r];
  d->total--;
  for (i = r; i < d->total; i++) {
    d->cards[i] = d->cards[i + 1];
  }
  deck_resize(d, d->total);
  return &c;
}

static
char *suit_str(card *c) {
  static char suit[7];

  switch (c->rank) {
      case RANK_ACE:
      sprintf(suit, "Ace");
      break;
      case RANK_JACK:
      sprintf(suit, "Jack");
      break;
      case RANK_QUEEN:
      sprintf(suit, "Queen");
      break;
      case RANK_KING:
      sprintf(suit, "King");
      break;
    default:
      sprintf(suit, "%d", c->rank);
  }

  return suit;
}

/**
 Returns a string that is an ASCII-readable description of the
 card. For example, "Ace of spades", "7 of hearts".
 @since 0.2.0

 @warning The string is stored as static data, therefore it is overwritten
 with every call.

 @param c The card to describe.
 @return The ASCII string describing it.
 */
char *card_ascii(card *c) {
  static char desc[CARD_DESC_MAX_BYTES];

  char *suit = suit_str(c);

  sprintf(desc, "%s of ", suit);

  switch (c->suit) {
      case clubs:
      sprintf(desc, "%sclubs", desc);
      break;
      case hearts:
      sprintf(desc, "%shearts", desc);
      break;
      case diamonds:
      sprintf(desc, "%sdiamonds", desc);
      break;
      case spades:
      sprintf(desc, "%sspades", desc);
      break;
    default:
      break;
  }

  return desc;
}

/**
 Returns a string that is a description of the
 card. This string contains Unicode code points.
 For example, "♠ Ace", "♥ 7".
 @since 0.2.0

 @warning The string is stored as static data, therefore it is overwritten
 with every call.
 @param c The card to describe.
 @return The string descring the card.
 */
char *card_unicode(card *c) {
  static char desc[CARD_DESC_MAX_BYTES];

  char *suit = suit_str(c);

  switch (c->suit) {
      case clubs:
      sprintf(desc, "\u2663");
      break;
      case hearts:
      sprintf(desc, "\u2665");
      break;
      case diamonds:
      sprintf(desc, "\u2666");
      break;
      case spades:
      sprintf(desc, "\u2660");
      break;
    default:
      break;
  }

  sprintf(desc, "%s %s", desc, suit);

  return desc;
}
