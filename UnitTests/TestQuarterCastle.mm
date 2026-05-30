//
//  TestQuarterCastle.m
//  UnitTests
//
//  Created by nick on 5/29/26.
//

#import <XCTest/XCTest.h>
#include "M88.hpp"
#include "VerifyQuarter.hpp"
#include "Tests.hpp"
#include "Logging.hpp"

@interface TestQuarterCastle : XCTestCase

@end

@implementation TestQuarterCastle

- (void)testCastleAQuarterA {
    
    M88 aBefore = VerifyQuarter::SpawnTestMatrixQuarterA();
    M88 aAfter = aBefore;
    
    aAfter.CastleAQuarterA();
    
    const M aExpected = VerifyQuarter::QuarterCastleAExpected();
    
    if (!VerifyQuarter::CheckQuarterA(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Quarter", aExpected);
        
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}

- (void)testCastleBQuarterB {
    
    M88 aBefore = VerifyQuarter::SpawnTestMatrixQuarterA();
    M88 aAfter = aBefore;
    
    aAfter.CastleBQuarterA();
    
    const M aExpected = VerifyQuarter::QuarterCastleBExpected();
    
    if (!VerifyQuarter::CheckQuarterA(aBefore, aAfter, aExpected)) {
        Logging::Log("Before", aBefore);
        Logging::Log("After", aAfter);
        Logging::Log("Expected Quarter", aExpected);
        
        XCTFail(@"%s failed", sel_getName(_cmd));
        return;
    } else {
        
        NSLog(@"%s succeeded", sel_getName(_cmd));
        Logging::Log("Success", aAfter);
    }
}


@end

