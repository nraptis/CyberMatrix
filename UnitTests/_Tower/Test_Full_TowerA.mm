//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_TowerA : XCTestCase

@end

@implementation Test_Full_TowerA

- (void)testFull_TowerA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TowerA_4x4();

    const M aExpected = {
        { 38, 39, 20, 21, 48, 49, 50, 51 },
        { 46, 47, 28, 29, 56, 57, 58, 59 },
        { 54, 55, 32, 33,  2,  3, 36, 37 },
        { 62, 63, 40, 41, 10, 11, 44, 45 },
        { 18, 19, 52, 53, 22, 23,  0,  1 },
        { 26, 27, 60, 61, 30, 31,  8,  9 },
        {  4,  5,  6,  7, 34, 35, 16, 17 },
        { 12, 13, 14, 15, 42, 43, 24, 25 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_TowerA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_TowerA_EachQuad_4x4();

    const M aExpected = {
        { 19, 10, 24, 25, 23, 14, 28, 29 },
        { 27, 16,  1, 18, 31, 20,  5, 22 },
        {  9, 26, 11,  0, 13, 30, 15,  4 },
        {  2,  3, 17,  8,  6,  7, 21, 12 },
        { 51, 42, 56, 57, 55, 46, 60, 61 },
        { 59, 48, 33, 50, 63, 52, 37, 54 },
        { 41, 58, 43, 32, 45, 62, 47, 36 },
        { 34, 35, 49, 40, 38, 39, 53, 44 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}



@end
