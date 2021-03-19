//This code gave TLE because of O(2^n) time complexity
class Solution {
public:
    //state 0 -> not bought yet
    //state 1 -> already bought
    int getMax (vector<int>& prices, int i, int S, bool state){
        if(i>=prices.size()) return S;
        int x=0;
        if (state == 0){
            x += max(getMax(prices, i+1, S, 0), getMax(prices, i+1, S-prices[i], 1));
        }
        else{
            x += max(getMax(prices, i+1, S, 1), getMax(prices, i+2, S+prices[i], 0));
        }
        return x;
    }
    int maxProfit(vector<int>& prices) {
        return getMax(prices, 0, 0, 0);
    }
}; 

//solution optimized
