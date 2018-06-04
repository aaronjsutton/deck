#include "munit/munit.h"

static MunitResult
test_create(const MunitParameter params[], void* data) {
  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  { (char*) "/create", test_create, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
    (char*) "/deck/tests",
    test_suite_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
  };

#include <stdlib.h>

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}
