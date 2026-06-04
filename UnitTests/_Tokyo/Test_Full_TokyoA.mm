//
//  Test_Full_TokyoA.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_TokyoA : XCTestCase

@end

@implementation Test_Full_TokyoA

- (void)testFull_TokyoA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TokyoA_4x4();

    const M aExpected = {
        { 16, 17,  2,  3,  6,  7, 20, 21 },
        { 24, 25, 10, 11, 14, 15, 28, 29 },
        { 50, 51, 18, 19, 36, 37,  4,  5 },
        { 58, 59, 26, 27, 44, 45, 12, 13 },
        { 34, 35, 48, 49, 52, 53, 38, 39 },
        { 42, 43, 56, 57, 60, 61, 46, 47 },
        {  0,  1, 32, 33, 22, 23, 54, 55 },
        {  8,  9, 40, 41, 30, 31, 62, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_TokyoA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TokyoA_EachQuad_4x4();

    const M aExpected = {
        {  8,  1,  3, 10, 12,  5,  7, 14 },
        { 25,  9, 18,  2, 29, 13, 22,  6 },
        { 17, 24, 26, 19, 21, 28, 30, 23 },
        {  0, 16, 11, 27,  4, 20, 15, 31 },
        { 40, 33, 35, 42, 44, 37, 39, 46 },
        { 57, 41, 50, 34, 61, 45, 54, 38 },
        { 49, 56, 58, 51, 53, 60, 62, 55 },
        { 32, 48, 43, 59, 36, 52, 47, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_TokyoA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TokyoA_8x8();

    const M aExpected = {
        { 24,  0, 26,  2, 14, 22, 12, 20 },
        { 25,  1, 27,  3, 15, 23, 13, 21 },
        { 58, 16, 56, 18, 44,  6, 46,  4 },
        { 59, 17, 57, 19, 45,  7, 47,  5 },
        { 42, 50, 40, 48, 60, 36, 62, 38 },
        { 43, 51, 41, 49, 61, 37, 63, 39 },
        {  8, 34, 10, 32, 30, 52, 28, 54 },
        {  9, 35, 11, 33, 31, 53, 29, 55 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
