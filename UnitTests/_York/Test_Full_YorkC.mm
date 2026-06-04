//
//  Test_Full_YorkC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_YorkC : XCTestCase

@end

@implementation Test_Full_YorkC

- (void)testFull_YorkC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_YorkC_4x4();

    const M aExpected = {
        { 52, 53, 34, 35,  6,  7, 16, 17 },
        { 60, 61, 42, 43, 14, 15, 24, 25 },
        { 36, 37, 50, 51, 22, 23,  0,  1 },
        { 44, 45, 58, 59, 30, 31,  8,  9 },
        { 54, 55, 18, 19,  4,  5, 32, 33 },
        { 62, 63, 26, 27, 12, 13, 40, 41 },
        { 38, 39,  2,  3, 20, 21, 48, 49 },
        { 46, 47, 10, 11, 28, 29, 56, 57 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_YorkC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_YorkC_EachQuad_4x4();

    const M aExpected = {
        { 26, 17,  3,  8, 30, 21,  7, 12 },
        { 18, 25, 11,  0, 22, 29, 15,  4 },
        { 27,  9,  2, 16, 31, 13,  6, 20 },
        { 19,  1, 10, 24, 23,  5, 14, 28 },
        { 58, 49, 35, 40, 62, 53, 39, 44 },
        { 50, 57, 43, 32, 54, 61, 47, 36 },
        { 59, 41, 34, 48, 63, 45, 38, 52 },
        { 51, 33, 42, 56, 55, 37, 46, 60 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_YorkC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_YorkC_8x8();

    const M aExpected = {
        { 54, 32, 52, 34,  4, 18,  6, 16 },
        { 55, 33, 53, 35,  5, 19,  7, 17 },
        { 38, 48, 36, 50, 20,  2, 22,  0 },
        { 39, 49, 37, 51, 21,  3, 23,  1 },
        { 62, 42, 60, 26, 12, 24, 14, 40 },
        { 63, 43, 61, 27, 13, 25, 15, 41 },
        { 46, 58, 44, 10, 28,  8, 30, 56 },
        { 47, 59, 45, 11, 29,  9, 31, 57 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
