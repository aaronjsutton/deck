/**
 * @file deck.h
 * A library for handing the construction and manipulation
 * of a simulated deck of cards.
 *
 * Copyright © 2018, Aaron Sutton <aaronjsutton@icloud.com>
 */
#ifndef DECK
#define DECK

#define DECK_MAX_SIZE 52

#define RANK_ACE    1
#define RANK_JACK   11
#define RANK_QUEEN  12
#define RANK_KING   13

#define CARD_UNICODE_MAX_BYTES	5
#define CARD_ASCII_MAX_BYTES		20

typedef enum suit {
  clubs = 1,
  diamonds,
  hearts,
  spades
} suit_e;

/**
  * @brief A type representing a playing card.
  * A card can have the follwing rank:
  * - 1       Ace
  * - 2...10  Number value
  * - 11      Jack
  * - 12      Queen
  * - 13      King
  *
  * A card can have the follwing suits:
  * - Hearts
  * - Spades
  * - Clubs
  * - Diamonds
  *
  */
typedef struct card {
  suit_e suit;  /**< The suit of the card. Detailed in description. */
  int rank;     /**< Rank of the card. Detailed in description.     */
} card;

/**
 A deck of cards.
 */
typedef struct deck {
  card *cards;                 /**< An array of cards currently in the deck.           */
  int total;                   /**< The total number of cards in the deck.             */
} deck;

deck *deck_alloc(void);
void deck_fill(deck*);
void deck_free(deck*);
void deck_add(deck *d, card *c);

deck *deck_cut(deck*);
card *deck_pick(deck*);
card *deck_pick_rand(deck*);
card *deck_draw(deck*);
card *deck_draw_rand(deck*);

char *card_ascii(card *c);
char *card_unicode(card *c);

#endif
