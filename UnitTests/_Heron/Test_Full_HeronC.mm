//
//  Test_Full_HeronC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_HeronC : XCTestCase

@end

@implementation Test_Full_HeronC

- (void)testFull_HeronC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronC_4x4();

    const M aExpected = {
        { 48, 49, 50, 51, 52, 53, 54, 55 },
        { 56, 57, 58, 59, 60, 61, 62, 63 },
        { 32, 33, 34, 35, 36, 37, 38, 39 },
        { 40, 41, 42, 43, 44, 45, 46, 47 },
        { 20, 21, 22, 23, 16, 17, 18, 19 },
        { 28, 29, 30, 31, 24, 25, 26, 27 },
        {  4,  5,  6,  7,  0,  1,  2,  3 },
        { 12, 13, 14, 15,  8,  9, 10, 11 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeronC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronC_EachQuad_4x4();

    const M aExpected = {
        { 24, 25, 26, 27, 28, 29, 30, 31 },
        { 16, 17, 18, 19, 20, 21, 22, 23 },
        { 10, 11,  8,  9, 14, 15, 12, 13 },
        {  2,  3,  0,  1,  6,  7,  4,  5 },
        { 56, 57, 58, 59, 60, 61, 62, 63 },
        { 48, 49, 50, 51, 52, 53, 54, 55 },
        { 42, 43, 40, 41, 46, 47, 44, 45 },
        { 34, 35, 32, 33, 38, 39, 36, 37 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeronC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronC_8x8();

    const M aExpected = {
        { 56, 61, 62, 59, 60, 57, 58, 63 },
        { 48, 53, 54, 51, 52, 49, 50, 55 },
        { 40, 45, 46, 43, 44, 41, 42, 47 },
        { 32, 37, 38, 35, 36, 33, 34, 39 },
        { 30, 31, 28, 29, 26, 27, 24, 25 },
        { 22, 23, 20, 21, 18, 19, 16, 17 },
        { 14, 15, 12, 13, 10, 11,  8,  9 },
        {  6,  7,  4,  5,  2,  3,  0,  1 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
