#pragma once
#include <math.h>
#include "ofMathConstants.h"

class TweenFunctions {
public:
	static float easeLinear(float a_t, float a_b, float a_c, float a_d) {
		return a_c * a_t/a_d + a_b;
	}
	
	static float easeInQuad(float a_t, float a_b, float a_c, float a_d) {
    a_t /= a_d;
		return a_c * a_t * a_t + a_b;
	}
	static float easeOutQuad(float a_t, float a_b, float a_c, float a_d) {
    a_t /= a_d;
		return - a_c * a_t * (a_t-2.f) + a_b;
	}
	static float easeInOutQuad(float a_t, float a_b, float a_c, float a_d) {
		if ( (a_t /= a_d/2.f) < 1.f) return a_c/2.f * a_t * a_t + a_b;
    --a_t;
		return -a_c/2 * ( a_t * (a_t-2.f) - 1.f) + a_b;
	}
	
	
	static float easeInCubic(float a_t, float a_b, float a_c, float a_d) {
		return a_c * pow((a_t / a_d), 3) + a_b;
	}
	static float easeOutCubic(float a_t, float a_b, float a_c, float a_d) {
		return a_c * (pow(a_t/a_d-1.f, 3) + 1.f) + a_b;
	}
	static float easeInOutCubic(float a_t, float a_b, float a_c, float a_d) {
		if ( (a_t/=a_d/2) < 1.f) return a_c/2.f * pow(a_t, 3) + a_b;
		return a_c/2.f * (pow(a_t-2.f, 3) + 2.f) + a_b;
	}
	
	
	static float easeInQuart(float a_t, float a_b, float a_c, float a_d) {
		return a_c * pow(a_t/a_d, 4) + a_b;
	}
	static float easeOutQuart(float a_t, float a_b, float a_c, float a_d) {
		return -a_c * (pow(a_t/a_d-1, 4) - 1.f) + a_b;
	}
	static float easeInOutQuart(float a_t, float a_b, float a_c, float a_d) {
		if ( (a_t/=a_d/2.f) < 1.f) return a_c/2.f * pow(a_t, 4) + a_b;
		return -a_c/2.f * (pow(a_t-2, 4) -2.f) + a_b;
	}
	
	
	static float easeInQuint(float a_t, float a_b, float a_c, float a_d) {
		return a_c * pow(a_t/a_d, 5) + a_b;
	}
	static float easeOutQuint(float a_t, float a_b, float a_c, float a_d) {
		return a_c * (pow(a_t/a_d-1, 5) + 1.f) + a_b;
	}
	static float easeInOutQuint(float a_t, float a_b, float a_c, float a_d) {
		if ( (a_t/=a_d/2.f) < 1.f) return a_c/2 * pow(a_t, 5) + a_b;
		return a_c/2 * (pow(a_t-2.f, 5) + 2.f) + a_b;
	}
	
	
	static float easeInSine(float a_t, float a_b, float a_c, float a_d) {
		return a_c * (1.f - cos(a_t/a_d * HALF_PI)) + a_b;
	}
	static float easeOutSine(float a_t, float a_b, float a_c, float a_d) {
		return a_c * sin(a_t/a_d * HALF_PI) + a_b;
	}
	static float easeInOutSine(float a_t, float a_b, float a_c, float a_d) {
		return a_c/2 * (1.f - cos(PI * a_t/a_d)) + a_b;
	}
	
	
	static float easeInExpo(float a_t, float a_b, float a_c, float a_d) {
		return a_c * pow(2.f, 10.f * (a_t/a_d - 1.f)) + a_b;
	}
	static float easeOutExpo(float a_t, float a_b, float a_c, float a_d) {
		return a_c * (-pow(2.f, -10.f * a_t/a_d) + 1.f) + a_b;
	}
	static float easeInOutExpo(float a_t, float a_b, float a_c, float a_d) {
		if ( (a_t/=a_d/2.f) < 1.f) return a_c/2 * pow(2.f, 10.f * (a_t - 1.f)) + a_b;
		return a_c/2 * (-pow(2.f, -10.f * --a_t) + 2.f) + a_b;
	}
	
	
	static float easeInCirc(float a_t, float a_b, float a_c, float a_d) {
    a_t /= a_d;
		return a_c * (1.f - sqrt(1.f - a_t * a_t)) + a_b;
	}
	static float easeOutCirc(float a_t, float a_b, float a_c, float a_d) {
    a_t=a_t/a_d-1.f;
		return a_c * sqrt(1.f - a_t * a_t) + a_b;
	}
	static float easeInOutCirc(float a_t, float a_b, float a_c, float a_d) {
		if ( (a_t/=a_d/2.f) < 1.f) return a_c/2.f * (1.f - sqrt(1.f - a_t * a_t)) + a_b;
    a_t-=2.f;
		return a_c/2.f * (sqrt(1.f - a_t * a_t) + 1.f) + a_b;
	}
	
	
	static float easeInElastic(float a_t, float a_b, float a_c, float a_d, float a_p = 0, float a_a = 0) {
		if (a_t==0) return a_b;
		if ((a_t/=a_d)==1) return a_b+a_c;
		a_p = a_p == 0 ? a_d * .3 : a_p;
		float a_s;
		//float a = !Boolean(p_params) || isNaN(p_params.amplitude) ? 0 : p_params.amplitude;
		float a_a_c = a_c < 0 ? a_c * - 1 : a_c;
		if (!(a_a) || a_a < a_a_c) {
			a_a = a_c;
			a_s = a_p/4;
		} else {
			a_s = a_p/(2*PI) * asin (a_c/a_a);
		}
    a_t-=1;
		return -(a_a*pow(2,10*a_t) * sin( (a_t*a_d-a_s)*(2*PI)/a_p )) + a_b;
	}
	static float easeOutElastic(float a_t, float a_b, float a_c, float a_d, float a_p = 0, float a_a = 0) {
		if (a_t==0) return a_b;
		if ((a_t/=a_d)==1) return a_b+a_c;
		//float p = !Boolean(p_params) || isNaN(p_params.period) ? d*.3 : p_params.period;
		a_p = a_p == 0 ? a_d * .3 : a_p;
		float a_s;
		//float a = !Boolean(p_params) || isNaN(p_params.amplitude) ? 0 : p_params.amplitude;
		float a_a_c = a_c < 0 ? a_c * - 1 : a_c;
		if (!(a_a) || a_a < a_a_c) {
			a_a = a_c;
			a_s = a_p/4;
		} else {
			a_s = a_p/(2*PI) * asin (a_c/a_a);
		}
		return (a_a*pow(2,-10*a_t) *sin( (a_t*a_d-a_s)*(2*PI)/a_p ) + a_c + a_b);
	}
	static float easeInOutElastic(float a_t, float a_b, float a_c, float a_d, float a_p = 0, float a_a = 0) {
		if (a_t==0) return a_b;
		if ((a_t/=a_d/2)==2) return a_b+a_c;
		//var p:Number = !Boolean(p_params) || isNaN(p_params.period) ? d*(.3*1.5) : p_params.period;
		a_p = a_p == 0 ? a_d*(.3*1.5) : a_p;
		float a_s;
		//var a:Number = !Boolean(p_params) || isNaN(p_params.amplitude) ? 0 : p_params.amplitude;
		float a_a_c = a_c < 0 ? a_c * - 1 : a_c;
		if (!(a_a) || a_a < a_a_c) {
			a_a = a_c;
			a_s = a_p/4;
		} else {
			a_s = a_p/(2*PI) * asin (a_c/a_a);
		}
    a_t-=1;
		if (a_t < 0) return -.5*(a_a*pow(2,10*a_t) * sin( (a_t*a_d-a_s)*(2*PI)/a_p )) + a_b;
		return a_a*pow(2,-10*a_t) * sin( (a_t*a_d-a_s)*(2*PI)/a_p )*.5 + a_c + a_b;
	}
	static float easeOutInElastic(float a_t, float a_b, float a_c, float a_d, float a_p = 0, float a_a = 0) {
		if (a_t < a_d/2) return easeOutElastic (a_t*2, a_b, a_c/2, a_d, a_p, a_a);
		return easeInElastic((a_t*2)-a_d, a_b+a_c/2, a_c/2, a_d, a_p, a_a);
	}
	
	
	static float easeInBack(float a_t, float a_b, float a_c, float a_d, float a_p = 0) {
		// var s:Number = !Boolean(p_params) || isNaN(p_params.overshoot) ? 1.70158 : p_params.overshoot;
		a_p = a_p == 0 ? 1.70158 : a_p;
    a_t/=a_d;
		return a_c*a_t*a_t*((a_p+1)*a_t - a_p) + a_b;
	}
	static float easeOutBack(float a_t, float a_b, float a_c, float a_d, float a_p = 0) {
		//var s:Number = !Boolean(p_params) || isNaN(p_params.overshoot) ? 1.70158 : p_params.overshoot;
		a_p = a_p == 0 ? 1.70158 : a_p;
    a_t=a_t/a_d-1;
		return a_c*(a_t*a_t*((a_p+1)*a_t + a_p) + 1) + a_b;
	}
	static float easeInOutBack(float a_t, float a_b, float a_c, float a_d, float a_p = 0) {
		//var s:Number = !Boolean(p_params) || isNaN(p_params.overshoot) ? 1.70158 : p_params.overshoot;
		a_p = a_p == 0 ? 1.70158 : a_p;
    a_p*=(1.525);
		if ((a_t/=a_d/2) < 1) return a_c/2*(a_t*a_t*((a_p+1)*a_t - a_p)) + a_b;
    a_t-=2;
		return a_c/2*(a_t*a_t*((a_p+1)*a_t + a_p) + 2) + a_b;
	}
	static float easeOutInBack(float a_t, float a_b, float a_c, float a_d, float a_p = 0) {
		if (a_t < a_d/2) return easeOutBack(a_t*2, a_b, a_c/2, a_d, a_p);
		return easeInBack((a_t*2)-a_d, a_b+a_c/2, a_c/2, a_d, a_p);
	}
	
	
	
	
	static float easeInBounce(float a_t, float a_b, float a_c, float a_d) {
		return a_c - easeOutBounce (a_d-a_t, 0, a_c, a_d) + a_b;
	}
	
