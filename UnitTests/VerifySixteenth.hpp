//
//  VerifySixteenth.hpp
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//

#ifndef VerifySixteenth_hpp
#define VerifySixteenth_hpp

#include <cstddef>
#include "M88.hpp"
#include "Tests.hpp"

class VerifySixteenth {
public:
    static M88 SpawnTestMatrixSixteenthA();
    static M88 SpawnTestMatrixSixteenthB();
    static M88 SpawnTestMatrixSixteenthC();
    static M88 SpawnTestMatrixSixteenthD();

    static M88 SpawnTestMatrixSixteenthE();
    static M88 SpawnTestMatrixSixteenthF();
    static M88 SpawnTestMatrixSixteenthG();
    static M88 SpawnTestMatrixSixteenthH();

    static M88 SpawnTestMatrixSixteenthI();
    static M88 SpawnTestMatrixSixteenthJ();
    static M88 SpawnTestMatrixSixteenthK();
    static M88 SpawnTestMatrixSixteenthL();

    static M88 SpawnTestMatrixSixteenthM();
    static M88 SpawnTestMatrixSixteenthN();
    static M88 SpawnTestMatrixSixteenthO();
    static M88 SpawnTestMatrixSixteenthP();

    static M SixteenthBefore();

    
    static M SixteenthRotAExpected();      // rotate right
    static M SixteenthRotBExpected();      // rotate left
    
    static M SixteenthFlipAExpected();     // horizontal
    static M SixteenthFlipBExpected();     // vertical
    
    static M SixteenthTriadAAExpected();     // BCAD
    static M SixteenthTriadABExpected();     // CABD
    static M SixteenthTriadBAExpected();     // BDCA
    static M SixteenthTriadBBExpected();     // DACB
    static M SixteenthTriadCAExpected();     // CBDA
    static M SixteenthTriadCBExpected();     // DBAC
    static M SixteenthTriadDAExpected();     // ACDB
    static M SixteenthTriadDBExpected();     // ADBC
    
    static M SixteenthSnakeAExpected();
    static M SixteenthSnakeBExpected();
    static M SixteenthSnakeCExpected();
    static M SixteenthSnakeDExpected();
    

    static bool CheckSixteenthA(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthB(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthC(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthD(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthE(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthF(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthG(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthH(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthI(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthJ(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthK(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthL(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthM(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthN(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthO(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenthP(const M88 &pBefore,
                                const M88 &pAfter,
                                const M &pExpected);

    static bool CheckSixteenth(std::size_t pSixteenth,
                               const M88 &pBefore,
                               const M88 &pAfter,
                               const M &pExpected);

private:
    static M88 SpawnTestMatrixSixteenth(std::size_t pSixteenth);
};

#endif /* VerifySixteenth_hpp */
