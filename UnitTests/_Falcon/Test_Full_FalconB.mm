//
//  Test_Full_FalconB.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_FalconB : XCTestCase

@end

@implementation Test_Full_FalconB

- (void)testFull_FalconB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconB_4x4();

    const M aExpected = {
        { 50, 51, 34, 35, 18, 19,  2,  3 },
        { 58, 59, 42, 43, 26, 27, 10, 11 },
        { 48, 49, 32, 33, 20, 21,  4,  5 },
        { 56, 57, 40, 41, 28, 29, 12, 13 },
        { 54, 55, 38, 39, 22, 23,  6,  7 },
        { 62, 63, 46, 47, 30, 31, 14, 15 },
        { 52, 53, 36, 37, 16, 17,  0,  1 },
        { 60, 61, 44, 45, 24, 25,  8,  9 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FalconB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconB_EachQuad_4x4();

    const M aExpected = {
        { 25, 17,  9,  1, 29, 21, 13,  5 },
        { 24, 16, 10,  2, 28, 20, 14,  6 },
        { 27, 19, 11,  3, 31, 23, 15,  7 },
        { 26, 18,  8,  0, 30, 22, 12,  4 },
        { 57, 49, 41, 33, 61, 53, 45, 37 },
        { 56, 48, 42, 34, 60, 52, 46, 38 },
        { 59, 51, 43, 35, 63, 55, 47, 39 },
        { 58, 50, 40, 32, 62, 54, 44, 36 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FalconB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconB_8x8();

    const M aExpected = {
        { 57, 49, 41, 33, 25, 17,  9,  1 },
        { 56, 48, 40, 32, 26, 18, 10,  2 },
        { 59, 51, 43, 35, 27, 19, 11,  3 },
        { 58, 50, 42, 34, 28, 20, 12,  4 },
        { 61, 53, 45, 37, 29, 21, 13,  5 },
        { 60, 52, 44, 36, 30, 22, 14,  6 },
        { 63, 55, 47, 39, 31, 23, 15,  7 },
        { 62, 54, 46, 38, 24, 16,  8,  0 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
