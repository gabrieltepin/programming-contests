class Solution {
public:
    int knightDialer(int N) {
        int mod = 1000000007;
        vector < vector <int> > dp (N, vector <int> (10, 0));
        //dp[0][x] = 1 because it is placement operation
        for(int i =0; i<dp[0].size(); i++) dp[0][i]=1;
        for(int i = 1; i<dp.size();i++){
            for(int j = 0; j<dp[0].size();j++){
                if(j==1) dp[i][j] = (dp[i-1][6]%mod+dp[i-1][8]%mod)%mod;
                if(j==2) dp[i][j] = (dp[i-1][7]%mod+dp[i-1][9]%mod)%mod;
                if(j==3) dp[i][j] = (dp[i-1][4]%mod+dp[i-1][8]%mod)%mod;
                if(j==4) dp[i][j] = ((dp[i-1][3]%mod+dp[i-1][9]%mod)%mod+dp[i-1][0]%mod)%mod;
                if(j==6) dp[i][j] = ((dp[i-1][1]%mod+dp[i-1][7]%mod)%mod+dp[i-1][0]%mod)%mod;
                if(j==7) dp[i][j] = (dp[i-1][6]%mod+dp[i-1][2]%mod)%mod;
                if(j==8) dp[i][j] = (dp[i-1][1]%mod+dp[i-1][3]%mod)%mod;
                if(j==9) dp[i][j] = (dp[i-1][2]%mod+dp[i-1][4]%mod)%mod;
                if(j==0) dp[i][j] = (dp[i-1][6]%mod+dp[i-1][4]%mod)%mod;
            }
        }
        int sum =0;
        for(int i = 0; i<dp[0].size();i++) sum = (sum%mod + dp[N-1][i]%mod)%mod;
        return sum%(mod);
    }
};

//concise solution
using VL = vector< long >;
class Solution {
    static const int MOD = 1000000007;
    vector<VL> hops{
        { 4, 6 },  { 6, 8 },  { 7, 9 },  { 4, 8 },  { 0, 3, 9 },  { },  { 0, 1, 7 },  { 2, 6 },  { 1, 3 },  { 2, 4 }
    };
public:
    int knightDialer( int N ){
        VL cur( 10, 1 );
        for(  VL next( 10, 0 );  --N > 0;  next=VL( 10, 0 )  ){
            for( int i=0;  i <= 9;  ++i )
                for( auto hop: hops[ i ] )
                    next[ i ] += cur[ hop ] % MOD;
            cur.swap( next );
        }
        return accumulate( cur.begin(), cur.end(), 0L ) % MOD;
    }
};

//more concise
using VL = vector< long >;
class Solution {
    static const int MOD = 1000000007;
    vector<VL> hops{ {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4} };
public:
    int knightDialer( int N, VL cur=VL( 10, 1 ) ){
        for(  VL next( 10, 0 );  --N > 0;  cur.swap( next ), next=VL( 10, 0 )  )
            for( int i=0;  i < 10;  ++i )
                for( auto hop: hops[ i ] )
                    next[ i ] += cur[ hop ] % MOD;
        return accumulate( cur.begin(), cur.end(), 0L ) % MOD;
    }
};