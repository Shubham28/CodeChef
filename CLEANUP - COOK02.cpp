#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SORT(A) sort( A.begin(),A.end() )
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	Input(T);

	int N,M;
	bool jobs[1001];
	int chef[1001],assis[1001];
	int lenc,lena;

	while(T--){
		Input(N),Input(M);

		lenc=0,lena=0;
		memset(jobs,0,sizeof(jobs));

		FOR(inp,0,M){
			int tmp;
			Input(tmp);
			jobs[tmp-1]=true;
		}

		bool ch=true;
		FOR(all,0,N)
			if(!jobs[all]){
				if(ch)
					chef[lenc++]=all+1;
				else
					assis[lena++]=all+1;
				ch=!ch;
			}

		FOR(pr,0,lenc)
			printf("%d ",chef[pr]);
		printf("\n");
		FOR(pr,0,lena)
			printf("%d ",assis[pr]);
		printf("\n");
	}

//	fclose(stdin);
	return 0;
}
