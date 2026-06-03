//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_FortressA : XCTestCase

@end

@implementation Test_Full_FortressA

- (void)testFull_FortressA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FortressA_4x4();

    const M aExpected = {
        { 52, 53, 54, 55, 36, 37, 32, 33 },
        { 60, 61, 62, 63, 44, 45, 40, 41 },
        { 20, 21, 50, 51, 16, 17, 48, 49 },
        { 28, 29, 58, 59, 24, 25, 56, 57 },
        {  6,  7, 38, 39,  4,  5, 34, 35 },
        { 14, 15, 46, 47, 12, 13, 42, 43 },
        { 22, 23, 18, 19,  0,  1,  2,  3 },
        { 30, 31, 26, 27,  8,  9, 10, 11 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FortressA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FortressA_EachQuad_4x4();

    const M aExpected = {
        { 26, 27, 18, 16, 30, 31, 22, 20 },
        { 10, 25,  8, 24, 14, 29, 12, 28 },
        {  3, 19,  2, 17,  7, 23,  6, 21 },
        { 11,  9,  0,  1, 15, 13,  4,  5 },
        { 58, 59, 50, 48, 62, 63, 54, 52 },
        { 42, 57, 40, 56, 46, 61, 44, 60 },
        { 35, 51, 34, 49, 39, 55, 38, 53 },
        { 43, 41, 32, 33, 47, 45, 36, 37 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
