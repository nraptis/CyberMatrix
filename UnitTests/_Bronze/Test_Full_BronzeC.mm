//
//  Test_Full_BronzeC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_BronzeC : XCTestCase

@end

@implementation Test_Full_BronzeC

- (void)testFull_BronzeC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_BronzeC_4x4();

    const M aExpected = {
        { 32, 33,  0,  1, 36, 37,  4,  5 },
        { 40, 41,  8,  9, 44, 45, 12, 13 },
        { 50, 51, 18, 19, 54, 55, 22, 23 },
        { 58, 59, 26, 27, 62, 63, 30, 31 },
        { 34, 35,  6,  7, 38, 39,  2,  3 },
        { 42, 43, 14, 15, 46, 47, 10, 11 },
        { 52, 53, 16, 17, 48, 49, 20, 21 },
        { 60, 61, 24, 25, 56, 57, 28, 29 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_BronzeC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_BronzeC_EachQuad_4x4();

    const M aExpected = {
        { 16,  0, 18,  2, 20,  4, 22,  6 },
        { 25,  9, 27, 11, 29, 13, 31, 15 },
        { 17,  3, 19,  1, 21,  7, 23,  5 },
        { 26,  8, 24, 10, 30, 12, 28, 14 },
        { 48, 32, 50, 34, 52, 36, 54, 38 },
        { 57, 41, 59, 43, 61, 45, 63, 47 },
        { 49, 35, 51, 33, 53, 39, 55, 37 },
        { 58, 40, 56, 42, 62, 44, 60, 46 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_BronzeC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_BronzeC_8x8();

    const M aExpected = {
        { 34,  2, 32,  0, 38,  6, 36,  4 },
        { 44, 12, 42, 10, 40,  8, 46, 14 },
        { 50, 18, 48, 16, 54, 22, 52, 20 },
        { 60, 28, 58, 26, 56, 24, 62, 30 },
        { 35,  1, 33,  7, 39,  5, 37,  3 },
        { 45, 11, 43,  9, 41, 15, 47, 13 },
        { 51, 17, 49, 23, 55, 21, 53, 19 },
        { 61, 27, 59, 25, 57, 31, 63, 29 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
