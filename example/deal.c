//
//  main.c
//  example
//
//  Created by Aaron Sutton on 6/5/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "../src/deck.h"
#include "../src/shuffle.h"

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

    // Strings to describe the card.
    char *suit_str, *rank_str;

    switch (c->suit) {      case clubs:
        suit_str = "clubs";
        break;
      case diamonds:
        suit_str = "diamonds";
        break;
      case spades:
        suit_str = "spades";
        break;
      case hearts:
        suit_str = "hearts";
        break;
      default:
        break;
    }

    switch (c->rank) {
      case RANK_ACE:
        rank_str = "Ace";
        break;
      case RANK_JACK:
        rank_str = "Jack";
        break;
      case RANK_QUEEN:
        rank_str = "Queen";
        break;
      case RANK_KING:
        rank_str = "King";
        break;
      default:
        rank_str = malloc(sizeof(char) * 2);
        sprintf(rank_str, "%i", c->rank);
        break;
    }

    // Print out which card we dealt.
    printf("You dealt the %s of %s \n", rank_str, suit_str);
  }

  // Clean up and exit.
  deck_free(p);
  return 0;
}

