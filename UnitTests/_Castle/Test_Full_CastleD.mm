//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_CastleD : XCTestCase

@end

@implementation Test_Full_CastleD

- (void)testFull_CastleD_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleD_4x4();

    const M aExpected = {
        { 18, 19, 16, 17, 32, 33, 20, 21 },
        { 26, 27, 24, 25, 40, 41, 28, 29 },
        { 52, 53,  0,  1,  6,  7,  4,  5 },
        { 60, 61,  8,  9, 14, 15, 12, 13 },
        { 50, 51, 48, 49, 54, 55,  2,  3 },
        { 58, 59, 56, 57, 62, 63, 10, 11 },
        { 34, 35, 22, 23, 38, 39, 36, 37 },
        { 42, 43, 30, 31, 46, 47, 44, 45 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_CastleD_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleD_EachQuad_4x4();

    const M aExpected = {
        {  9,  8, 16, 10, 13, 12, 20, 14 },
        { 26,  0,  3,  2, 30,  4,  7,  6 },
        { 25, 24, 27,  1, 29, 28, 31,  5 },
        { 17, 11, 19, 18, 21, 15, 23, 22 },
        { 41, 40, 48, 42, 45, 44, 52, 46 },
        { 58, 32, 35, 34, 62, 36, 39, 38 },
        { 57, 56, 59, 33, 61, 60, 63, 37 },
        { 49, 43, 51, 50, 53, 47, 55, 54 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
