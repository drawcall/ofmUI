#include "ofmMatrix.h"
#include "ofmMathUtil.h"
#include "ofmMathConsts.h"
#include <math.h>

using namespace std;

void ofmMatrix::append(
                       float _a ,
                       float _b ,
                       float _c ,
                       float _d ,
                       float _tx ,
                       float _ty ) {
    float a1 = a;
    float b1 = b;
    float c1 = c;
    float d1 = d;
    
    if (_a != 1 || _b != 0 || _c != 0 || _d != 1) {
        a = a1 * _a + c1 * _b;
        b = b1 * _a + d1 * _b;
        c = a1 * _c + c1 * _d;
        d = b1 * _c + d1 * _d;
    }
    
    tx = a1 * _tx + c1 * _ty + tx;
    ty = b1 * _tx + d1 * _ty + ty;
}

void ofmMatrix::identity() {
    a = 1;
    b = 0;
    c = 0;
    d = 1;
    tx = 0;
    ty = 0;
}

void ofmMatrix::appendMatrix(ofmMatrix& matrix) {
    append(matrix.a, matrix.b, matrix.c, matrix.d, matrix.tx, matrix.ty);
}

void ofmMatrix::appendTransform(float x, float y, float scaleX, float scaleY,
                                float rotation, float regX, float regY) {
    float cosa = 0;
    float sina = 0;
    
    if (ofmMathUtil::mod(rotation, 360) != 0) {
        float r = rotation * OFM_PI_180;
        cosa = cos(r);
        sina = sin(r);
    } else {
        cosa = 1;
        sina = 0;
    }
    
    append(
           cosa * scaleX, sina * scaleX, -sina * scaleY, cosa * scaleY, x, y);
    
//    if (regX != 0 || regY != 0) {
//        tx -= regX * a + regY * c;
//        ty -= regX * b + regY * d;
//    }
}

string ofmMatrix::toString(){
    string sa = " a:" + ofmMathUtil::toString(a, 2);
    string sb = " b:" + ofmMathUtil::toString(b, 2);
    string sc = " c:" + ofmMathUtil::toString(c, 2);
    string sd = " d:" + ofmMathUtil::toString(d, 2);
    string sx = " tx:" + ofmMathUtil::toString(tx, 2);
    string sy = " ty:" + ofmMathUtil::toString(ty, 2);
    
    return sa + sb + sc + sd + sx + sy;
}

