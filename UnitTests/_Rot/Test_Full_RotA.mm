//
//  TestFullRotA.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_RotA : XCTestCase

@end

@implementation Test_Full_RotA

- (void)testFull_RotA_2x2 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RotA_2x2();

    const M aExpected = {
        { 32, 33, 34, 35,  0,  1,  2,  3 },
        { 40, 41, 42, 43,  8,  9, 10, 11 },
        { 48, 49, 50, 51, 16, 17, 18, 19 },
        { 56, 57, 58, 59, 24, 25, 26, 27 },
        { 36, 37, 38, 39,  4,  5,  6,  7 },
        { 44, 45, 46, 47, 12, 13, 14, 15 },
        { 52, 53, 54, 55, 20, 21, 22, 23 },
        { 60, 61, 62, 63, 28, 29, 30, 31 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        NSLog(@"%s succeeded", sel_getName(_cmd));
    }
}

- (void)testFull_RotA_EachQuad_2x2 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RotA_EachQuad_2x2();

    const M aExpected = {
        { 16, 17,  0,  1, 20, 21,  4,  5 },
        { 24, 25,  8,  9, 28, 29, 12, 13 },
        { 18, 19,  2,  3, 22, 23,  6,  7 },
        { 26, 27, 10, 11, 30, 31, 14, 15 },
        { 48, 49, 32, 33, 52, 53, 36, 37 },
        { 56, 57, 40, 41, 60, 61, 44, 45 },
        { 50, 51, 34, 35, 54, 55, 38, 39 },
        { 58, 59, 42, 43, 62, 63, 46, 47 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        NSLog(@"%s succeeded", sel_getName(_cmd));
    }
}

- (void)testFull_RotA_EachMini_2x2 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RotA_EachMini_2x2();

    const M aExpected = {
        {  8,  0, 10,  2, 12,  4, 14,  6 },
        {  9,  1, 11,  3, 13,  5, 15,  7 },
        { 24, 16, 26, 18, 28, 20, 30, 22 },
        { 25, 17, 27, 19, 29, 21, 31, 23 },
        { 40, 32, 42, 34, 44, 36, 46, 38 },
        { 41, 33, 43, 35, 45, 37, 47, 39 },
        { 56, 48, 58, 50, 60, 52, 62, 54 },
        { 57, 49, 59, 51, 61, 53, 63, 55 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        NSLog(@"%s succeeded", sel_getName(_cmd));
    }
}

- (void)testFull_RotA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RotA_4x4();

    const M aExpected = {
        { 48, 49, 32, 33, 16, 17,  0,  1 },
        { 56, 57, 40, 41, 24, 25,  8,  9 },
        { 50, 51, 34, 35, 18, 19,  2,  3 },
        { 58, 59, 42, 43, 26, 27, 10, 11 },
        { 52, 53, 36, 37, 20, 21,  4,  5 },
        { 60, 61, 44, 45, 28, 29, 12, 13 },
        { 54, 55, 38, 39, 22, 23,  6,  7 },
        { 62, 63, 46, 47, 30, 31, 14, 15 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        NSLog(@"%s succeeded", sel_getName(_cmd));
    }
}

- (void)testFull_RotA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RotA_EachQuad_4x4();

    const M aExpected = {
        { 24, 16,  8,  0, 28, 20, 12,  4 },
        { 25, 17,  9,  1, 29, 21, 13,  5 },
        { 26, 18, 10,  2, 30, 22, 14,  6 },
        { 27, 19, 11,  3, 31, 23, 15,  7 },
        { 56, 48, 40, 32, 60, 52, 44, 36 },
        { 57, 49, 41, 33, 61, 53, 45, 37 },
        { 58, 50, 42, 34, 62, 54, 46, 38 },
        { 59, 51, 43, 35, 63, 55, 47, 39 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        NSLog(@"%s succeeded", sel_getName(_cmd));
    }
}

- (void)testFull_RotA_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_RotA_8x8();

    const M aExpected = {
        { 56, 48, 40, 32, 24, 16,  8,  0 },
        { 57, 49, 41, 33, 25, 17,  9,  1 },
        { 58, 50, 42, 34, 26, 18, 10,  2 },
        { 59, 51, 43, 35, 27, 19, 11,  3 },
        { 60, 52, 44, 36, 28, 20, 12,  4 },
        { 61, 53, 45, 37, 29, 21, 13,  5 },
        { 62, 54, 46, 38, 30, 22, 14,  6 },
        { 63, 55, 47, 39, 31, 23, 15,  7 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        NSLog(@"%s succeeded", sel_getName(_cmd));
    }
}

@end
