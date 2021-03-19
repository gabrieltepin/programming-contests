class Solution {
public:
    int getMin(vector <int> &lookup, vector <int> &days, vector <int> &costs, int i, int d, int maxDay){
        if(i>=days.size() || d>maxDay) return 0;
        if(lookup[i]!=INT_MAX) return lookup[i];
        int ans;
        //WHY IS THIS WRONG??????
        if(d>days[i]){
            ans = getMin(lookup, days, costs, i+1, d, maxDay);
        }
        ////////////////////
        else{
            int c0 = costs[0] + getMin(lookup, days, costs, i+1, days[i]+1, maxDay);
            int c1 = costs[1] + getMin(lookup, days, costs, i+1, days[i]+7, maxDay);
            int c2 = costs[2] + getMin(lookup, days, costs, i+1, days[i]+30, maxDay);
            ans = min({c0,c1,c2});
            lookup[i]=min(lookup[i], ans);
        }
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> lookup(days.size(), INT_MAX);
        return getMin (lookup, days, costs, 0, days[0], days[days.size()-1]);
    }
};


//////Now, fixed solution
class Solution {
public:
    int getMin(vector <int> &lookup, vector <int> &days, vector <int> &costs, int i, int d, int maxDay){
        if(i>=days.size() || d>maxDay) return 0;
        if(lookup[i]!=INT_MAX) return lookup[i];
        int ans, j=i+1;
        int c0 = costs[0] + getMin(lookup, days, costs, j, days[i]+1, maxDay);
        while(j<days.size() && days[i]+6>=days[j]) 
            j++;
        int c1 = costs[1] + getMin(lookup, days, costs, j, days[i]+7, maxDay);
        while(j<days.size() && days[i]+29>=days[j])
            j++;
        int c2 = costs[2] + getMin(lookup, days, costs, j, days[i]+30, maxDay);
        ans = min({c0,c1,c2});
        lookup[i]=ans;
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> lookup(days.size(), INT_MAX);
        return getMin (lookup, days, costs, 0, days[0], days[days.size()-1]);
    }
};
//it seems that recursing wouldn't allow the following c1 or c2 to change the lookup
//since it would be already changed in a previous recursion in some cases