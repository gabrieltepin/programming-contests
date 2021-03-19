class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int M=INT_MIN, S=0;
        for(int i =0; i< nums.size(); i++){
            S += nums[i];
            M = max(S, M);
            S = max(0, S);
        }
        return M;   
    }
};