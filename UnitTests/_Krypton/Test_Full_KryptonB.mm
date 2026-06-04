//
//  Test_Full_KryptonB.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_KryptonB : XCTestCase

@end

@implementation Test_Full_KryptonB

- (void)testFull_KryptonB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_KryptonB_4x4();

    const M aExpected = {
        {  2,  3, 38, 39, 48, 49, 20, 21 },
        { 10, 11, 46, 47, 56, 57, 28, 29 },
        { 18, 19, 54, 55, 32, 33,  4,  5 },
        { 26, 27, 62, 63, 40, 41, 12, 13 },
        { 50, 51, 36, 37,  0,  1, 22, 23 },
        { 58, 59, 44, 45,  8,  9, 30, 31 },
        { 34, 35, 52, 53, 16, 17,  6,  7 },
        { 42, 43, 60, 61, 24, 25, 14, 15 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_KryptonB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_KryptonB_EachQuad_4x4();

    const M aExpected = {
        {  1, 19, 24, 10,  5, 23, 28, 14 },
        {  9, 27, 16,  2, 13, 31, 20,  6 },
        { 25, 18,  0, 11, 29, 22,  4, 15 },
        { 17, 26,  8,  3, 21, 30, 12,  7 },
        { 33, 51, 56, 42, 37, 55, 60, 46 },
        { 41, 59, 48, 34, 45, 63, 52, 38 },
        { 57, 50, 32, 43, 61, 54, 36, 47 },
        { 49, 58, 40, 35, 53, 62, 44, 39 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_KryptonB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_KryptonB_8x8();

    const M aExpected = {
        {  2, 36, 50, 38, 48, 22,  0, 20 },
        {  3, 37, 51, 39, 49, 23,  1, 21 },
        { 18, 52, 34, 54, 32,  6, 16,  4 },
        { 19, 53, 35, 55, 33,  7, 17,  5 },
        { 58, 44, 56, 46,  8, 30, 10, 28 },
        { 59, 45, 57, 47,  9, 31, 11, 29 },
        { 42, 60, 40, 62, 24, 14, 26, 12 },
        { 43, 61, 41, 63, 25, 15, 27, 13 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
