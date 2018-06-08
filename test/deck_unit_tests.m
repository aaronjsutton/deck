//
//  deck_unit_tests.m
//  deck-unit-tests
//
//  Created by Aaron Sutton on 6/5/18.
//

#import <XCTest/XCTest.h>
#import "test-bridge.h"
#import "munit/munit.h"
#import "../src/deck.h"

@interface deck_unit_tests : XCTestCase

@end

@implementation deck_unit_tests

/**
 µnit test wrapper for Xcode.
 */
- (void)testDeck {
  int res = obcj_deck_tests();
  XCTAssert(res == 0);
}


@end
