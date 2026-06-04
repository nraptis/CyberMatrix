//
//  Test_Full_YorkD.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_YorkD : XCTestCase

@end

@implementation Test_Full_YorkD

- (void)testFull_YorkD_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_YorkD_4x4();

    const M aExpected = {
        { 32, 33,  4,  5, 18, 19, 54, 55 },
        { 40, 41, 12, 13, 26, 27, 62, 63 },
        { 48, 49, 20, 21,  2,  3, 38, 39 },
        { 56, 57, 28, 29, 10, 11, 46, 47 },
        { 34, 35, 52, 53, 16, 17,  6,  7 },
        { 42, 43, 60, 61, 24, 25, 14, 15 },
        { 50, 51, 36, 37,  0,  1, 22, 23 },
        { 58, 59, 44, 45,  8,  9, 30, 31 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_YorkD_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_YorkD_EachQuad_4x4();

    const M aExpected = {
        { 16,  2,  9, 27, 20,  6, 13, 31 },
        { 24, 10,  1, 19, 28, 14,  5, 23 },
        { 17, 26,  8,  3, 21, 30, 12,  7 },
        { 25, 18,  0, 11, 29, 22,  4, 15 },
        { 48, 34, 41, 59, 52, 38, 45, 63 },
        { 56, 42, 33, 51, 60, 46, 37, 55 },
        { 49, 58, 40, 35, 53, 62, 44, 39 },
        { 57, 50, 32, 43, 61, 54, 36, 47 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_YorkD_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_YorkD_8x8();

    const M aExpected = {
        { 40, 60, 42, 12, 26, 14, 24, 62 },
        { 41, 61, 43, 13, 27, 15, 25, 63 },
        { 56, 44, 58, 28, 10, 30,  8, 46 },
        { 57, 45, 59, 29, 11, 31,  9, 47 },
        { 32, 54, 34, 52, 18,  4, 16,  6 },
        { 33, 55, 35, 53, 19,  5, 17,  7 },
        { 48, 38, 50, 36,  2, 20,  0, 22 },
        { 49, 39, 51, 37,  3, 21,  1, 23 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
