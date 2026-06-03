//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_CastleA : XCTestCase

@end

@implementation Test_Full_CastleA

- (void)testFull_CastleA_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleA_4x4();

    const M aExpected = {
        { 20, 21, 22, 23, 38, 39, 36, 37 },
        { 28, 29, 30, 31, 46, 47, 44, 45 },
        {  4,  5, 48, 49,  0,  1, 52, 53 },
        { 12, 13, 56, 57,  8,  9, 60, 61 },
        {  2,  3, 54, 55,  6,  7, 50, 51 },
        { 10, 11, 62, 63, 14, 15, 58, 59 },
        { 18, 19, 16, 17, 32, 33, 34, 35 },
        { 26, 27, 24, 25, 40, 41, 42, 43 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_CastleA_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_CastleA_EachQuad_4x4();

    const M aExpected = {
        { 10, 11, 19, 18, 14, 15, 23, 22 },
        {  2, 24,  0, 26,  6, 28,  4, 30 },
        {  1, 27,  3, 25,  5, 31,  7, 29 },
        {  9,  8, 16, 17, 13, 12, 20, 21 },
        { 42, 43, 51, 50, 46, 47, 55, 54 },
        { 34, 56, 32, 58, 38, 60, 36, 62 },
        { 33, 59, 35, 57, 37, 63, 39, 61 },
        { 41, 40, 48, 49, 45, 44, 52, 53 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}



@end
