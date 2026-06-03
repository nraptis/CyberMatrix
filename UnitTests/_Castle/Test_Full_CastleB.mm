//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_CastleB : XCTestCase

@end

@implementation Test_Full_CastleB

- (void)testFull_CastleB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleB_4x4();

    const M aExpected = {
        { 34, 35, 32, 33, 16, 17, 18, 19 },
        { 42, 43, 40, 41, 24, 25, 26, 27 },
        { 50, 51,  6,  7, 54, 55,  2,  3 },
        { 58, 59, 14, 15, 62, 63, 10, 11 },
        { 52, 53,  0,  1, 48, 49,  4,  5 },
        { 60, 61,  8,  9, 56, 57, 12, 13 },
        { 36, 37, 38, 39, 22, 23, 20, 21 },
        { 44, 45, 46, 47, 30, 31, 28, 29 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_CastleB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleB_EachQuad_4x4();

    const M aExpected = {
        { 17, 16,  8,  9, 21, 20, 12, 13 },
        { 25,  3, 27,  1, 29,  7, 31,  5 },
        { 26,  0, 24,  2, 30,  4, 28,  6 },
        { 18, 19, 11, 10, 22, 23, 15, 14 },
        { 49, 48, 40, 41, 53, 52, 44, 45 },
        { 57, 35, 59, 33, 61, 39, 63, 37 },
        { 58, 32, 56, 34, 62, 36, 60, 38 },
        { 50, 51, 43, 42, 54, 55, 47, 46 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
