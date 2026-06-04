//
//  Test_Full_HeronD.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_HeronD : XCTestCase

@end

@implementation Test_Full_HeronD

- (void)testFull_HeronD_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronD_4x4();

    const M aExpected = {
        {  4,  5, 20, 21, 32, 33, 48, 49 },
        { 12, 13, 28, 29, 40, 41, 56, 57 },
        {  6,  7, 22, 23, 34, 35, 50, 51 },
        { 14, 15, 30, 31, 42, 43, 58, 59 },
        {  0,  1, 16, 17, 36, 37, 52, 53 },
        {  8,  9, 24, 25, 44, 45, 60, 61 },
        {  2,  3, 18, 19, 38, 39, 54, 55 },
        { 10, 11, 26, 27, 46, 47, 62, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeronD_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronD_EachQuad_4x4();

    const M aExpected = {
        {  2, 10, 16, 24,  6, 14, 20, 28 },
        {  3, 11, 17, 25,  7, 15, 21, 29 },
        {  0,  8, 18, 26,  4, 12, 22, 30 },
        {  1,  9, 19, 27,  5, 13, 23, 31 },
        { 34, 42, 48, 56, 38, 46, 52, 60 },
        { 35, 43, 49, 57, 39, 47, 53, 61 },
        { 32, 40, 50, 58, 36, 44, 54, 62 },
        { 33, 41, 51, 59, 37, 45, 55, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_HeronD_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_HeronD_8x8();

    const M aExpected = {
        {  6, 14, 22, 30, 32, 40, 48, 56 },
        {  7, 15, 23, 31, 37, 45, 53, 61 },
        {  4, 12, 20, 28, 38, 46, 54, 62 },
        {  5, 13, 21, 29, 35, 43, 51, 59 },
        {  2, 10, 18, 26, 36, 44, 52, 60 },
        {  3, 11, 19, 27, 33, 41, 49, 57 },
        {  0,  8, 16, 24, 34, 42, 50, 58 },
        {  1,  9, 17, 25, 39, 47, 55, 63 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
