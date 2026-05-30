//
//  TestQuarterRotate.m
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "VerifyQuarter.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface TestQuarterRotate : XCTestCase

@end

@implementation TestQuarterRotate

- (void)testRotateRightQuarterA {
    
    M88 aBefore = VerifyQuarter::SpawnTestMatrixQuarterA();
    M88 aAfter = aBefore;
    
    aAfter.RotateRightQuarterA();
    //Slice aQuarter = aAfter.GetQuarterA();
    
    // Not implemented yet.
    // aQuarter.RotateRight();
    // aAfter.Paste(aQuarter);
    
    const M aExpected = VerifyQuarter::QuarterRotAExpected();
    
    if (!VerifyQuarter::CheckQuarterA(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Quarter", aExpected);
        
        XCTFail(@"testRotateRightQuarterA failed");
        return;
    } else {
        Logging::Log("Success", aAfter);
    }
    
}

@end

