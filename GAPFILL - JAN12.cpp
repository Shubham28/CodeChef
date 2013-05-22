#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <climits>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ULL unsigned long long

using namespace std;

inline void Input(ULL &N)
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

ULL PR=1000000007;
ULL MOD=1000000006;

inline ULL binExp(ULL bs,ULL exp)
{
	ULL ret=1;
	for(;exp!=0;exp>>=1,bs*=bs){
		bs%=PR;
		if(exp&1){
			ret*=bs;
			ret%=PR;
		}
	}

	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);

	ULL N,M;
	ULL ans;

	while(T--){
		Input(N),Input(M);

		if( (N&1)==0 && (M&1)==0 ){
			ans=binExp(2, (N%MOD)*(M%MOD)%MOD );

		} else if((N&1) && (M&1)){
			ans=binExp(2, ((N-1)%MOD)*((M-1)%MOD)%MOD );
			ans=(ans*2)%PR;

		} else {
			if(N&1)
				swap(N,M);

			ans=binExp(2, (N%MOD)*((M-1)%MOD)%MOD );
			ans=(ans*2)%PR;
		}
		printf("%d\n",int(ans));
	}

	return 0;
}
