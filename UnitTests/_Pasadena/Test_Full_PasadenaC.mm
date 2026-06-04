//
//  Test_Full_PasadenaC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_PasadenaC : XCTestCase

@end

@implementation Test_Full_PasadenaC

- (void)testFull_PasadenaC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PasadenaC_4x4();

    const M aExpected = {
        { 32, 33,  0,  1, 54, 55, 22, 23 },
        { 40, 41,  8,  9, 62, 63, 30, 31 },
        { 48, 49, 34, 35, 38, 39, 52, 53 },
        { 56, 57, 42, 43, 46, 47, 60, 61 },
        { 18, 19, 50, 51,  4,  5, 36, 37 },
        { 26, 27, 58, 59, 12, 13, 44, 45 },
        {  2,  3, 16, 17, 20, 21,  6,  7 },
        { 10, 11, 24, 25, 28, 29, 14, 15 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_PasadenaC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PasadenaC_EachQuad_4x4();

    const M aExpected = {
        { 16,  0, 27, 11, 20,  4, 31, 15 },
        { 24, 17, 19, 26, 28, 21, 23, 30 },
        {  9, 25,  2, 18, 13, 29,  6, 22 },
        {  1,  8, 10,  3,  5, 12, 14,  7 },
        { 48, 32, 59, 43, 52, 36, 63, 47 },
        { 56, 49, 51, 58, 60, 53, 55, 62 },
        { 41, 57, 34, 50, 45, 61, 38, 54 },
        { 33, 40, 42, 35, 37, 44, 46, 39 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_PasadenaC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PasadenaC_8x8();

    const M aExpected = {
        { 40,  2, 42,  0, 62, 20, 60, 22 },
        { 41,  3, 43,  1, 63, 21, 61, 23 },
        { 56, 32, 58, 34, 46, 54, 44, 52 },
        { 57, 33, 59, 35, 47, 55, 45, 53 },
        { 26, 48, 24, 50, 12, 38, 14, 36 },
        { 27, 49, 25, 51, 13, 39, 15, 37 },
        { 10, 18,  8, 16, 28,  4, 30,  6 },
        { 11, 19,  9, 17, 29,  5, 31,  7 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
