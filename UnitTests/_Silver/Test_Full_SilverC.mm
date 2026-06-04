//
//  Test_Full_SilverC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_SilverC : XCTestCase

@end

@implementation Test_Full_SilverC

- (void)testFull_SilverC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SilverC_4x4();

    const M aExpected = {
        {  2,  3, 34, 35,  6,  7, 38, 39 },
        { 10, 11, 42, 43, 14, 15, 46, 47 },
        { 50, 51, 18, 19, 54, 55, 22, 23 },
        { 58, 59, 26, 27, 62, 63, 30, 31 },
        { 48, 49, 20, 21, 52, 53, 16, 17 },
        { 56, 57, 28, 29, 60, 61, 24, 25 },
        { 32, 33,  4,  5, 36, 37,  0,  1 },
        { 40, 41, 12, 13, 44, 45,  8,  9 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_SilverC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SilverC_EachQuad_4x4();

    const M aExpected = {
        {  1, 17,  3, 19,  5, 21,  7, 23 },
        { 25,  9, 27, 11, 29, 13, 31, 15 },
        { 24, 10, 26,  8, 28, 14, 30, 12 },
        { 16,  2, 18,  0, 20,  6, 22,  4 },
        { 33, 49, 35, 51, 37, 53, 39, 55 },
        { 57, 41, 59, 43, 61, 45, 63, 47 },
        { 56, 42, 58, 40, 60, 46, 62, 44 },
        { 48, 34, 50, 32, 52, 38, 54, 36 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_SilverC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_SilverC_8x8();

    const M aExpected = {
        {  9, 41, 11, 43, 13, 45, 15, 47 },
        {  1, 33,  3, 35,  5, 37,  7, 39 },
        { 57, 25, 59, 27, 61, 29, 63, 31 },
        { 49, 17, 51, 19, 53, 21, 55, 23 },
        { 56, 26, 58, 28, 60, 30, 62, 24 },
        { 48, 18, 50, 20, 52, 22, 54, 16 },
        { 40, 10, 42, 12, 44, 14, 46,  8 },
        { 32,  2, 34,  4, 36,  6, 38,  0 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
