//
//  Test_Full_HeronA.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_HeronA : XCTestCase

@end

@implementation Test_Full_HeronA

- (void)testFull_HeronA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronA_4x4();

    const M aExpected = {
        {  2,  3,  0,  1,  6,  7,  4,  5 },
        { 10, 11,  8,  9, 14, 15, 12, 13 },
        { 18, 19, 16, 17, 22, 23, 20, 21 },
        { 26, 27, 24, 25, 30, 31, 28, 29 },
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

- (void)testFull_HeronA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronA_EachQuad_4x4();

    const M aExpected = {
        {  1,  0,  3,  2,  5,  4,  7,  6 },
        {  9,  8, 11, 10, 13, 12, 15, 14 },
        { 19, 18, 17, 16, 23, 22, 21, 20 },
        { 27, 26, 25, 24, 31, 30, 29, 28 },
        { 33, 32, 35, 34, 37, 36, 39, 38 },
        { 41, 40, 43, 42, 45, 44, 47, 46 },
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

- (void)testFull_HeronA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronA_8x8();

    const M aExpected = {
        {  1,  0,  3,  2,  5,  4,  7,  6 },
        {  9,  8, 11, 10, 13, 12, 15, 14 },
        { 17, 16, 19, 18, 21, 20, 23, 22 },
        { 25, 24, 27, 26, 29, 28, 31, 30 },
        { 39, 34, 33, 36, 35, 38, 37, 32 },
        { 47, 42, 41, 44, 43, 46, 45, 40 },
        { 55, 50, 49, 52, 51, 54, 53, 48 },
        { 63, 58, 57, 60, 59, 62, 61, 56 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
