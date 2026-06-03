//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_FoldC : XCTestCase

@end

@implementation Test_Full_FoldC

- (void)testFull_FoldC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FoldC_4x4();

    const M aExpected = {
        {  6,  7,  4,  5,  2,  3,  0,  1 },
        { 14, 15, 12, 13, 10, 11,  8,  9 },
        { 22, 23, 20, 21, 18, 19, 16, 17 },
        { 30, 31, 28, 29, 26, 27, 24, 25 },
        { 38, 39, 36, 37, 34, 35, 32, 33 },
        { 46, 47, 44, 45, 42, 43, 40, 41 },
        { 54, 55, 52, 53, 50, 51, 48, 49 },
        { 62, 63, 60, 61, 58, 59, 56, 57 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FoldC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FoldC_EachQuad_4x4();

    const M aExpected = {
        {  3,  2,  1,  0,  7,  6,  5,  4 },
        { 11, 10,  9,  8, 15, 14, 13, 12 },
        { 19, 18, 17, 16, 23, 22, 21, 20 },
        { 27, 26, 25, 24, 31, 30, 29, 28 },
        { 35, 34, 33, 32, 39, 38, 37, 36 },
        { 43, 42, 41, 40, 47, 46, 45, 44 },
        { 51, 50, 49, 48, 55, 54, 53, 52 },
        { 59, 58, 57, 56, 63, 62, 61, 60 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
