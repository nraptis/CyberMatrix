//
//  Test_Full_InglewoodC.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_InglewoodC : XCTestCase

@end

@implementation Test_Full_InglewoodC

- (void)testFull_InglewoodC_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_InglewoodC_4x4();

    const M aExpected = {
        { 54, 55, 50, 51,  6,  7,  2,  3 },
        { 62, 63, 58, 59, 14, 15, 10, 11 },
        { 52, 53,  4,  5, 36, 37, 20, 21 },
        { 60, 61, 12, 13, 44, 45, 28, 29 },
        { 34, 35, 38, 39, 18, 19, 22, 23 },
        { 42, 43, 46, 47, 26, 27, 30, 31 },
        {  0,  1, 48, 49, 16, 17, 32, 33 },
        {  8,  9, 56, 57, 24, 25, 40, 41 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_InglewoodC_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_InglewoodC_EachQuad_4x4();

    const M aExpected = {
        { 27, 25,  3,  1, 31, 29,  7,  5 },
        { 26,  2, 18, 10, 30,  6, 22, 14 },
        { 17, 19,  9, 11, 21, 23, 13, 15 },
        {  0, 24,  8, 16,  4, 28, 12, 20 },
        { 59, 57, 35, 33, 63, 61, 39, 37 },
        { 58, 34, 50, 42, 62, 38, 54, 46 },
        { 49, 51, 41, 43, 53, 55, 45, 47 },
        { 32, 56, 40, 48, 36, 60, 44, 52 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_InglewoodC_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_InglewoodC_8x8();

    const M aExpected = {
        { 62, 43, 46, 59, 12, 25, 28,  9 },
        { 20,  1,  4, 17,  6, 19, 22,  3 },
        { 60, 63, 44, 47, 14, 13, 30, 29 },
        { 54, 21, 38,  5, 36,  7, 52, 23 },
        { 40, 61, 56, 45, 26, 15, 10, 31 },
        { 34, 55, 50, 39, 48, 37, 32, 53 },
        { 42, 41, 58, 57, 24, 27,  8, 11 },
        {  0, 35, 16, 51, 18, 49,  2, 33 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
