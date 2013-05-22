#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

inline void Inp(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0'&&ch<='9');

	return;
}

int main()
{
	int T,N,M;
	Inp(T);

	int sign,fr,to,val;
	int diff[1000005];

	while(T--){
		Inp(N),Inp(M);
		MEM(diff,0);

		FOR(i,0,M){
			Inp(sign),Inp(fr),Inp(to),Inp(val);
			fr--,to--;

			if(sign==2)
				val*=-1;

			diff[fr]+=val;
			diff[to+1]-=val;
		}

		LL cum=0,num;
		LL mx=-50000000000ll,mn=50000000000ll;

		FOR(i,0,N){
			cum+=diff[i];
			num=(i+1)+cum;

			if(mx<num)		mx=num;
			if(mn>num)		mn=num;
		}
		printf("%lld\n",(mx-mn));
	}

	return 0;
}
