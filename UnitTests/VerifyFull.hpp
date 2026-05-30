//
//  VerifyFull.hpp
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//

#ifndef VerifyFull_hpp
#define VerifyFull_hpp

#include "M88.hpp"
#include "Tests.hpp"

class VerifyFull {
public:
    static M88 SpawnTestMatrixFull();

    static M FullBefore();

    static M FullRotAExpected();          // full 8x8 rotate right
    static M FullRotBExpected();          // full 8x8 rotate left
    static M FullRotCExpected();          // full 8x8 rotate 180

    // Block rotation:
    // Treat the full 8x8 matrix as a 2x2 grid of 4x4 quarter blocks.
    // The 4x4 blocks move as units; the bytes inside each block do not rotate.
    static M FullBlockRotAExpected();     // quarter-block grid rotate right
    static M FullBlockRotBExpected();     // quarter-block grid rotate left
    static M FullBlockRotCExpected();     // quarter-block grid rotate 180

    // Pylon rotation:
    // Treat the full 8x8 matrix as a 4x4 grid of 2x2 sixteenth pylons.
    // The 2x2 pylons move as units; the bytes inside each pylon do not rotate.
    static M FullPylonRotAExpected();     // sixteenth-grid rotate right
    static M FullPylonRotBExpected();     // sixteenth-grid rotate left
    static M FullPylonRotCExpected();     // sixteenth-grid rotate 180

    static bool CheckFull(const M88 &pBefore,
                          const M88 &pAfter,
                          const M &pExpected);
};

#endif /* VerifyFull_hpp */
