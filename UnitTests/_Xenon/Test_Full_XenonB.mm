//
//  Test_Full_XenonB.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_XenonB : XCTestCase

@end

@implementation Test_Full_XenonB

- (void)testFull_XenonB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_XenonB_4x4();

    const M aExpected = {
        { 34, 35,  6,  7, 16, 17, 52, 53 },
        { 42, 43, 14, 15, 24, 25, 60, 61 },
        { 50, 51, 22, 23,  0,  1, 36, 37 },
        { 58, 59, 30, 31,  8,  9, 44, 45 },
        { 18, 19,  4,  5, 32, 33, 54, 55 },
        { 26, 27, 12, 13, 40, 41, 62, 63 },
        {  2,  3, 20, 21, 48, 49, 38, 39 },
        { 10, 11, 28, 29, 56, 57, 46, 47 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_XenonB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_XenonB_EachQuad_4x4();

    const M aExpected = {
        { 17,  3,  8, 26, 21,  7, 12, 30 },
        { 25, 11,  0, 18, 29, 15,  4, 22 },
        {  9,  2, 16, 27, 13,  6, 20, 31 },
        {  1, 10, 24, 19,  5, 14, 28, 23 },
        { 49, 35, 40, 58, 53, 39, 44, 62 },
        { 57, 43, 32, 50, 61, 47, 36, 54 },
        { 41, 34, 48, 59, 45, 38, 52, 63 },
        { 33, 42, 56, 51, 37, 46, 60, 55 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_XenonB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_XenonB_8x8();

    const M aExpected = {
        { 43, 13, 27, 15, 25, 63, 41, 61 },
        { 42, 12, 26, 14, 24, 62, 40, 60 },
        { 59, 29, 11, 31,  9, 47, 57, 45 },
        { 58, 28, 10, 30,  8, 46, 56, 44 },
        { 19,  5, 17,  7, 33, 55, 35, 53 },
        { 18,  4, 16,  6, 32, 54, 34, 52 },
        {  3, 21,  1, 23, 49, 39, 51, 37 },
        {  2, 20,  0, 22, 48, 38, 50, 36 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
