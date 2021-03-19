#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, R, C;
	char tab[102][102], str[5] = {'s', 'p','o', 'o', 'n'};
	cin >> T;
	while(T--){
		bool isfound=0;
		cin >> R >> C;
		fori(0, R){
			forj(0, C){
				cin >> tab[i][j];
				int d = tab[i][j]-'A';
				if(d<=26 && d>=0) 
					tab[i][j]='a'+d;
			}
		}
		fori(0, R){
		    int k = 0;
			forj(0, C-4){//no need to look later j>C-5 
				while(tab[i][j+k]==str[k] && k<5){
					k++;
				}
				if(k==5) {
					isfound=1;
					j=C;i=R;//break
				}
				else k=0;
			}
		}
		if(isfound==0){
			forj(0, C){
				int k =0;
				fori(0, R-4){
					while(tab[i+k][j]==str[k] && k<5){
						k++;
					}
					if(k==5) {
						isfound=1;
						j=C;i=R;//break
					}
					else k=0;
				}
			}
		}
		if(isfound) cout << "There is a spoon!\n";
		else cout << "There is indeed no spoon!\n";
	}
	return 0;
}