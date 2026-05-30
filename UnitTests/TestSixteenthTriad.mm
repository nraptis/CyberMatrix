//
//  TestSixteenthTriad.m
//  UnitTests
//
//  Created by nick on 5/29/26.
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifySixteenth.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface TestSixteenthTriad : XCTestCase

@end

@implementation TestSixteenthTriad

- (void)testTriadAASixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadAASixA();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadAASixB();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadAASixC();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadAASixD();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadAASixE();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadAASixF();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadAASixG();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadAASixH();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadAASixI();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadAASixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadAASixK();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadAASixL();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadAASixM();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadAASixN();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadAASixO();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadAASixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadAASixP();
    const M aExpected = VerifySixteenth::SixteenthTriadAAExpected();
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

- (void)testTriadABSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadABSixA();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadABSixB();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadABSixC();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadABSixD();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadABSixE();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadABSixF();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadABSixG();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadABSixH();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadABSixI();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadABSixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadABSixK();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadABSixL();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadABSixM();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadABSixN();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadABSixO();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadABSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadABSixP();
    const M aExpected = VerifySixteenth::SixteenthTriadABExpected();
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

- (void)testTriadBASixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadBASixA();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadBASixB();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadBASixC();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadBASixD();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadBASixE();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadBASixF();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadBASixG();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadBASixH();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadBASixI();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadBASixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadBASixK();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadBASixL();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadBASixM();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadBASixN();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadBASixO();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBASixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadBASixP();
    const M aExpected = VerifySixteenth::SixteenthTriadBAExpected();
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

- (void)testTriadBBSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixA();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixB();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixC();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixD();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixE();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixF();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixG();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixH();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixI();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixK();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixL();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixM();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixN();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixO();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadBBSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadBBSixP();
    const M aExpected = VerifySixteenth::SixteenthTriadBBExpected();
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

- (void)testTriadCASixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadCASixA();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadCASixB();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadCASixC();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadCASixD();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadCASixE();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadCASixF();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadCASixG();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadCASixH();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadCASixI();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadCASixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadCASixK();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadCASixL();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadCASixM();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadCASixN();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadCASixO();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCASixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadCASixP();
    const M aExpected = VerifySixteenth::SixteenthTriadCAExpected();
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

- (void)testTriadCBSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixA();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixB();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixC();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixD();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixE();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixF();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixG();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixH();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixI();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixK();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixL();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixM();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixN();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixO();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadCBSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadCBSixP();
    const M aExpected = VerifySixteenth::SixteenthTriadCBExpected();
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

- (void)testTriadDASixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadDASixA();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadDASixB();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadDASixC();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadDASixD();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadDASixE();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadDASixF();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadDASixG();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadDASixH();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadDASixI();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadDASixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadDASixK();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadDASixL();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadDASixM();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadDASixN();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadDASixO();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDASixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadDASixP();
    const M aExpected = VerifySixteenth::SixteenthTriadDAExpected();
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

- (void)testTriadDBSixA {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthA();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixA();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixB {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthB();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixB();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixC {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthC();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixC();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixD {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthD();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixD();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixE {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthE();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixE();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixF {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthF();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixF();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixG {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthG();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixG();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixH {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthH();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixH();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixI {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthI();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixI();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixJ {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthJ();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixJ();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixK {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthK();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixK();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixL {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthL();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixL();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixM {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthM();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixM();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixN {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthN();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixN();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixO {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthO();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixO();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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

- (void)testTriadDBSixP {
    M88 aBefore = VerifySixteenth::SpawnTestMatrixSixteenthP();
    M88 aAfter = aBefore;
    aAfter.TriadDBSixP();
    const M aExpected = VerifySixteenth::SixteenthTriadDBExpected();
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
