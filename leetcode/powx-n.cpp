class Solution {
public:
    double myPow(double x, long int n) {
        if(n==0) return 1;
        if(n==1 || x==1) return x;
        bool isneg=0;
        if(n<0){
            isneg=1;
            n=-n;
        }
        double pow=1.0;
        while (n){
            if(n&1) 
                pow*=x;
            x*=x;
            n=n>>1;
        }
        if(isneg) return 1.0/pow;
        return pow;
    }
};

//concise solution
double myPow(double x, int n) {
    if (n==0) return 1;
    if (n==1) return x;
    if (n==-1) return 1/x;
    return myPow(x*x,n/2)*(n%2==0?1:n>0?x:1/x);
}

//another solution
class Solution
{
public:
    double myPow(double x, int n)
    {
        bitset<32> bit(abs(n));
        double result = 1;
        for(int i = bit.size()-1; i >= 0; i--)
        {
            result*=result;
            if(bit[i] == 1)
                result *=x;
        }
        return (n >= 0)?result : 1/result;
    }
};