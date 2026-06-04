//
//  Test_Full_GooseB.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_GooseB : XCTestCase

@end

@implementation Test_Full_GooseB

- (void)testFull_GooseB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_GooseB_4x4();

    const M aExpected = {
        { 18, 19,  2,  3, 50, 51, 34, 35 },
        { 26, 27, 10, 11, 58, 59, 42, 43 },
        { 20, 21,  4,  5, 52, 53, 36, 37 },
        { 28, 29, 12, 13, 60, 61, 44, 45 },
        { 22, 23,  6,  7, 54, 55, 38, 39 },
        { 30, 31, 14, 15, 62, 63, 46, 47 },
        { 16, 17,  0,  1, 48, 49, 32, 33 },
        { 24, 25,  8,  9, 56, 57, 40, 41 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_GooseB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_GooseB_EachQuad_4x4();

    const M aExpected = {
        {  9,  1, 25, 17, 13,  5, 29, 21 },
        { 10,  2, 26, 18, 14,  6, 30, 22 },
        { 11,  3, 27, 19, 15,  7, 31, 23 },
        {  8,  0, 24, 16, 12,  4, 28, 20 },
        { 41, 33, 57, 49, 45, 37, 61, 53 },
        { 42, 34, 58, 50, 46, 38, 62, 54 },
        { 43, 35, 59, 51, 47, 39, 63, 55 },
        { 40, 32, 56, 48, 44, 36, 60, 52 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_GooseB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_GooseB_8x8();

    const M aExpected = {
        { 25, 17,  9,  1, 57, 49, 41, 33 },
        { 26, 18, 10,  2, 58, 50, 42, 34 },
        { 27, 19, 11,  3, 59, 51, 43, 35 },
        { 28, 20, 12,  4, 60, 52, 44, 36 },
        { 29, 21, 13,  5, 61, 53, 45, 37 },
        { 30, 22, 14,  6, 62, 54, 46, 38 },
        { 31, 23, 15,  7, 63, 55, 47, 39 },
        { 24, 16,  8,  0, 56, 48, 40, 32 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
