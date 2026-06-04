//
//  Test_Full_EssexC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_EssexC : XCTestCase

@end

@implementation Test_Full_EssexC

- (void)testFull_EssexC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_EssexC_4x4();

    const M aExpected = {
        { 32, 33, 54, 55, 18, 19,  4,  5 },
        { 40, 41, 62, 63, 26, 27, 12, 13 },
        { 48, 49, 38, 39,  2,  3, 20, 21 },
        { 56, 57, 46, 47, 10, 11, 28, 29 },
        { 34, 35,  6,  7, 16, 17, 52, 53 },
        { 42, 43, 14, 15, 24, 25, 60, 61 },
        { 50, 51, 22, 23,  0,  1, 36, 37 },
        { 58, 59, 30, 31,  8,  9, 44, 45 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_EssexC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_EssexC_EachQuad_4x4();

    const M aExpected = {
        { 16, 27,  9,  2, 20, 31, 13,  6 },
        { 24, 19,  1, 10, 28, 23,  5, 14 },
        { 17,  3,  8, 26, 21,  7, 12, 30 },
        { 25, 11,  0, 18, 29, 15,  4, 22 },
        { 48, 59, 41, 34, 52, 63, 45, 38 },
        { 56, 51, 33, 42, 60, 55, 37, 46 },
        { 49, 35, 40, 58, 53, 39, 44, 62 },
        { 57, 43, 32, 50, 61, 47, 36, 54 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_EssexC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_EssexC_8x8();

    const M aExpected = {
        { 43, 61, 41, 63, 25, 15, 27, 13 },
        { 42, 60, 40, 62, 24, 14, 26, 12 },
        { 59, 45, 57, 47,  9, 31, 11, 29 },
        { 58, 44, 56, 46,  8, 30, 10, 28 },
        { 35, 55, 33,  7, 17,  5, 19, 53 },
        { 34, 54, 32,  6, 16,  4, 18, 52 },
        { 51, 39, 49, 23,  1, 21,  3, 37 },
        { 50, 38, 48, 22,  0, 20,  2, 36 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
