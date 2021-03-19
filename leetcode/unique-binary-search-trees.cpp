//calculate the number of BST given n nodes
//Catalan number: fix the node x and we should calculate combination of x[i]*x[n-1-i]
//with 5 nodes, for example:
//(x _ _ _ _) + (_ x _ _ _) +  (_ _ x _ _) + (_ _ _ x _) + (_ _ _ _ x) = f0*f4 + f1*f3 + ...
class Solution {
public:
    int cat(int n, vector <int> &v){
        if (n==0 || n==1) return 1;
        int C=0;
        for(int i = 0;i<n;i++){
            if(v[i]!=0 && v[n-1-i]!=0){
                C+=v[i]*v[n-1-i];    
            }
            else{
                v[i]=cat(i, v);
                v[n-1-i] = cat(n-1-i, v);
                C+=cat(i, v)*cat(n-1-i, v);
            }
        }
        return C;
    }
    int numTrees(int n) {
        vector <int> v(n+1, 0);
        v.push_back(1);
        v.push_back(1);
        return cat(n, v);
    }
};

//another way to calculate is with the formula: Cn+1 = ((2)(2n+1)/(n+2))Cn