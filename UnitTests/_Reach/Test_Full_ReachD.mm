//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_ReachD : XCTestCase

@end

@implementation Test_Full_ReachD

- (void)testFull_ReachD_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachD_4x4();

    const M aExpected = {
        {  0,  1,  2,  3, 36, 37, 38, 39 },
        {  8,  9, 10, 11, 44, 45, 46, 47 },
        { 48, 49, 50, 51, 20, 21, 22, 23 },
        { 56, 57, 58, 59, 28, 29, 30, 31 },
        { 32, 33, 34, 35,  4,  5,  6,  7 },
        { 40, 41, 42, 43, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 52, 53, 54, 55 },
        { 24, 25, 26, 27, 60, 61, 62, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_ReachD_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachD_EachQuad_4x4();

    const M aExpected = {
        {  0,  1, 18, 19,  4,  5, 22, 23 },
        { 24, 25, 10, 11, 28, 29, 14, 15 },
        { 16, 17,  2,  3, 20, 21,  6,  7 },
        {  8,  9, 26, 27, 12, 13, 30, 31 },
        { 32, 33, 50, 51, 36, 37, 54, 55 },
        { 56, 57, 42, 43, 60, 61, 46, 47 },
        { 48, 49, 34, 35, 52, 53, 38, 39 },
        { 40, 41, 58, 59, 44, 45, 62, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_ReachD_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_ReachD_8x8();

    const M aExpected = {
        {  0,  1, 18, 19,  4,  5, 22, 23 },
        { 24, 25, 10, 11, 28, 29, 14, 15 },
        { 16, 17,  2,  3, 20, 21,  6,  7 },
        {  8,  9, 26, 27, 12, 13, 30, 31 },
        { 32, 33, 50, 51, 36, 37, 54, 55 },
        { 56, 57, 42, 43, 60, 61, 46, 47 },
        { 48, 49, 34, 35, 52, 53, 38, 39 },
        { 40, 41, 58, 59, 44, 45, 62, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}


@end
