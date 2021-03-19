class Solution {
public:
//map ordena em ordem crescente por default usando o primeiro indice 
    int oddEvenJumps(vector<int>& A) {
        vector <bool> isreachable1(A.size(), 0);
        vector <bool> isreachable2(A.size(), 0);
        isreachable1[A.size()-1]=isreachable2[A.size()-1]=1;
        map <int, int> jump;
        map <int, int>::iterator it;
        for(int i = A.size()-1; i>=0;i--){
            it = jump.lower_bound(A[i]);
            if(it!=jump.end()){
                isreachable1[i]=isreachable2[it->second];
                if(A[i]==it->first)it++;
            }
            if(it!=jump.begin()){
                isreachable2[i] = isreachable1[prev(it)->second];
            }
            jump[A[i]]=i;
        }
        int cont=0;
        for(int i =0; i<isreachable1.size();i++){
            if(isreachable1[i]) cont++;
        }
        return cont;
    }
};