//
//  Test_Full_CobaltB.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_CobaltB : XCTestCase

@end

@implementation Test_Full_CobaltB

- (void)testFull_CobaltB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CobaltB_4x4();

    const M aExpected = {
        { 48, 49,  0,  1, 38, 39, 54, 55 },
        { 56, 57,  8,  9, 46, 47, 62, 63 },
        { 16, 17, 32, 33,  2,  3, 18, 19 },
        { 24, 25, 40, 41, 10, 11, 26, 27 },
        { 52, 53,  4,  5, 34, 35, 50, 51 },
        { 60, 61, 12, 13, 42, 43, 58, 59 },
        { 20, 21, 36, 37,  6,  7, 22, 23 },
        { 28, 29, 44, 45, 14, 15, 30, 31 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_CobaltB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CobaltB_EachQuad_4x4();

    const M aExpected = {
        { 24,  0, 19, 27, 28,  4, 23, 31 },
        {  8, 16,  1,  9, 12, 20,  5, 13 },
        { 26,  2, 17, 25, 30,  6, 21, 29 },
        { 10, 18,  3, 11, 14, 22,  7, 15 },
        { 56, 32, 51, 59, 60, 36, 55, 63 },
        { 40, 48, 33, 41, 44, 52, 37, 45 },
        { 58, 34, 49, 57, 62, 38, 53, 61 },
        { 42, 50, 35, 43, 46, 54, 39, 47 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_CobaltB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CobaltB_8x8();

    const M aExpected = {
        { 48, 56,  0,  8, 39, 47, 55, 63 },
        { 16, 24, 32, 40,  1,  9, 17, 25 },
        { 50, 58,  2, 10, 33, 41, 49, 57 },
        { 18, 26, 34, 42,  3, 11, 19, 27 },
        { 52, 60,  4, 12, 35, 43, 51, 59 },
        { 20, 28, 36, 44,  5, 13, 21, 29 },
        { 54, 62,  6, 14, 37, 45, 53, 61 },
        { 22, 30, 38, 46,  7, 15, 23, 31 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
