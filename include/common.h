#ifndef __QUCOMMON_H
#define __QUCOMMON_H

#include <complex>
#include <limits>
#include <cmath>

typedef std::complex<float> QuAmp;
enum Qubit {ZERO, ONE};
const unsigned char qu_stride=4;
const float TOLERANCE = std::numeric_limits<float>::epsilon();
const QuAmp ZERO_AMP = QuAmp(0,0);
const QuAmp ONE_AMP = QuAmp(1,0);
const QuAmp MONE_AMP = QuAmp(-1, 0);
const QuAmp I_AMP = QuAmp(0,1);
const QuAmp MI_AMP = QuAmp(0,-1);
const QuAmp ROOT2 = QuAmp(1 / std::sqrt(2), 0);

bool isNotZero(QuAmp& amp);

#endif