#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, l, w, x, r;
	double x1, x2;
	while(cin >> n >> l >> w){
		vector < pair< double, double > > v;
		fori(0,n){
			cin >> x >> r;
			if((double)r > (w/(double)2)){
				x1 = (double)(x - sqrt(abs(r*r - 0.25*w*w)));
				x2 = (double)(x + sqrt(abs(r*r - 0.25*w*w)));
				v.push_back(make_pair(x1, x2));
			}
		}
		sort(v.begin(), v.end());
		double end = v[0].second;
		int cont = 1;
		if(v[0].first>0) {
			cout << -1 << "\n";
		}
		else {
			fori(1, v.size()){
				if(v[i].first > end){
					cout << -1 << "\n";
					break;
				} 
				else{
					int t=i;
					double _end=end;
					while(v[t].first<=end && t<v.size()){
						_end=max(_end, v[t].second);
						t++;
					}
					if(_end>end){
						cont++;
						end=_end;
					}
					i=t-1; 
				}
				if(end>=l){
					break;
				} 
			}
			if (end < l) cout << -1 << "\n";
			else cout << cont << "\n";
		}
		v.clear();
	}
	return 0;
}

/////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_map>
#include <math.h>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define Find(x, y) y.find(x)!=y.end()
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T, N;
	cin >> T >> N;
	vector < pair <int, int> > v(N);
	vector <int> arr(N);
	fori(0, N){
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.rbegin(), v.rend());
	fori(0, N) cout << v[i].first << " "; cout << endl;
	fori(0, N) cout << v[i].second << " "; cout << endl;
	int t1=0, t2 = 0;
	fori(0, N){
		if(T-(v[i].first+t1)>=0){
			arr[v[i].second]=t1;
			t1+=v[i].first;
		}
		else{
			arr[v[i].second]=t2;
			t2+=v[i].first;
		}
		cout << t1 << " " << t2 << endl;
	}
	fori(0, N) cout << arr[i] << " ";
	cout <<"\n";
	
	return 0;
}

//////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_map>
#include <math.h>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define Find(x, y) y.find(x)!=y.end()
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector < vector <char> > v(N+1, vector <char>(M));
	fori(0, N){
		forj(0, M){
			cin >> v[i][j];
		}
	}
	fori(0, N){
		forj(0, M){
			cout << v[i][j];
		}
		cout << endl;
	}
	int cont = 0;
	fori(0, N){
		char flag='0';
		forj(0, M){
			if(v[i][j]!=flag){
				flag = v[i][j];
				if(flag=='1')cont++;
			}
		}
	}
	fori(0, N){
		char flag='0';
		forj(0, M){
			if(v[j][i]!=flag){
				flag = v[j][i];
				if (flag=='1')cont++;
			}
		}
	}
	cont*=2;
	cout << cont<< "\n";
	return 0;
}



/////////////////////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
	int val;
	ListNode* next;
};
#include <iostream>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //using given linked lists space
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        int carry=0, flag=1;
        while(tmp1!=NULL || tmp2!=NULL){
            tmp1->val+=tmp2->val + carry;
            tmp2->val = tmp1->val;
            if(tmp1->val>9){
                tmp1->val%=10;
                tmp2->val%=10;
                carry=1;
            }
            else {
                carry=0;
            }
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        if(carry==1){
            if(tmp1 == NULL && tmp2==NULL){
                ListNode* no = new ListNode;
                no->val =1;
                no->next = NULL;
                tmp1=no;
            }
            else{
                if(tmp1!=NULL){
                    while(tmp1 != NULL ||carry==0){
                        tmp1->val++;
                        if(tmp1->val>9){
                            tmp1->val%=10;
                            carry =1;
                        }
                        else{
                            carry =0;
                        }
                        tmp1 = tmp1->next;
                    }
                }
                if(tmp2!=NULL){
                    flag = 2;
                    while(tmp2!=NULL||carry==0){
                        tmp2->val++;
                        if(tmp2->val>9){
                            tmp2->val%=10;
                            carry =1;
                        }
                        else{
                            carry =0;
                        }
                        tmp2 = tmp2->next;
                    }
                }
            }
        }
        if(flag == 1) return l1;
        return l2;
    }
};
int main (){
	return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
   float valorTransicaoFinal;
   int nota, centavo, valorTotalNota, valorTotalCent, valorFinal1, valorFinal2, sum, valorTransicao;
   char ponto = '.';
   int aluno[1001];
   int numeroViajantes, n;
   scanf("%d", &numeroViajantes);
   valorTotalNota = 0;
   valorTotalCent = 0;
   for(int viajante = 1; viajante <= numeroViajantes; viajante++){
      scanf("%d%c%d", &nota, &ponto, &centavo);
      aluno[viajante] = nota*100 + centavo;
      valorTotalNota = valorTotalNota + nota;
      valorTotalCent = valorTotalCent + centavo;
   }
   valorFinal1 = valorTotalNota*100 + valorTotalCent;
   cout << valorFinal1 << endl;
   valorFinal2 = valorFinal1/numeroViajantes;
   cout << valorFinal2 << endl;
   n = 0;
   sum = 0;
   for(int viajante = 1; viajante <= numeroViajantes; viajante++){
      if(aluno[viajante] > valorFinal2){
         sum = sum + aluno[viajante];
         n = n + 1;
      }
   }
   valorTransicao = sum - valorFinal2*n;
   valorTransicaoFinal = valorTransicao;
   printf("$%.2f", valorTransicaoFinal/100);
   return 0;
}


#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){
    FILE* fptr;
    fptr = fopen("teste.cpp", "r");
    char ch;
    while ((ch = getc(fptr)) !=EOF){
        printf("%c", ch);
    }
    fclose(fptr);
	return 0;
}