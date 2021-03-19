class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> v;
        v.push_back(0);
        for(int i=1; i<=num; i++){
            int S=1, k=i;
            while(k&(k-1)){
                S++;
                k&=(k-1);
            }   
            v.push_back(S);
        }
        return v;
    }
};
///////////////optimized solution DP /////////////
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1; //brilliant!
        return ret;
    }
};