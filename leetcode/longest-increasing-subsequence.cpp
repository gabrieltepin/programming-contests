//My solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector <int> v;
        vector<int>::iterator iter;
        v.push_back(nums[0]);
        for (int i = 1; i <nums.size(); i++){
            iter = lower_bound(v.begin(), v.end(), nums[i]);
            int p = (int)(iter - v.begin());
            if(p<v.size() && nums[i]<=v[p]) v[p]=nums[i];
            else v.push_back(nums[i]);
        }
        return v.size();
    }
};

//compact solution
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}