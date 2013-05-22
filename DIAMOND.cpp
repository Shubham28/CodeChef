#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

const LL MOD=1000000007;

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

int N;
int V[2005];
double prob[2005][2005];

int main()
{
	prob[2][1]=prob[2][2]=.5;
	EFOR(len,3,2000){
		prob[len][len]=prob[len][1]=.5+.5*(1-prob[len-1][1]);

		EFOR(ps,2,int(ceil(len/2.)))
			prob[len][len+1-ps]=prob[len][ps]=.5*(1-prob[len-1][ps])+.5*(1-prob[len-1][ps-1]);
	}

	int T;
	Input(T);

	while(T--){
		Input(N);

		FOR(i,0,N)
			Input(V[i]);

		if(N==1){
			printf("%d.000\n",V[0]);
			continue;
		}

		double ans=0;
		EFOR(i,1,N)
			ans+=(prob[N][i]*V[i-1]);
	
		printf("%.3lf\n",ans);
	}

	return 0;
}
