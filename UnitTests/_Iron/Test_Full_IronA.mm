//
//  Test_Full_IronA.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_IronA : XCTestCase

@end

@implementation Test_Full_IronA

- (void)testFull_IronA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_IronA_4x4();

    const M aExpected = {
        { 36, 37,  0,  1, 32, 33,  4,  5 },
        { 44, 45,  8,  9, 40, 41, 12, 13 },
        { 54, 55, 18, 19, 50, 51, 22, 23 },
        { 62, 63, 26, 27, 58, 59, 30, 31 },
        { 34, 35,  2,  3, 38, 39,  6,  7 },
        { 42, 43, 10, 11, 46, 47, 14, 15 },
        { 52, 53, 20, 21, 48, 49, 16, 17 },
        { 60, 61, 28, 29, 56, 57, 24, 25 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_IronA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_IronA_EachQuad_4x4();

    const M aExpected = {
        { 18,  0, 16,  2, 22,  4, 20,  6 },
        { 27,  9, 25, 11, 31, 13, 29, 15 },
        { 17,  1, 19,  3, 21,  5, 23,  7 },
        { 26, 10, 24,  8, 30, 14, 28, 12 },
        { 50, 32, 48, 34, 54, 36, 52, 38 },
        { 59, 41, 57, 43, 63, 45, 61, 47 },
        { 49, 33, 51, 35, 53, 37, 55, 39 },
        { 58, 42, 56, 40, 62, 46, 60, 44 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_IronA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_IronA_8x8();

    const M aExpected = {
        { 36,  2, 34,  0, 32,  6, 38,  4 },
        { 46, 12, 44, 10, 42,  8, 40, 14 },
        { 52, 18, 50, 16, 48, 22, 54, 20 },
        { 62, 28, 60, 26, 58, 24, 56, 30 },
        { 35,  3, 33,  1, 39,  7, 37,  5 },
        { 45, 13, 43, 11, 41,  9, 47, 15 },
        { 51, 19, 49, 17, 55, 23, 53, 21 },
        { 61, 29, 59, 27, 57, 25, 63, 31 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
