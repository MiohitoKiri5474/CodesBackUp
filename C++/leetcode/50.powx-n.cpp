class Solution {
public:
    double myPow(double x, int n) {
        double res = 0, base = x;
		while ( n ) {
			if ( n & 1 )
				res *= base;
			base *= base;
			n >>= 1;
		}

		return res;
    }
};
