//
//  Test_Full_FalconD.mm
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_FalconD : XCTestCase

@end

@implementation Test_Full_FalconD

- (void)testFull_FalconD_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconD_4x4();

    const M aExpected = {
        {  0,  1, 16, 17, 36, 37, 52, 53 },
        {  8,  9, 24, 25, 44, 45, 60, 61 },
        {  6,  7, 22, 23, 38, 39, 54, 55 },
        { 14, 15, 30, 31, 46, 47, 62, 63 },
        {  4,  5, 20, 21, 32, 33, 48, 49 },
        { 12, 13, 28, 29, 40, 41, 56, 57 },
        {  2,  3, 18, 19, 34, 35, 50, 51 },
        { 10, 11, 26, 27, 42, 43, 58, 59 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FalconD_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconD_EachQuad_4x4();

    const M aExpected = {
        {  0,  8, 18, 26,  4, 12, 22, 30 },
        {  3, 11, 19, 27,  7, 15, 23, 31 },
        {  2, 10, 16, 24,  6, 14, 20, 28 },
        {  1,  9, 17, 25,  5, 13, 21, 29 },
        { 32, 40, 50, 58, 36, 44, 54, 62 },
        { 35, 43, 51, 59, 39, 47, 55, 63 },
        { 34, 42, 48, 56, 38, 46, 52, 60 },
        { 33, 41, 49, 57, 37, 45, 53, 61 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_FalconD_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_FalconD_8x8();

    const M aExpected = {
        {  0,  8, 16, 24, 38, 46, 54, 62 },
        {  7, 15, 23, 31, 39, 47, 55, 63 },
        {  6, 14, 22, 30, 36, 44, 52, 60 },
        {  5, 13, 21, 29, 37, 45, 53, 61 },
        {  4, 12, 20, 28, 34, 42, 50, 58 },
        {  3, 11, 19, 27, 35, 43, 51, 59 },
        {  2, 10, 18, 26, 32, 40, 48, 56 },
        {  1,  9, 17, 25, 33, 41, 49, 57 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
