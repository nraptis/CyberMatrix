//
//  TestSixteenthSnake.m
//  UnitTests
//
//  Created by nick on 5/29/26.
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifySixteenth.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface TestSixteenthSnake : XCTestCase

@end

@implementation TestSixteenthSnake

- (void)testSnakeASixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.SnakeASixA();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.SnakeASixB();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.SnakeASixC();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.SnakeASixD();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.SnakeASixE();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.SnakeASixF();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.SnakeASixG();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.SnakeASixH();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.SnakeASixI();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.SnakeASixJ();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.SnakeASixK();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.SnakeASixL();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.SnakeASixM();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.SnakeASixN();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.SnakeASixO();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeASixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.SnakeASixP();
    const M aExpected = VerifySixteenth::SixteenthSnakeAExpected();
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

- (void)testSnakeBSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixA();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixB();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixC();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixD();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixE();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixF();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixG();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixH();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixI();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixJ();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixK();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixL();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixM();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixN();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixO();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeBSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.SnakeBSixP();
    const M aExpected = VerifySixteenth::SixteenthSnakeBExpected();
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

- (void)testSnakeCSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixA();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixB();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixC();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixD();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixE();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixF();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixG();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixH();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixI();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixJ();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixK();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixL();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixM();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixN();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixO();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeCSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.SnakeCSixP();
    const M aExpected = VerifySixteenth::SixteenthSnakeCExpected();
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

- (void)testSnakeDSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixA();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixB();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixC();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixD();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixE();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixF();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixG();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixH();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixI();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixJ();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixK();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixL();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixM();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixN();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixO();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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

- (void)testSnakeDSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.SnakeDSixP();
    const M aExpected = VerifySixteenth::SixteenthSnakeDExpected();
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
