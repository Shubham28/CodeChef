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
#define LL long long

using namespace std;

const int MOD=1000000007;

int nCr(LL n,LL r)
{
	if(n==0)		return 0;
	if(r==1)		return n;
	if(r==2)		return n*(n-1)/2;
	if(r==3)		return ((n*(n-1)/2)*(n-2)/3)%MOD;

	return (((n*(n-1)/2)*(n-2)/3)*(n-3)/4)%MOD;
}

int main()
{
	int T;
	scanf("%d",&T);

	char inp[10005];
	int frq[10],use[10];
	int L,ans;

	while(T--){
		scanf("%s",inp);
		L=strlen(inp),ans=0;

		MEM(frq,0);
		FOR(i,0,L)
			frq[inp[i]-'0']++;

		EFOR(d1,0,10)	EFOR(d2,d1,10)
			EFOR(d3,d2,10)	EFOR(d4,d3,10){
				int	S=0;
				MEM(use,0);

				if(d1<=9)	S+=d1,use[d1]++;
				if(d2<=9)	S+=d2,use[d2]++;
				if(d3<=9)	S+=d3,use[d3]++;
				if(d4<=9)	S+=d4,use[d4]++;

				if(S>0 && !(S%9)){
					LL tmp=1;

					FOR(dgt,0,10)
						if(use[dgt])
							tmp=(tmp*nCr(frq[dgt],use[dgt]))%MOD;

					ans=(ans+tmp)%MOD;
				}
			}

		printf("%d\n",ans);
	}

	return 0;
}
