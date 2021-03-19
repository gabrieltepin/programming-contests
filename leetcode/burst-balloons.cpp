//Recursive naive solution
class Solution {
public:
    int auxMaxCoins(vector<int> &nums, int N, vector <bool> &isvisited){
        if(N==1) 
            for(int i = 0; i<nums.size();i++) if(isvisited[i]==0) return nums[i];
        int res=1, prev, next, j, ans=1;
        for(int i = 0; i<nums.size(); i++){
            if(isvisited[i]==0){
                for(j = i-1; j>=0 && isvisited[j]==1; j--){}
                if(j>=0) prev = nums[j];
                else prev =1;
                
                for(j = i+1; j<nums.size() && isvisited[j]==1; j++){}
                if(j<nums.size()) next = nums[j];
                else next =1;   
                
                isvisited[i]=1;
                res = prev*nums[i]*next;
                ans = max(ans, res + auxMaxCoins(nums, N-1, isvisited));
                isvisited[i]=0;
            }
        }
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector <bool> isvisited(nums.size(), 0);
        return auxMaxCoins(nums, nums.size(), isvisited);
    }
};

//recursive soluition with memoization
class Solution {
public:
    int auxMaxCoins(vector<int> &nums, vector< vector<int> > &coins, int a, int b){
        if(a==b-1) return 0;
        if(coins[a][b]>0) return coins[a][b];
        for (int k = a+1; k<b; k++){
            coins[a][b]=max(coins[a][b], auxMaxCoins(nums,coins,a,k)+nums[a]*nums[k]*nums[b]+auxMaxCoins(nums, coins, k, b));
        }
        return coins[a][b];
    }
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector< vector<int> > coins(nums.size(), vector <int> (nums.size(), 0));
        return auxMaxCoins(nums, coins, 0, nums.size()-1);
    }
};
//O(N^3) solution
class Solution {
    public:
        int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        // dp[i][j]=max( dp[i][j], dp[i][x-1]+nums[i-1]*nums[x]*nums[j+1]+dp[x+1][j] )
        // dp[i][j] means max coins in range [i,j].
        for(int len=1;len<=n;len++)
            for(int start=1;start<=n-len+1;start++){
                int end=start+len-1;
                for(int x=start;x<=end;x++)
                    dp[start][end]=max(dp[start][end],dp[start][x-1]+nums[start-1]*nums[x]*nums[end+1]+dp[x+1][end]);
            }
        return dp[1][n];   
        }
    };

    /*
    We then think can we apply the divide and conquer technique? After all there seems to be many self similar sub problems from the previous analysis.

Well, the nature way to divide the problem is burst one balloon and separate the balloons into 2 sub sections one on the left and one one the right. However, in this problem the left and right become adjacent and have effects on the maxCoins in the future.

Then another interesting idea come up. Which is quite often seen in dp problem analysis. That is reverse thinking. Like I said the coins you get for a balloon does not depend on the balloons already burst. Therefore
instead of divide the problem by the first balloon to burst, we divide the problem by the last balloon to burst.

Why is that? Because only the first and last balloons we are sure of their adjacent balloons before hand!

For the first we have nums[i-1]*nums[i]*nums[i+1] for the last we have nums[-1]*nums[i]*nums[n].

OK. Think about n balloons if i is the last one to burst, what now?

We can see that the balloons is again separated into 2 sections. But this time since the balloon i is the last balloon of all to burst, the left and right section now has well defined boundary and do not affect each other! Therefore we can do either recursive method with memoization or dp.

Final

Here comes the final solutions. Note that we put 2 balloons with 1 as boundaries and also burst all the zero balloons in the first round since they won't give any coins.
The algorithm runs in O(n^3) which can be easily seen from the 3 loops in dp solution.
*/