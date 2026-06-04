//
//  Test_Full_KryptonD.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_KryptonD : XCTestCase

@end

@implementation Test_Full_KryptonD

- (void)testFull_KryptonD_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_KryptonD_4x4();

    const M aExpected = {
        { 54, 55, 18, 19,  4,  5, 32, 33 },
        { 62, 63, 26, 27, 12, 13, 40, 41 },
        { 38, 39,  2,  3, 20, 21, 48, 49 },
        { 46, 47, 10, 11, 28, 29, 56, 57 },
        {  6,  7, 16, 17, 52, 53, 34, 35 },
        { 14, 15, 24, 25, 60, 61, 42, 43 },
        { 22, 23,  0,  1, 36, 37, 50, 51 },
        { 30, 31,  8,  9, 44, 45, 58, 59 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_KryptonD_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_KryptonD_EachQuad_4x4();

    const M aExpected = {
        { 27,  9,  2, 16, 31, 13,  6, 20 },
        { 19,  1, 10, 24, 23,  5, 14, 28 },
        {  3,  8, 26, 17,  7, 12, 30, 21 },
        { 11,  0, 18, 25, 15,  4, 22, 29 },
        { 59, 41, 34, 48, 63, 45, 38, 52 },
        { 51, 33, 42, 56, 55, 37, 46, 60 },
        { 35, 40, 58, 49, 39, 44, 62, 53 },
        { 43, 32, 50, 57, 47, 36, 54, 61 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_KryptonD_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_KryptonD_8x8();

    const M aExpected = {
        { 63, 25, 15, 27, 13, 43, 61, 41 },
        { 62, 24, 14, 26, 12, 42, 60, 40 },
        { 47,  9, 31, 11, 29, 59, 45, 57 },
        { 46,  8, 30, 10, 28, 58, 44, 56 },
        {  7, 17,  5, 19, 53, 35, 55, 33 },
        {  6, 16,  4, 18, 52, 34, 54, 32 },
        { 23,  1, 21,  3, 37, 51, 39, 49 },
        { 22,  0, 20,  2, 36, 50, 38, 48 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
