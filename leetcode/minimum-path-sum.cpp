class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int C=grid[0].size(), L=grid.size(), up, left;
        for(int i = 0; i<L; i++){
            for (int j = 0; j<C; j++){
                if(i!=0 || j!= 0){
				    (j>0)? left=grid[i][j-1] : left=INT_MAX;
				    (i>0)? up=grid[i-1][j] : up = INT_MAX;
				    grid[i][j] += min(up, left);
			    }
            }
        }
        return grid[L-1][C-1];
    }
};