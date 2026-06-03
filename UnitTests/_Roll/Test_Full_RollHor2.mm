//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_RollHor2 : XCTestCase

@end

@implementation Test_Full_RollHor2

- (void)testFull_RollHor2_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RollHor2_4x4();

    const M aExpected = {
        {  4,  5,  6,  7,  0,  1,  2,  3 },
        { 12, 13, 14, 15,  8,  9, 10, 11 },
        { 20, 21, 22, 23, 16, 17, 18, 19 },
        { 28, 29, 30, 31, 24, 25, 26, 27 },
        { 36, 37, 38, 39, 32, 33, 34, 35 },
        { 44, 45, 46, 47, 40, 41, 42, 43 },
        { 52, 53, 54, 55, 48, 49, 50, 51 },
        { 60, 61, 62, 63, 56, 57, 58, 59 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_RollHor2_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RollHor2_EachQuad_4x4();

    const M aExpected = {
        {  2,  3,  0,  1,  6,  7,  4,  5 },
        { 10, 11,  8,  9, 14, 15, 12, 13 },
        { 18, 19, 16, 17, 22, 23, 20, 21 },
        { 26, 27, 24, 25, 30, 31, 28, 29 },
        { 34, 35, 32, 33, 38, 39, 36, 37 },
        { 42, 43, 40, 41, 46, 47, 44, 45 },
        { 50, 51, 48, 49, 54, 55, 52, 53 },
        { 58, 59, 56, 57, 62, 63, 60, 61 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
