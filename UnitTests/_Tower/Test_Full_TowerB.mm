//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_TowerB : XCTestCase

@end

@implementation Test_Full_TowerB


- (void)testFull_TowerB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TowerB_4x4();

    const M aExpected = {
        { 16, 17, 34, 35,  6,  7,  4,  5 },
        { 24, 25, 42, 43, 14, 15, 12, 13 },
        {  0,  1, 22, 23, 52, 53, 18, 19 },
        {  8,  9, 30, 31, 60, 61, 26, 27 },
        { 36, 37,  2,  3, 32, 33, 54, 55 },
        { 44, 45, 10, 11, 40, 41, 62, 63 },
        { 50, 51, 48, 49, 20, 21, 38, 39 },
        { 58, 59, 56, 57, 28, 29, 46, 47 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_TowerB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TowerB_EachQuad_4x4();

    const M aExpected = {
        {  8, 17,  3,  2, 12, 21,  7,  6 },
        {  0, 11, 26,  9,  4, 15, 30, 13 },
        { 18,  1, 16, 27, 22,  5, 20, 31 },
        { 25, 24, 10, 19, 29, 28, 14, 23 },
        { 40, 49, 35, 34, 44, 53, 39, 38 },
        { 32, 43, 58, 41, 36, 47, 62, 45 },
        { 50, 33, 48, 59, 54, 37, 52, 63 },
        { 57, 56, 42, 51, 61, 60, 46, 55 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
