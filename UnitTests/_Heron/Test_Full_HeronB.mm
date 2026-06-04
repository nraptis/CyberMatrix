//
//  Test_Full_HeronB.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_HeronB : XCTestCase

@end

@implementation Test_Full_HeronB

- (void)testFull_HeronB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronB_4x4();

    const M aExpected = {
        { 54, 55, 38, 39, 18, 19,  2,  3 },
        { 62, 63, 46, 47, 26, 27, 10, 11 },
        { 52, 53, 36, 37, 16, 17,  0,  1 },
        { 60, 61, 44, 45, 24, 25,  8,  9 },
        { 50, 51, 34, 35, 22, 23,  6,  7 },
        { 58, 59, 42, 43, 30, 31, 14, 15 },
        { 48, 49, 32, 33, 20, 21,  4,  5 },
        { 56, 57, 40, 41, 28, 29, 12, 13 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeronB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronB_EachQuad_4x4();

    const M aExpected = {
        { 27, 19,  9,  1, 31, 23, 13,  5 },
        { 26, 18,  8,  0, 30, 22, 12,  4 },
        { 25, 17, 11,  3, 29, 21, 15,  7 },
        { 24, 16, 10,  2, 28, 20, 14,  6 },
        { 59, 51, 41, 33, 63, 55, 45, 37 },
        { 58, 50, 40, 32, 62, 54, 44, 36 },
        { 57, 49, 43, 35, 61, 53, 47, 39 },
        { 56, 48, 42, 34, 60, 52, 46, 38 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeronB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronB_8x8();

    const M aExpected = {
        { 63, 55, 47, 39, 25, 17,  9,  1 },
        { 58, 50, 42, 34, 24, 16,  8,  0 },
        { 57, 49, 41, 33, 27, 19, 11,  3 },
        { 60, 52, 44, 36, 26, 18, 10,  2 },
        { 59, 51, 43, 35, 29, 21, 13,  5 },
        { 62, 54, 46, 38, 28, 20, 12,  4 },
        { 61, 53, 45, 37, 31, 23, 15,  7 },
        { 56, 48, 40, 32, 30, 22, 14,  6 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
