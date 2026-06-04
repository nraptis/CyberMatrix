//
//  Test_Full_GlendaleA.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_GlendaleA : XCTestCase

@end

@implementation Test_Full_GlendaleA

- (void)testFull_GlendaleA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_GlendaleA_4x4();

    const M aExpected = {
        { 20, 21,  6,  7,  2,  3, 16, 17 },
        { 28, 29, 14, 15, 10, 11, 24, 25 },
        {  4,  5, 36, 37, 18, 19, 50, 51 },
        { 12, 13, 44, 45, 26, 27, 58, 59 },
        { 38, 39, 52, 53, 48, 49, 34, 35 },
        { 46, 47, 60, 61, 56, 57, 42, 43 },
        { 54, 55, 22, 23, 32, 33,  0,  1 },
        { 62, 63, 30, 31, 40, 41,  8,  9 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_GlendaleA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_GlendaleA_EachQuad_4x4();

    const M aExpected = {
        { 10,  3,  1,  8, 14,  7,  5, 12 },
        {  2, 18,  9, 25,  6, 22, 13, 29 },
        { 19, 26, 24, 17, 23, 30, 28, 21 },
        { 27, 11, 16,  0, 31, 15, 20,  4 },
        { 42, 35, 33, 40, 46, 39, 37, 44 },
        { 34, 50, 41, 57, 38, 54, 45, 61 },
        { 51, 58, 56, 49, 55, 62, 60, 53 },
        { 59, 43, 48, 32, 63, 47, 52, 36 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_GlendaleA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_GlendaleA_8x8();

    const M aExpected = {
        { 20, 12, 22, 14,  2, 26,  0, 24 },
        { 21, 13, 23, 15,  3, 27,  1, 25 },
        {  4, 46,  6, 44, 18, 56, 16, 58 },
        {  5, 47,  7, 45, 19, 57, 17, 59 },
        { 38, 62, 36, 60, 48, 40, 50, 42 },
        { 39, 63, 37, 61, 49, 41, 51, 43 },
        { 54, 28, 52, 30, 32, 10, 34,  8 },
        { 55, 29, 53, 31, 33, 11, 35,  9 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
