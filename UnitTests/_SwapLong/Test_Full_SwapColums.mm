//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_SwapColums : XCTestCase

@end

@implementation Test_Full_SwapColums

- (void)testFull_SwapColums_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SwapColums_4x4();

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

- (void)testFull_SwapColums_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SwapColums_EachQuad_4x4();

    const M aExpected = {
        {  1,  0,  3,  2,  5,  4,  7,  6 },
        {  9,  8, 11, 10, 13, 12, 15, 14 },
        { 17, 16, 19, 18, 21, 20, 23, 22 },
        { 25, 24, 27, 26, 29, 28, 31, 30 },
        { 33, 32, 35, 34, 37, 36, 39, 38 },
        { 41, 40, 43, 42, 45, 44, 47, 46 },
        { 49, 48, 51, 50, 53, 52, 55, 54 },
        { 57, 56, 59, 58, 61, 60, 63, 62 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_SwapColums_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SwapColums_8x8();

    const M aExpected = {
        {  1,  0,  3,  2,  5,  4,  7,  6 },
        {  9,  8, 11, 10, 13, 12, 15, 14 },
        { 17, 16, 19, 18, 21, 20, 23, 22 },
        { 25, 24, 27, 26, 29, 28, 31, 30 },
        { 33, 32, 35, 34, 37, 36, 39, 38 },
        { 41, 40, 43, 42, 45, 44, 47, 46 },
        { 49, 48, 51, 50, 53, 52, 55, 54 },
        { 57, 56, 59, 58, 61, 60, 63, 62 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
