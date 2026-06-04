//
//  Test_Full_TokyoD.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_TokyoD : XCTestCase

@end

@implementation Test_Full_TokyoD

- (void)testFull_TokyoD_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TokyoD_4x4();

    const M aExpected = {
        { 48, 49, 36, 37, 38, 39, 50, 51 },
        { 56, 57, 44, 45, 46, 47, 58, 59 },
        { 52, 53, 54, 55, 34, 35, 32, 33 },
        { 60, 61, 62, 63, 42, 43, 40, 41 },
        {  2,  3, 22, 23, 20, 21,  0,  1 },
        { 10, 11, 30, 31, 28, 29,  8,  9 },
        {  6,  7,  4,  5, 16, 17, 18, 19 },
        { 14, 15, 12, 13, 24, 25, 26, 27 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_TokyoD_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TokyoD_EachQuad_4x4();

    const M aExpected = {
        { 24, 18, 19, 25, 28, 22, 23, 29 },
        { 26, 27, 17, 16, 30, 31, 21, 20 },
        {  1, 11, 10,  0,  5, 15, 14,  4 },
        {  3,  2,  8,  9,  7,  6, 12, 13 },
        { 56, 50, 51, 57, 60, 54, 55, 61 },
        { 58, 59, 49, 48, 62, 63, 53, 52 },
        { 33, 43, 42, 32, 37, 47, 46, 36 },
        { 35, 34, 40, 41, 39, 38, 44, 45 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_TokyoD_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TokyoD_8x8();

    const M aExpected = {
        { 56, 48, 44, 36, 46, 38, 58, 50 },
        { 45, 37, 47, 39, 59, 51, 57, 49 },
        { 40, 32, 60, 52, 62, 54, 42, 34 },
        { 61, 53, 63, 55, 43, 35, 41, 33 },
        { 10,  2, 30, 22, 28, 20,  8,  0 },
        { 31, 23, 29, 21,  9,  1, 11,  3 },
        { 26, 18, 14,  6, 12,  4, 24, 16 },
        { 15,  7, 13,  5, 25, 17, 27, 19 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
