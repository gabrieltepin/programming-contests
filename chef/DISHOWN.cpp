#include <iostream>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
inline int readInt(){
    int n=0;
    char c=getchar_unlocked();
    while(c < '0' || c >'9') {c=getchar_unlocked();}
    while(c>='0' && c<='9')
    {
        n=(n<<3)+(n<<1)+c-'0';
        c=getchar_unlocked();
    }
    return n;
}
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int T, N, score, Q, ind, ind1, ind2;
	bool op;
	T = readInt();
	while(T--){
		vector < pair <int, int> > S;
		N = readInt();
		fori(1, N+1){
			score = readInt();
			S.push_back(make_pair(score, i));
		}
		Q = readInt();;
		while(Q--){
			op = readInt();
			if(op == 1){
				cin >> ind;
				int tmp = ind;
				while (ind != S[ind-1].second){
					ind = S[ind-1].second;
				}
				S[tmp-1].second = ind;
				printf("%d\n", ind);
			}
			if(op == 0){
				ind1 = readInt();
				ind2 = readInt();
				int tmp1=ind1, tmp2=ind2;
				while (ind1 != S[ind1-1].second){
					ind1 = S[ind1-1].second;
				}
				S[tmp1-1].second = ind1;
				while (ind2 != S[ind2-1].second){
					ind2 = S[ind2-1].second;
				}
				S[tmp2-1].second = ind2;
				if(ind1==ind2){
					printf("Invalid query!\n");
				}
				else {
					if (S[ind1-1].first>S[ind2-1].first){
						S[ind2-1].first = S[ind1-1].first;
						S[ind2-1].second = ind1;
					}
					if (S[ind2-1].first>S[ind1-1].first){
						S[ind1-1].first = S[ind2-1].first;
						S[ind1-1].second = ind2;
					}
				}
			}
		}
		//fori(0, N) cout << S[i].first << " " << S[i].second << endl;
	}
	return 0;
}

