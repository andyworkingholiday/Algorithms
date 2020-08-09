#include <iostream>

long long solution(int w, int h) {
	long long answer = 1;
	int sn = (w < h ? w : h), gcd = 0;
	for (int i = sn; i >= 1; i--) {
        if (w%i == 0 && h%i == 0) {
            gcd = i;
            break;  
        } 
    }
	int sw = w / gcd, sh = h / gcd;
	int square = sw + sh - 1;
	answer = (long long)w * (long long)h - square * gcd;
	return answer;
}