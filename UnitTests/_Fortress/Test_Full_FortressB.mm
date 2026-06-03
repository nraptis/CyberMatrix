//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_FortressB : XCTestCase

@end

@implementation Test_Full_FortressB

- (void)testFull_FortressB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FortressB_4x4();

    const M aExpected = {
        { 54, 55, 52, 53, 18, 19, 48, 49 },
        { 62, 63, 60, 61, 26, 27, 56, 57 },
        { 34, 35,  4,  5, 38, 39, 32, 33 },
        { 42, 43, 12, 13, 46, 47, 40, 41 },
        { 22, 23, 16, 17, 50, 51, 20, 21 },
        { 30, 31, 24, 25, 58, 59, 28, 29 },
        {  6,  7, 36, 37,  2,  3,  0,  1 },
        { 14, 15, 44, 45, 10, 11,  8,  9 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FortressB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FortressB_EachQuad_4x4();

    const M aExpected = {
        { 27, 26,  9, 24, 31, 30, 13, 28 },
        { 17,  2, 19, 16, 21,  6, 23, 20 },
        { 11,  8, 25, 10, 15, 12, 29, 14 },
        {  3, 18,  1,  0,  7, 22,  5,  4 },
        { 59, 58, 41, 56, 63, 62, 45, 60 },
        { 49, 34, 51, 48, 53, 38, 55, 52 },
        { 43, 40, 57, 42, 47, 44, 61, 46 },
        { 35, 50, 33, 32, 39, 54, 37, 36 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}


@end
