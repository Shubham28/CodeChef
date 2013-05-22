#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int T,N;
	int minWays[1002];
	int H[502],K[502];

	Input(T);
	while(T--){
		Input(N);

		int mx=0;
		FOR(i,0,N){
			Input(H[i]);
			mx=max(mx,H[i]);
		}
		FOR(i,0,N)		
			Input(K[i]);

		FOR(f,0,1001)
			minWays[f]=1005;

		minWays[0]=0;
		EFOR(s,1,2*mx){
			FOR(use,0,N)
				if(s-K[use]>=0)
					minWays[s]=min(minWays[s],minWays[s-K[use]]+1);
		}

		int tot=0;
		FOR(i,0,N)
			tot+=minWays[2*H[i]];
		printf("%d\n",tot);	
	}
	return 0;
}
