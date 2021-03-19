#include <iostream>
#include <vector>
#include <queue>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 100007
#define LIM 1000000007
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, M, x, y; 
	bool isvisited[TAM];
	cin >> T;
	while(T--){
		queue <int> q;
		int numexit=0; 
		ll S=1;
		cin >> N >> M;
		fori(1, N+1) isvisited[i]=0;
		vector < vector <int> > v(N+1);
		fori(0, M){
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		fori(1, N+1){
			if(isvisited[i]==0){
				q.push(i);
				int numemp=0;
				++numexit;
				while(!q.empty()){
					//cout << q.front() << endl;
					for(auto it: v[q.front()]){
						if(isvisited[it]==0){
							q.push(it);
							++numemp;
							isvisited[it]=1;
						}
					}
					q.pop();
				}
				if(numemp==0)numemp=1;
				S=((S%LIM)*(numemp%LIM))%LIM;
			}
		}
		cout << numexit << ' ' << S << '\n';
	}
	return 0;
}
//SOLUTION CODECHEF
/*
//fire escape routes...march log challenge 2013
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define M 100001
#define mod 1000000007

struct subsets
{
	int parent;
	int rank;//number of nodes in the tree with corresponding parent
};

inline int readInt()
{
	int n=0;
	char c;
	while(1)
	{
		c=getchar_unlocked();
		if(c=='\n'||c==' ')
		   break;
		n=n*10+c-'0';
	}
	return n;
}

inline void writeInt(int n)
{
	int i=10;
	char buf[11];
	buf[10]='\0';
	do//while loop is not used becuase do...while will handle the case when n is 0 by default
	{
		buf[--i]=(n%10)+'0';
		n/=10;
	}while(n);
	while(buf[i])
	{
		putchar_unlocked(buf[i]);
		i++;
	}
}

void initialise(subsets s[],int n)
{
	for(int i=1;i<=n;i++)
	{
		s[i].parent=i;
		s[i].rank=1;
	}
}

int find(subsets s[], int i)
{
    // find root and make root as parent of i (path compression)
    while (s[i].parent != i)
        i=s[i].parent;

    return s[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
int Union(subsets s[], int x, int y)
{
    int xroot = find(s, x);
    int yroot = find(s, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if(xroot==yroot)return 0;
    if (s[xroot].rank < s[yroot].rank)
        {
			s[xroot].parent = yroot;
			s[yroot].rank+=s[xroot].rank;
		}
    else if (s[xroot].rank >= s[yroot].rank)
    {
        s[yroot].parent = xroot;
        s[xroot].rank+=s[yroot].rank;
	}
	return 1;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int t=readInt();
	//cout<<t<<endl;
	long long ways=1;
	int n,m;
	while(t--)
	{
	    ways=1;
		n=readInt();
		m=readInt();
		//cout<<n<<" "<<m<<endl;
		int notrees=n;
		int src,dest;
		struct subsets s[M];
		//initialising the disjoint-set forets
		initialise(s,n);
		while(m--)
		{
			src=readInt();
			dest=readInt();
			//cout<<src<<" "<<dest<<endl;
			//int x=find(s,src);
			//int y=find(s,dest);
			//cout<<x<<" "<<y<<endl;
            if(Union(s,src,dest))
				notrees--;
			//cout<<s[x].parent<<" "<<s[x].rank<<endl;
			//cout<<s[y].parent<<" "<<s[y].rank<<endl;
			//cout<<"------\n";
			//getch();
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i].parent==i)
			{
				ways*=s[i].rank;
			}
			if(ways>=mod)ways=ways%mod;
		}
		writeInt(notrees);
		printf(" ");
		writeInt(ways);
		printf("\n");
		//printf("%d %lld",notrees,ways);
		//cout<<notrees<<" "<<ways<<endl;
	}
	return 0;
}

*/