#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int N;
int ar[10005];

LL lCum[10005],rCum[10005];
LL lCMax[10005],rCMax[10005];
LL lCMin[10005],rCMin[10005];

LL calBest()
{
	lCum[0]=0,rCum[N+1]=0;

	LL lMin=0,rMin=0,lMax=0,rMax=0;
	EFOR(i,1,N){
		lCum[i]=lCum[i-1]+ar[i];

		int j=N+1-i;
		rCum[j]=rCum[j+1]+ar[j];

		lCMax[i]=lCum[i]-lMin;
		lMin=min(lMin,lCum[i]);

		rCMax[j]=rCum[j]-rMin;
		rMin=min(rMin,rCum[j]);

		lCMin[i]=lCum[i]-lMax;
		lMax=max(lMax,lCum[i]);

		rCMin[j]=rCum[j]-rMax;
		rMax=max(rMax,rCum[j]);
	}

	LL minCSum=lCMin[1],maxCSum=lCMax[1];
	LL ret=LONG_LONG_MIN;
	EFOR(k,2,N){
		ret=max(ret,max(abs(rCMax[k]-minCSum),abs(rCMin[k]-maxCSum)));

		minCSum=min(minCSum,lCMin[k]);
		maxCSum=max(maxCSum,lCMax[k]);
	}
	return ret;
}

int main()
{
	int T;
	Input(T);

	while(T--){
		Input(N);

		EFOR(i,1,N)
			Input(ar[i]);

		printf("%lld\n",calBest());
	}

	return 0;
}
