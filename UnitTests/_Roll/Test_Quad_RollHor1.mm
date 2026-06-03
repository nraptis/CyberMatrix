//
//  TestQuadKIND.m
//  CyberMatrixTests
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyQuad.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface Test_Quad_RollHor1 : XCTestCase

@end

@implementation Test_Quad_RollHor1


- (void)testQuad_RollHor1_4x4_A {
    M88 aBefore = VerifyQuad::SpawnTestMatrixQuadA();
    M88 aAfter = aBefore;

    aAfter.Quad_RollHor1_4x4_A();

    const M aExpected = {
        {  3,  0,  1,  2 },
        {  7,  4,  5,  6 },
        { 11,  8,  9, 10 },
        { 15, 12, 13, 14 }
    };

    if (!VerifyQuad::CheckQuadA(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testQuad_RollHor1_4x4_B {
    M88 aBefore = VerifyQuad::SpawnTestMatrixQuadB();
    M88 aAfter = aBefore;

    aAfter.Quad_RollHor1_4x4_B();

    const M aExpected = {
        {  3,  0,  1,  2 },
        {  7,  4,  5,  6 },
        { 11,  8,  9, 10 },
        { 15, 12, 13, 14 }
    };

    if (!VerifyQuad::CheckQuadB(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testQuad_RollHor1_4x4_C {
    M88 aBefore = VerifyQuad::SpawnTestMatrixQuadC();
    M88 aAfter = aBefore;

    aAfter.Quad_RollHor1_4x4_C();

    const M aExpected = {
        {  3,  0,  1,  2 },
        {  7,  4,  5,  6 },
        { 11,  8,  9, 10 },
        { 15, 12, 13, 14 }
    };

    if (!VerifyQuad::CheckQuadC(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

- (void)testQuad_RollHor1_4x4_D {
    M88 aBefore = VerifyQuad::SpawnTestMatrixQuadD();
    M88 aAfter = aBefore;

    aAfter.Quad_RollHor1_4x4_D();

    const M aExpected = {
        {  3,  0,  1,  2 },
        {  7,  4,  5,  6 },
        { 11,  8,  9, 10 },
        { 15, 12, 13, 14 }
    };

    if (!VerifyQuad::CheckQuadD(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    }
}

@end
