//
//  Test_Full_FalconC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_FalconC : XCTestCase

@end

@implementation Test_Full_FalconC

- (void)testFull_FalconC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconC_4x4();

    const M aExpected = {
        { 52, 53, 54, 55, 48, 49, 50, 51 },
        { 60, 61, 62, 63, 56, 57, 58, 59 },
        { 36, 37, 38, 39, 32, 33, 34, 35 },
        { 44, 45, 46, 47, 40, 41, 42, 43 },
        { 16, 17, 22, 23, 20, 21, 18, 19 },
        { 24, 25, 30, 31, 28, 29, 26, 27 },
        {  0,  1,  6,  7,  4,  5,  2,  3 },
        {  8,  9, 14, 15, 12, 13, 10, 11 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FalconC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconC_EachQuad_4x4();

    const M aExpected = {
        { 26, 27, 24, 25, 30, 31, 28, 29 },
        { 18, 19, 16, 17, 22, 23, 20, 21 },
        {  8, 11, 10,  9, 12, 15, 14, 13 },
        {  0,  3,  2,  1,  4,  7,  6,  5 },
        { 58, 59, 56, 57, 62, 63, 60, 61 },
        { 50, 51, 48, 49, 54, 55, 52, 53 },
        { 40, 43, 42, 41, 44, 47, 46, 45 },
        { 32, 35, 34, 33, 36, 39, 38, 37 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FalconC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconC_8x8();

    const M aExpected = {
        { 62, 63, 60, 61, 58, 59, 56, 57 },
        { 54, 55, 52, 53, 50, 51, 48, 49 },
        { 46, 47, 44, 45, 42, 43, 40, 41 },
        { 38, 39, 36, 37, 34, 35, 32, 33 },
        { 24, 31, 30, 29, 28, 27, 26, 25 },
        { 16, 23, 22, 21, 20, 19, 18, 17 },
        {  8, 15, 14, 13, 12, 11, 10,  9 },
        {  0,  7,  6,  5,  4,  3,  2,  1 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
