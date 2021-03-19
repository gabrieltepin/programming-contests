///////BEST SOLUTION//////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, max_p = 0, size = prices.size();
        for(int i = 0; i < size; i++) {
            max_p = prices[i]-min > max_p ? prices[i]-min : max_p;
            min = min > prices[i] ? prices[i] : min;
        }
        return max_p;
    }
};

///////FIRST ATTEMPT//////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minv;
        int INF = numeric_limits<int>::max(); //bastava fazer INF = INT_MAX
        int m = INF, M=0;
        for(int i = 0; i<prices.size();i++){
            minv.push_back(min(m, prices[i]));
            m = min(prices[i], m);
        }
        for(int i = prices.size()-1; i>=0;i--){
            M = max(prices[i]-minv[i], M);
        }
        return M;
    }
};

////////OPTIMIZED ATTEMPT///////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int INF = numeric_limits<int>::max(); //bastava fazer INF = INT_MAX
        int m = INF, M=0;
        for(int i = 0; i<prices.size();i++){
            m = min(m, prices[i]);
            M = max(prices[i]-m, M);
        }
        return M;
    }
};