class Solution {
public:
    int histMax(vector <int> &v){
        int area=0, i =0;
        stack<int> stk;
        while(i<v.size()){
            if(stk.empty() || v[stk.top()]<=v[i])
                stk.push(i++);
            else{
                int tp = v[stk.top()];
                stk.pop();
                area = max(area, tp*((stk.empty())? i : i-stk.top()-1));
            }
        }
        while(!stk.empty()){
            int tp =v[stk.top()];
            stk.pop();
            area = max(area, tp*((stk.empty())?i:i-stk.top()-1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int maxArea=0;
        vector <int> v(matrix[0].size());
        for(int i = matrix.size()-1;i>=0;i--){
            for(int j = 0; j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    int k = i;
                    while(k>=0 && matrix[k][j]=='1'){
                        k--;
                    }
                    v[j]=i-k;
                }
                else{
                    v[j]=0;
                }
            }
            maxArea = max(maxArea, histMax(v));
        }
        return maxArea;
    }
};

//a solucao otima ta no caderno, fica ruim de explicar por aqui :p

//mas tem essa solucao usando divide and conquer tb
//divide and conquer solution
class Solution {
    public int maximalRectangle(char[][] matrix) {

        if (matrix.length == 0) return 0;
        int maxarea = 0;
        int[][] dp = new int[matrix.length][matrix[0].length];

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if (matrix[i][j] == '1'){

                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0? 1 : dp[i][j-1] + 1;

                    int width = dp[i][j];

                    // compute the maximum area rectangle with a lower right corner at [i, j]
                    for(int k = i; k >= 0; k--){
                        width = Math.min(width, dp[k][j]);
                        maxarea = Math.max(maxarea, width * (i - k + 1));
                    }
                }
            }
        } return maxarea;
    }
}