//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_ReachA : XCTestCase

@end

@implementation Test_Full_ReachA

- (void)testFull_ReachA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachA_4x4();

    const M aExpected = {
        {  4,  5,  2,  3,  0,  1,  6,  7 },
        { 12, 13, 10, 11,  8,  9, 14, 15 },
        { 20, 21, 18, 19, 16, 17, 22, 23 },
        { 28, 29, 26, 27, 24, 25, 30, 31 },
        { 32, 33, 38, 39, 36, 37, 34, 35 },
        { 40, 41, 46, 47, 44, 45, 42, 43 },
        { 48, 49, 54, 55, 52, 53, 50, 51 },
        { 56, 57, 62, 63, 60, 61, 58, 59 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_ReachA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachA_EachQuad_4x4();

    const M aExpected = {
        {  2,  1,  0,  3,  6,  5,  4,  7 },
        { 10,  9,  8, 11, 14, 13, 12, 15 },
        { 16, 19, 18, 17, 20, 23, 22, 21 },
        { 24, 27, 26, 25, 28, 31, 30, 29 },
        { 34, 33, 32, 35, 38, 37, 36, 39 },
        { 42, 41, 40, 43, 46, 45, 44, 47 },
        { 48, 51, 50, 49, 52, 55, 54, 53 },
        { 56, 59, 58, 57, 60, 63, 62, 61 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_ReachA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachA_8x8();

    const M aExpected = {
        {  2,  1,  0,  3,  6,  5,  4,  7 },
        { 10,  9,  8, 11, 14, 13, 12, 15 },
        { 16, 19, 18, 17, 20, 23, 22, 21 },
        { 24, 27, 26, 25, 28, 31, 30, 29 },
        { 34, 33, 32, 35, 38, 37, 36, 39 },
        { 42, 41, 40, 43, 46, 45, 44, 47 },
        { 48, 51, 50, 49, 52, 55, 54, 53 },
        { 56, 59, 58, 57, 60, 63, 62, 61 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
