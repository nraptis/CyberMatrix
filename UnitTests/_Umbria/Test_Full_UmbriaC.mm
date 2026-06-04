//
//  Test_Full_UmbriaC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_UmbriaC : XCTestCase

@end

@implementation Test_Full_UmbriaC

- (void)testFull_UmbriaC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_UmbriaC_4x4();

    const M aExpected = {
        {  2,  3, 36, 37,  0,  1, 38, 39 },
        { 10, 11, 44, 45,  8,  9, 46, 47 },
        { 50, 51, 52, 53, 16, 17, 22, 23 },
        { 58, 59, 60, 61, 24, 25, 30, 31 },
        { 48, 49, 20, 21, 18, 19, 54, 55 },
        { 56, 57, 28, 29, 26, 27, 62, 63 },
        { 32, 33,  4,  5, 34, 35,  6,  7 },
        { 40, 41, 12, 13, 42, 43, 14, 15 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_UmbriaC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_UmbriaC_EachQuad_4x4();

    const M aExpected = {
        {  1, 18,  0, 19,  5, 22,  4, 23 },
        { 25, 26,  8, 11, 29, 30, 12, 15 },
        { 24, 10,  9, 27, 28, 14, 13, 31 },
        { 16,  2, 17,  3, 20,  6, 21,  7 },
        { 33, 50, 32, 51, 37, 54, 36, 55 },
        { 57, 58, 40, 43, 61, 62, 44, 47 },
        { 56, 42, 41, 59, 60, 46, 45, 63 },
        { 48, 34, 49, 35, 52, 38, 53, 39 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_UmbriaC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_UmbriaC_8x8();

    const M aExpected = {
        {  1, 55,  3, 53, 19, 37, 17, 39 },
        { 48, 38, 50, 36,  2, 20,  0, 22 },
        { 49,  7, 51,  5, 35, 21, 33, 23 },
        { 32, 54, 34, 52, 18,  4, 16,  6 },
        {  9, 61, 11, 45, 27, 47, 25, 63 },
        { 56, 44, 58, 28, 10, 30,  8, 46 },
        { 57, 13, 59, 29, 43, 31, 41, 15 },
        { 40, 60, 42, 12, 26, 14, 24, 62 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
