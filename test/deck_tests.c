#include "munit/munit.h"
#include "../src/deck.h"
#include "../src/shuffle.h"
#include "test-bridge.h"

/****************************************/
/*            Setup/Teardown            */
/****************************************/


static void *setup_deck(const MunitParameter params[], void *data) {
  return deck_alloc();
}

static void teardown_deck(void *fixture) {
  deck_free((deck*)fixture);
}

/****************************************/
/*                Tests                 */
/****************************************/

static MunitResult
test_create(const MunitParameter params[], void* data) {
  deck *d;
  d = deck_alloc();
  munit_assert_not_null(d);
  deck_free(d);
  return MUNIT_OK;
}

static MunitResult
test_fill(const MunitParameter params[], void *fixture) {
  deck *d = (deck*) fixture;
  int s, r;
  deck_fill(d);
  int i = 0;
  for (s = clubs; s <= spades; s++) {
    for (r = RANK_ACE; r <= RANK_KING; r++) {
      munit_assert_int(d->cards[i].suit, ==, s);
      munit_assert_int(d->cards[i].rank, ==, r);
      i++;
    }
  }

  card c = {clubs, RANK_ACE};
  deck_add(d, &c);
  munit_assert_int(d->cards[52].suit, ==, clubs);

  return MUNIT_OK;
}

static MunitResult
test_cut(const MunitParameter params[], void *fixture) {
  deck *d = (deck*) fixture;
  int s, r;
  deck_fill(d);
  deck *n;
  n = deck_cut(d);

  munit_assert_int(d->total, ==, n->total);

  int i = 0;
  for (s = hearts; s <= spades; s++) {
    for (r = RANK_ACE; r <= RANK_KING; r++) {
      munit_assert_int(d->cards[i].suit, ==, s);
      munit_assert_int(d->cards[i].rank, ==, r);
      i++;
    }
  }

  i = 0;
  for (s = clubs; s <= diamonds; s++) {
    for (r = RANK_ACE; r <= RANK_KING; r++) {
      munit_assert_int(n->cards[i].suit, ==, s);
      munit_assert_int(n->cards[i].rank, ==, r);
      i++;
    }
  }
  deck_free(n);
  return MUNIT_OK;
}

static MunitResult
test_pick(const MunitParameter params[], void *fixture) {
  deck *d = (deck*) fixture;
  deck_fill(d);
  card *c = deck_pick(d);
  munit_assert_int(c->rank, ==, RANK_KING);
  c = deck_pick_rand(d);
  munit_assert_not_null(c);
  return MUNIT_OK;
}

static MunitResult
test_draw(const MunitParameter params[], void *fixture) {
  deck *d = (deck*) fixture;
  deck_fill(d);
  card *c = deck_draw(d);
  munit_assert_int(c->rank, ==, RANK_KING);
  munit_assert_int(d->total, ==, 51);
  c = deck_draw(d);
  munit_assert_int(c->rank, ==, RANK_QUEEN);
  munit_assert_int(d->total, ==, 50);
  c = deck_draw_rand(d);
  munit_assert_not_null(c);
  munit_assert_int(d->total, ==, 49);
  return MUNIT_OK;
}

static MunitResult
test_shuffle(const MunitParameter params[], void *fixture) {
  deck *d = (deck*) fixture;
  deck_fill(d);
  deck_riffle_shuffle(d);
  munit_assert_not_null(d);
  deck_fisher_yates_shuffle(d);
  munit_assert_not_null(d);
  return MUNIT_OK;
}

static MunitResult
test_print(const MunitParameter params[], void *fixture) {
  card c = {spades, RANK_ACE};
  card h = {hearts, RANK_QUEEN};

  char *str = card_ascii(&c);
  munit_assert_string_equal(str, "Ace of spades");
  char *uni = card_unicode(&h);
  munit_assert_string_equal(uni, "♥ Queen");
  return MUNIT_OK;
}

/****************************************/
/*              Test Lists              */
/****************************************/

static MunitTest test_suite_tests[] = {
  { (char*) "/create", test_create, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/fill", test_fill, setup_deck, teardown_deck, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/cut", test_cut, setup_deck, teardown_deck, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/pick", test_pick, setup_deck, teardown_deck, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/draw", test_draw, setup_deck, teardown_deck, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/shuffle", test_shuffle, setup_deck, teardown_deck, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/print", test_print, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/****************************************/
/*              Test Suite              */
/****************************************/

static const MunitSuite test_suite = {
    (char*) "/deck/tests",
    test_suite_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
  };

/****************************************/
/*                Runner                */
/****************************************/

#include <stdlib.h>

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}

int obcj_deck_tests() {
  return munit_suite_main(&test_suite, (void*) "µnit", 0, NULL);
}
