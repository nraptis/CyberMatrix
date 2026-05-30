//
//  TestSixteenthRotate.m
//  UnitTests
//
//  Created by nick on 5/29/26.
//


#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifySixteenth.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface TestSixteenthRotate : XCTestCase

@end

@implementation TestSixteenthRotate

- (void)testRotASixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.RotASixA();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.RotASixB();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.RotASixC();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.RotASixD();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.RotASixE();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.RotASixF();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.RotASixG();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.RotASixH();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.RotASixI();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.RotASixJ();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.RotASixK();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.RotASixL();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.RotASixM();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.RotASixN();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.RotASixO();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotASixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.RotASixP();
    const M aExpected = VerifySixteenth::SixteenthRotAExpected();
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

- (void)testRotBSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.RotBSixA();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.RotBSixB();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.RotBSixC();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.RotBSixD();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.RotBSixE();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.RotBSixF();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.RotBSixG();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.RotBSixH();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.RotBSixI();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.RotBSixJ();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.RotBSixK();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.RotBSixL();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.RotBSixM();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.RotBSixN();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.RotBSixO();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

- (void)testRotBSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.RotBSixP();
    const M aExpected = VerifySixteenth::SixteenthRotBExpected();
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

