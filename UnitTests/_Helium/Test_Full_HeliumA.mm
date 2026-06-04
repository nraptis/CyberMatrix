//
//  Test_Full_HeliumA.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_HeliumA : XCTestCase

@end

@implementation Test_Full_HeliumA

- (void)testFull_HeliumA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeliumA_4x4();

    const M aExpected = {
        { 52, 53, 54, 55,  6,  7,  4,  5 },
        { 60, 61, 62, 63, 14, 15, 12, 13 },
        { 36, 37, 38, 39, 22, 23, 20, 21 },
        { 44, 45, 46, 47, 30, 31, 28, 29 },
        { 34, 35, 32, 33, 16, 17, 18, 19 },
        { 42, 43, 40, 41, 24, 25, 26, 27 },
        { 50, 51, 48, 49,  0,  1,  2,  3 },
        { 58, 59, 56, 57,  8,  9, 10, 11 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeliumA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeliumA_EachQuad_4x4();

    const M aExpected = {
        { 26, 27,  3,  2, 30, 31,  7,  6 },
        { 18, 19, 11, 10, 22, 23, 15, 14 },
        { 17, 16,  8,  9, 21, 20, 12, 13 },
        { 25, 24,  0,  1, 29, 28,  4,  5 },
        { 58, 59, 35, 34, 62, 63, 39, 38 },
        { 50, 51, 43, 42, 54, 55, 47, 46 },
        { 49, 48, 40, 41, 53, 52, 44, 45 },
        { 57, 56, 32, 33, 61, 60, 36, 37 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeliumA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeliumA_8x8();

    const M aExpected = {
        { 60, 52, 62, 54, 14,  6, 12,  4 },
        { 61, 53, 63, 55, 15,  7, 13,  5 },
        { 44, 36, 46, 38, 30, 22, 28, 20 },
        { 45, 37, 47, 39, 31, 23, 29, 21 },
        { 42, 34, 40, 32, 24, 16, 26, 18 },
        { 43, 35, 41, 33, 25, 17, 27, 19 },
        { 58, 50, 56, 48,  8,  0, 10,  2 },
        { 59, 51, 57, 49,  9,  1, 11,  3 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
