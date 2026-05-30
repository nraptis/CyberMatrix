//
//  VerifyQuarter.hpp
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//

#ifndef VerifyQuarter_hpp
#define VerifyQuarter_hpp

#include <cstddef>
#include "M88.hpp"
#include "Tests.hpp"

class VerifyQuarter {
public:
    static M88 SpawnTestMatrixQuarterA();
    static M88 SpawnTestMatrixQuarterB();
    static M88 SpawnTestMatrixQuarterC();
    static M88 SpawnTestMatrixQuarterD();

    static M QuarterBefore();

    static M QuarterRotAExpected();      // rotate right
    static M QuarterRotBExpected();      // rotate left
    static M QuarterRotCExpected();      // rotate 180

    static M QuarterPinAExpected();
    static M QuarterPinBExpected();

    static M QuarterCastleAExpected();
    static M QuarterCastleBExpected();

    static bool CheckQuarterA(const M88 &pBefore,
                              const M88 &pAfter,
                              const M &pExpected);

    static bool CheckQuarterB(const M88 &pBefore,
                              const M88 &pAfter,
                              const M &pExpected);

    static bool CheckQuarterC(const M88 &pBefore,
                              const M88 &pAfter,
                              const M &pExpected);

    static bool CheckQuarterD(const M88 &pBefore,
                              const M88 &pAfter,
                              const M &pExpected);

    static bool CheckQuarter(std::size_t pQuarter,
                             const M88 &pBefore,
                             const M88 &pAfter,
                             const M &pExpected);

private:
    static M88 SpawnTestMatrixQuarter(std::size_t pQuarter);
};

#endif /* VerifyQuarter_hpp */
