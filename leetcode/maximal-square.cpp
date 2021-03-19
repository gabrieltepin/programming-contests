//optimized space solution
class Solution {
public:
    bool checkSurround(vector<vector<char>>& matrix, int i, int j, int ii, int jj){
        if(ii>=matrix.size() || jj>=matrix[i].size()) return 0;
        bool res =1;
        for(int t=0;t<=ii-i;t++) {
            res = res && matrix[i+t][jj]=='1';
            res = res && matrix[ii][j+t]=='1';
            if(!res) return 0;
        }
        return res;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = 0;
        for(int i = 0; i< matrix.size(); i++){
            for(int j = 0; j< matrix[i].size(); j++){
                if(matrix[i][j]=='1'){
                    int ii = i, jj=j;
                    while(checkSurround(matrix, i, j, ++ii, ++jj)){}
                    m=max(m, (ii-i)*(ii-i));
                }
            }
        }
        return m;
    }
};

//optimized time solution
//if there is 1 int m[i][j], m[i][j]= min(m[i-1][j], m[i][j-1], m[i-1][j-1]) + 1
int maximalSquare(vector<vector<char>>& matrix) {
    int rst = 0;
    for(int ii=0; ii<matrix.size(); ++ii)
    {
        for(int jj=0; jj<matrix[0].size(); ++jj)
        {
            int a = (ii&&jj) ? matrix[ii-1][jj-1] : 0;
            int b = (ii) ? matrix[ii-1][jj] : 0;
            int c = (jj) ? matrix[ii][jj-1] : 0;

            matrix[ii][jj] = (matrix[ii][jj]>'0') ? (min(a, min(b, c))+1) : 0;
            
            rst = max(rst, matrix[ii][jj]*matrix[ii][jj]);
        }
    }
    return rst;

}