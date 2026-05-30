//
//  TestSixteenthFlip.m
//  UnitTests
//
//  Created by nick on 5/29/26.
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifySixteenth.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface TestSixteenthFlip : XCTestCase

@end

@implementation TestSixteenthFlip

- (void)testFlipASixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.FlipASixA();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthA(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.FlipASixB();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthB(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.FlipASixC();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthC(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.FlipASixD();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthD(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.FlipASixE();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthE(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.FlipASixF();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthF(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.FlipASixG();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthG(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.FlipASixH();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthH(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.FlipASixI();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthI(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.FlipASixJ();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthJ(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.FlipASixK();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthK(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.FlipASixL();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthL(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.FlipASixM();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthM(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.FlipASixN();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthN(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.FlipASixO();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthO(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipASixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.FlipASixP();
    const M aExpected = VerifySixteenth::SixteenthFlipAExpected();
    if (!VerifySixteenth::CheckSixteenthP(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.FlipBSixA();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthA(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.FlipBSixB();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthB(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.FlipBSixC();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthC(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.FlipBSixD();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthD(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.FlipBSixE();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthE(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.FlipBSixF();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthF(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.FlipBSixG();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthG(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.FlipBSixH();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthH(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.FlipBSixI();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthI(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.FlipBSixJ();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthJ(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.FlipBSixK();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthK(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.FlipBSixL();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthL(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.FlipBSixM();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthM(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.FlipBSixN();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthN(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.FlipBSixO();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthO(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFlipBSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.FlipBSixP();
    const M aExpected = VerifySixteenth::SixteenthFlipBExpected();
    if (!VerifySixteenth::CheckSixteenthP(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Sixteenth", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

@end

