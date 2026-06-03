//
//  TestFullKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Full_PinB : XCTestCase

@end

@implementation Test_Full_PinB

- (void)testFull_PinB_8x8 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PinB_8x8();

    const M aExpected = {
        {  7, 15, 23, 31, 39, 47, 55, 63 },
        {  6, 49, 41, 33, 25, 17,  9, 62 },
        {  5, 50, 21, 29, 37, 45, 10, 61 },
        {  4, 51, 20, 35, 27, 44, 11, 60 },
        {  3, 52, 19, 36, 28, 43, 12, 59 },
        {  2, 53, 18, 26, 34, 42, 13, 58 },
        {  1, 54, 46, 38, 30, 22, 14, 57 },
        {  0,  8, 16, 24, 32, 40, 48, 56 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_PinB_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PinB_4x4();

    const M aExpected = {
        {  6,  7, 22, 23, 38, 39, 54, 55 },
        { 14, 15, 30, 31, 46, 47, 62, 63 },
        {  4,  5, 34, 35, 18, 19, 52, 53 },
        { 12, 13, 42, 43, 26, 27, 60, 61 },
        {  2,  3, 36, 37, 20, 21, 50, 51 },
        { 10, 11, 44, 45, 28, 29, 58, 59 },
        {  0,  1, 16, 17, 32, 33, 48, 49 },
        {  8,  9, 24, 25, 40, 41, 56, 57 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testFull_PinB_EachQuad_4x4 {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;

    aAfter.Full_PinB_EachQuad_4x4();

    const M aExpected = {
        {  3, 11, 19, 27,  7, 15, 23, 31 },
        {  2, 17,  9, 26,  6, 21, 13, 30 },
        {  1, 18, 10, 25,  5, 22, 14, 29 },
        {  0,  8, 16, 24,  4, 12, 20, 28 },
        { 35, 43, 51, 59, 39, 47, 55, 63 },
        { 34, 49, 41, 58, 38, 53, 45, 62 },
        { 33, 50, 42, 57, 37, 54, 46, 61 },
        { 32, 40, 48, 56, 36, 44, 52, 60 }
    };

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
