//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_CastleC : XCTestCase

@end

@implementation Test_Full_CastleC

- (void)testFull_CastleC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleC_4x4();

    const M aExpected = {
        { 36, 37, 38, 39, 22, 23, 34, 35 },
        { 44, 45, 46, 47, 30, 31, 42, 43 },
        {  2,  3, 54, 55, 48, 49, 50, 51 },
        { 10, 11, 62, 63, 56, 57, 58, 59 },
        {  4,  5,  6,  7,  0,  1, 52, 53 },
        { 12, 13, 14, 15,  8,  9, 60, 61 },
        { 20, 21, 32, 33, 16, 17, 18, 19 },
        { 28, 29, 40, 41, 24, 25, 26, 27 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_CastleC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleC_EachQuad_4x4();

    const M aExpected = {
        { 18, 19, 11, 17, 22, 23, 15, 21 },
        {  1, 27, 24, 25,  5, 31, 28, 29 },
        {  2,  3,  0, 26,  6,  7,  4, 30 },
        { 10, 16,  8,  9, 14, 20, 12, 13 },
        { 50, 51, 43, 49, 54, 55, 47, 53 },
        { 33, 59, 56, 57, 37, 63, 60, 61 },
        { 34, 35, 32, 58, 38, 39, 36, 62 },
        { 42, 48, 40, 41, 46, 52, 44, 45 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
