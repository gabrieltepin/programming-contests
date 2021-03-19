//this gave TLE in leetcode
class Solution {
public:
    bool isEqual(vector <int> &sums){
        for(int i = 1 ; i< sums.size(); i++){
            if(sums[i]!=sums[i-1]) return 0;
        }
        return 1;
    }
    bool partition(vector <int> &nums, vector <int> &sums, int i, int N, int sum){
        if(i==N) return isEqual(sums);
        bool ans=0;
        for(int j = 0; j<sums.size(); j++){
            sums[j]+=nums[i];
            if(sums[j]<=sum) ans |= partition(nums, sums, i+1, N, sum);
            sums[j]-=nums[i];
        }
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%k!=0) return 0;
        int sum = total / k;
        vector <int> sums (k, 0);
        return partition(nums, sums, 0, nums.size(), sum);
    }
};

//My optimized solution
class Solution {
public:
    bool partition(vector <int> &nums, vector <int> &sums, int i, int sum){
        for(int j = 0; j<sums.size(); j++){
            if(nums[i]+sums[j]<=sum){
                if(i == nums.size()-1) return true; 
                sums[j]+=nums[i];
                if(partition(nums, sums, i+1, sum)) return true;
                else{
                    sums[j]-=nums[i];
                    if(sums[j]==0) return false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1) return true;
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%k!=0) return 0;
        sort(nums.rbegin(), nums.rend());
        int sum = total / k;
        if(nums[0]>sum) return 0;
        vector <int> sums (k, 0);
        return partition(nums, sums, 0, sum);
    }
};

//AC solution
 bool canPartitionKSubsets(vector<int>& nums, int K) {
        int N = nums.size();
        if (K == 1) return true;
        if (N < K) return false;
        int sum = 0;
        for (int i = 0; i < N; i++) sum += nums[i];
        if (sum % K != 0) return false;

        int subset = sum / K;
        int subsetSum[K];
        bool taken[N];

        for (int i = 0; i < K; i++) subsetSum[i] = 0;
        for (int i = 0; i < N; i++) taken[i] = false;

        subsetSum[0] = nums[N - 1];
        taken[N - 1] = true;

        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
    }

    bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
        if (subsetSum[curIdx] == subset) {
            if (curIdx == K - 2) return true;
            return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
        }

        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i]) continue;
            int tmp = subsetSum[curIdx] + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                if (nxt) return true;
            }
        }
        return false;
    }

    //optimized solution
    class Solution {
public:
   // use global variables to avoid long parameter list
   int target; // of each bucket
   vector< int > ns;
   vector< int > bucket;

   bool canPartitionKSubsets( vector<int>& nums, int k ) {
       int sum = 0;
       for( int &n : nums ) sum += n;
       if( sum % k ) return false; // not divisible
       target = sum / k;
       ns = vector< int >( nums );
       bucket = vector< int >( k, 0 );
       // starting with bigger ones makes it faster
       sort( ns.begin(), ns.end() );
       reverse( ns.begin(), ns.end() );
       return put( 0 );
   }

   // put #n item of ns into some bucket to meet target
   bool put( int n ) {
       for( int i = 0; i < bucket.size(); ++i ) {
           if( bucket[i] + ns[n] > target ) continue; // try next bucket
           bucket[i] += ns[n]; // put it in!
           if( n == ns.size() - 1 ) return true; // all items in bucket, no overflow
           if( put( n + 1 ) ) return true; // move on to next item
           else { // no solution = wrong bucket
               bucket[i] -= ns[n]; // take it out
               if( bucket[i] == 0 ) return false; // no need to try other empty bucket
           }
       }
       return false; // no bucket fits
   }
};