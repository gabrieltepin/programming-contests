class Solution {
public:
    int climbStairs(int n) {
        //Fn = Fn_1 + Fn_2
        double k, Phi, phi, F;
        k = pow(5, 0.5);
        Phi=(1+k)/2;
        phi=(1-k)/2;
        F = (1/k)*(pow(Phi, n+1) - pow(phi, n+1));
        return (int)F;
    }
};