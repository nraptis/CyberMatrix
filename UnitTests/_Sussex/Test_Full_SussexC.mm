//
//  Test_Full_SussexC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_SussexC : XCTestCase

@end

@implementation Test_Full_SussexC

- (void)testFull_SussexC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SussexC_4x4();

    const M aExpected = {
        { 48, 49, 32, 33,  4,  5, 20, 21 },
        { 56, 57, 40, 41, 12, 13, 28, 29 },
        { 34, 35, 54, 55, 18, 19,  6,  7 },
        { 42, 43, 62, 63, 26, 27, 14, 15 },
        { 50, 51, 22, 23,  2,  3, 38, 39 },
        { 58, 59, 30, 31, 10, 11, 46, 47 },
        { 36, 37,  0,  1, 16, 17, 52, 53 },
        { 44, 45,  8,  9, 24, 25, 60, 61 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_SussexC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SussexC_EachQuad_4x4();

    const M aExpected = {
        { 24, 16,  2, 10, 28, 20,  6, 14 },
        { 17, 27,  9,  3, 21, 31, 13,  7 },
        { 25, 11,  1, 19, 29, 15,  5, 23 },
        { 18,  0,  8, 26, 22,  4, 12, 30 },
        { 56, 48, 34, 42, 60, 52, 38, 46 },
        { 49, 59, 41, 35, 53, 63, 45, 39 },
        { 57, 43, 33, 51, 61, 47, 37, 55 },
        { 50, 32, 40, 58, 54, 36, 44, 62 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_SussexC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SussexC_8x8();

    const M aExpected = {
        { 58, 44, 56, 46,  8, 30, 10, 28 },
        { 59, 45, 57, 47,  9, 31, 11, 29 },
        { 42, 60, 40, 62, 24, 14, 26, 12 },
        { 43, 61, 41, 63, 25, 15, 27, 13 },
        { 52, 32, 50, 16,  2, 22,  4, 38 },
        { 53, 33, 51, 17,  3, 23,  5, 39 },
        { 36, 48, 34,  0, 18,  6, 20, 54 },
        { 37, 49, 35,  1, 19,  7, 21, 55 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
