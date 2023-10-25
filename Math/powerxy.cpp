// LC50 - Pow(x, n)
// Find x^n/2 * x^n/2 
// recursively. 
// If negative power, divide 
// get 1/res
class Solution {
public:
    double rec_pow(double x, unsigned int k)
    {
        if(k == 1) return x;
        if(k == 0) return 1;
        double a = rec_pow(x, k/2);
        if(k&1) return a*a*x;
        return a*a;
    }
    double myPow(double x, int n) {
       unsigned int k = abs(n); 
       double res = rec_pow(x, k);
       if(n < 0) return 1/res; 
       return res;
    }
};
