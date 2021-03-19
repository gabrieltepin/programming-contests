class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> sol(2);
        unordered_map <int, int> umap;
        for(int i = 0; i< nums.size(); i++){
            if(umap.find(nums[i])!=umap.end()){
                sol[0]=umap[nums[i]];
                sol[1]=i;
                return sol;
            }
            else {
                umap[target - nums[i]]=i;
            }
        }
        return sol;
    }
};