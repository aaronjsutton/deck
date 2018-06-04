#include "munit/munit.h"
#include "../src/deck.h"


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
  deck_fill(d);
  return MUNIT_OK;
}


/****************************************/
/*              Test Lists              */
/****************************************/

static MunitTest test_suite_tests[] = {
  { (char*) "/create", test_create, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/fill", test_fill, setup_deck, teardown_deck, MUNIT_TEST_OPTION_NONE, NULL },
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
