//
//  TestFullRotate.m
//  UnitTests
//
//  Created by nick on 5/30/26.
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface TestFullRotate : XCTestCase

@end

@implementation TestFullRotate

- (void)testFullRotA {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.RotA();

    const M aExpected = VerifyFull::FullRotAExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullRotB {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.RotB();

    const M aExpected = VerifyFull::FullRotBExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullRotC {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.RotC();

    const M aExpected = VerifyFull::FullRotCExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullBlockRotA {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.BlockRotA();

    const M aExpected = VerifyFull::FullBlockRotAExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullBlockRotB {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.BlockRotB();

    const M aExpected = VerifyFull::FullBlockRotBExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullBlockRotC {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.BlockRotC();

    const M aExpected = VerifyFull::FullBlockRotCExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullPylonRotA {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.PylonRotA();

    const M aExpected = VerifyFull::FullPylonRotAExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullPylonRotB {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.PylonRotB();

    const M aExpected = VerifyFull::FullPylonRotBExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testFullPylonRotC {
    M88 aBefore = VerifyFull::SpawnTestMatrixFull();
    M88 aAfter = aBefore;
    aAfter.PylonRotC();

    const M aExpected = VerifyFull::FullPylonRotCExpected();

    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Full", aExpected);
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

@end
