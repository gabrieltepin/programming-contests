//like the staricase problem
class Solution {
public:
    int rob(vector<int>& nums) {
        int L = nums.size();
        if(L==0) return 0;
        if(L==1) return nums[0];
        if(L==2) return max(nums[0], nums[1]);
        int S=max(nums[0], nums[1]), s=nums[0], tmp;
        for(int i=2; i<L;i++){   
            tmp=s;
            s=S;
            S=max(S, tmp+nums[i]);
        }
        return S;
    }
};