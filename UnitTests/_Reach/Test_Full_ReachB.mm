//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_ReachB : XCTestCase

@end

@implementation Test_Full_ReachB

- (void)testFull_ReachB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachB_4x4();

    const M aExpected = {
        {  0,  1,  6,  7,  4,  5,  2,  3 },
        {  8,  9, 14, 15, 12, 13, 10, 11 },
        { 16, 17, 22, 23, 20, 21, 18, 19 },
        { 24, 25, 30, 31, 28, 29, 26, 27 },
        { 36, 37, 34, 35, 32, 33, 38, 39 },
        { 44, 45, 42, 43, 40, 41, 46, 47 },
        { 52, 53, 50, 51, 48, 49, 54, 55 },
        { 60, 61, 58, 59, 56, 57, 62, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_ReachB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachB_EachQuad_4x4();

    const M aExpected = {
        {  0,  3,  2,  1,  4,  7,  6,  5 },
        {  8, 11, 10,  9, 12, 15, 14, 13 },
        { 18, 17, 16, 19, 22, 21, 20, 23 },
        { 26, 25, 24, 27, 30, 29, 28, 31 },
        { 32, 35, 34, 33, 36, 39, 38, 37 },
        { 40, 43, 42, 41, 44, 47, 46, 45 },
        { 50, 49, 48, 51, 54, 53, 52, 55 },
        { 58, 57, 56, 59, 62, 61, 60, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_ReachB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachB_8x8();

    const M aExpected = {
        {  0,  3,  2,  1,  4,  7,  6,  5 },
        {  8, 11, 10,  9, 12, 15, 14, 13 },
        { 18, 17, 16, 19, 22, 21, 20, 23 },
        { 26, 25, 24, 27, 30, 29, 28, 31 },
        { 32, 35, 34, 33, 36, 39, 38, 37 },
        { 40, 43, 42, 41, 44, 47, 46, 45 },
        { 50, 49, 48, 51, 54, 53, 52, 55 },
        { 58, 57, 56, 59, 62, 61, 60, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
