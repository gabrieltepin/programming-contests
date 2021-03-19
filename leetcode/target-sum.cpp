//this solution gives TLE
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    int N=(1<<(nums.size())), cont=0;
    while(--N>=0){
        int s=0, i=1;
		//cout << bitset<5>(N) << " ";
        for(int j=0; j<nums.size();i=1<<++j){
			//cout << bitset<5>(i) << " ";
            if(i&N) s+=nums[j];
            else s-=nums[j];
        }
		//cout << endl;
        if(s==S)cont++;
    }
    return cont;
}

};

//This is a nice solution!!
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(S>total || S<-total) return 0;
        //ks[0] -> -total, ks[total+1] -> 0, ks[2*total+1] -> total;
        //s = (total+S)/2 subset sum problem!!
        if((total+S)%2!=0) return 0;
        int s = (total+S)/2;
        vector <int> ks(s+1, 0);
        ks[0]=1;
        for(int i = 0; i<nums.size();i++){
            for(int j = ks.size()-1; j>=0;j--){
                if(j-nums[i]>=0) ks[j]+=ks[j-nums[i]];
            }
        }
        return ks[s];
    }
};