	static float easeOutBounce(float a_t, float a_b, float a_c, float a_d) {
		if ((a_t/=a_d) < (1/2.75)) {
			return a_c*(7.5625*a_t*a_t) + a_b;
		} else if (a_t < (2/2.75)) {
      a_t-=(1.5/2.75);
			return a_c*(7.5625*a_t * a_t + .75) + a_b;
		} else if (a_t < (2.5/2.75)) {
      a_t-=(2.25/2.75);
			return a_c*(7.5625*a_t * a_t + .9375) + a_b;
		} else {
      a_t-=(2.625/2.75);
      return a_c*(7.5625*a_t * a_t + .984375) + a_b;
		}
	}
	
	static float easeInOutBounce(float a_t, float a_b, float a_c, float a_d) {
		if (a_t < a_d/2) return easeInBounce (a_t*2, 0, a_c, a_d) * .5 + a_b;
		else return easeOutBounce (a_t*2-a_d, 0, a_c, a_d) * .5 + a_c*.5 + a_b;
	}
	
	static float easeOutInBounce(float a_t, float a_b, float a_c, float a_d) {
		if (a_t < a_d/2) return easeOutBounce (a_t*2, a_b, a_c/2, a_d);
		return easeInBounce((a_t*2)-a_d, a_b+a_c/2, a_c/2, a_d);
	}
	
};
