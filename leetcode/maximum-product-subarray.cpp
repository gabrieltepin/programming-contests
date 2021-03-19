//Like kadane's algorithm, but swapping values...
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==0)return 0;
        int minP=nums[0], maxP=nums[0], res=nums[0];
        for(int i =1; i<nums.size();i++){
            if(nums[i]<0) swap(maxP, minP);
            maxP=max(maxP*nums[i], nums[i]);
            minP=min(minP*nums[i], nums[i]);
            res = max(maxP, res);
        }
        return res;
    }
};