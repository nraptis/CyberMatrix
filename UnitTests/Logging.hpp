//
//  Logging.hpp
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//


#ifndef Logging_hpp
#define Logging_hpp

#include <cstdint>
#include <cstdio>
#include <vector>
#include "M88.hpp"
#include "Tests.hpp"

class Logging {
public:
    static void Log(const char *pLabel, const M &pMatrix);
    static void Log(const char *pLabel, const M88 &pMatrix);
    static void Log(const char *pLabel, const Slice &pSlice);
    
};

#endif /* Logging_hpp */
