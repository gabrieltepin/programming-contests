class Solution {
public:
//Obs.: gcd isn't neccessary in this case!!
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(coins.size()==0 && amount==0) return 0;
        if(coins.size()==0 && amount!=0) return -1;
        if(coins.size()==1 && amount%coins[0]!=0) return -1;
        if(coins.size()==1 && amount%coins[0]==0) return amount/coins[0];
        int g = gcd(coins[0], coins[1]);
        for(int i = 2;i<coins.size();i++){
            g = gcd(g, coins[i]);
        }
        if(amount%g!=0) return -1;
        vector <int> v(amount+1, amount+1);
        v[0]=0;
        for(int i = 0; i<coins.size(); i++){
            for(int j = coins[i]; j<=amount ;j++){
                v[j]=min(v[j-coins[i]]+1, v[j]);
            }   
        }
        if(v[amount]==0 || v[amount]>amount)return -1;
        return v[amount];
    }
};


//Optimized solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};