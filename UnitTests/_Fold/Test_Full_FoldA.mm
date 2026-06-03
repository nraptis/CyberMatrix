//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_FoldA : XCTestCase

@end

@implementation Test_Full_FoldA

- (void)testFull_FoldA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FoldA_4x4();

    const M aExpected = {
        {  6,  7, 18, 19, 20, 21,  0,  1 },
        { 14, 15, 26, 27, 28, 29,  8,  9 },
        { 22, 23,  2,  3,  4,  5, 16, 17 },
        { 30, 31, 10, 11, 12, 13, 24, 25 },
        { 38, 39, 50, 51, 52, 53, 32, 33 },
        { 46, 47, 58, 59, 60, 61, 40, 41 },
        { 54, 55, 34, 35, 36, 37, 48, 49 },
        { 62, 63, 42, 43, 44, 45, 56, 57 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FoldA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FoldA_EachQuad_4x4();

    const M aExpected = {
        {  3,  9, 10,  0,  7, 13, 14,  4 },
        { 11,  1,  2,  8, 15,  5,  6, 12 },
        { 19, 25, 26, 16, 23, 29, 30, 20 },
        { 27, 17, 18, 24, 31, 21, 22, 28 },
        { 35, 41, 42, 32, 39, 45, 46, 36 },
        { 43, 33, 34, 40, 47, 37, 38, 44 },
        { 51, 57, 58, 48, 55, 61, 62, 52 },
        { 59, 49, 50, 56, 63, 53, 54, 60 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}



@end
