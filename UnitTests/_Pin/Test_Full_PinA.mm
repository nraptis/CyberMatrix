//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_PinA : XCTestCase

@end

@implementation Test_Full_PinA

- (void)testFull_PinA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PinA_8x8();

    const M aExpected = {
        { 56, 48, 40, 32, 24, 16,  8,  0 },
        { 57, 14, 22, 30, 38, 46, 54,  1 },
        { 58, 13, 42, 34, 26, 18, 53,  2 },
        { 59, 12, 43, 28, 36, 19, 52,  3 },
        { 60, 11, 44, 27, 35, 20, 51,  4 },
        { 61, 10, 45, 37, 29, 21, 50,  5 },
        { 62,  9, 17, 25, 33, 41, 49,  6 },
        { 63, 55, 47, 39, 31, 23, 15,  7 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_PinA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PinA_4x4();

    const M aExpected = {
        { 48, 49, 32, 33, 16, 17,  0,  1 },
        { 56, 57, 40, 41, 24, 25,  8,  9 },
        { 50, 51, 20, 21, 36, 37,  2,  3 },
        { 58, 59, 28, 29, 44, 45, 10, 11 },
        { 52, 53, 18, 19, 34, 35,  4,  5 },
        { 60, 61, 26, 27, 42, 43, 12, 13 },
        { 54, 55, 38, 39, 22, 23,  6,  7 },
        { 62, 63, 46, 47, 30, 31, 14, 15 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_PinA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PinA_EachQuad_4x4();

    const M aExpected = {
        { 24, 16,  8,  0, 28, 20, 12,  4 },
        { 25, 10, 18,  1, 29, 14, 22,  5 },
        { 26,  9, 17,  2, 30, 13, 21,  6 },
        { 27, 19, 11,  3, 31, 23, 15,  7 },
        { 56, 48, 40, 32, 60, 52, 44, 36 },
        { 57, 42, 50, 33, 61, 46, 54, 37 },
        { 58, 41, 49, 34, 62, 45, 53, 38 },
        { 59, 51, 43, 35, 63, 55, 47, 39 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
