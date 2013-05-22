#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
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

const LL MOD=1000000007;

void binExp(LL P[2][2],int exp)
{
	if(exp==1){
		P[0][0]=6,P[0][1]=2;
		P[1][0]=4,P[1][1]=2;
	} else {
		LL H[2][2];
		binExp(H,exp>>1);

		P[0][0]=(H[0][0]*H[0][0])%MOD+(H[0][1]*H[1][0])%MOD;
		P[0][1]=(H[0][0]*H[0][1])%MOD+(H[0][1]*H[1][1])%MOD;
		P[1][0]=(H[1][0]*H[0][0])%MOD+(H[1][1]*H[1][0])%MOD;
		P[1][1]=(H[1][0]*H[0][1])%MOD+(H[1][1]*H[1][1])%MOD;

		if(exp&1){
			H[0][0]=P[0][0],H[0][1]=P[0][1],H[1][0]=P[1][0],H[1][1]=P[1][1];

			P[0][0]=(H[0][0]*6)%MOD+(H[0][1]*4)%MOD;
			P[0][1]=(H[0][0]*2)%MOD+(H[0][1]*2)%MOD;
			P[1][0]=(H[1][0]*6)%MOD+(H[1][1]*4)%MOD;
			P[1][1]=(H[1][0]*2)%MOD+(H[1][1]*2)%MOD;			
		}
	}
	return;
}

int main()
{
	int T,N;
	LL pwr[2][2];

	Input(T);
	while(T--){
		Input(N);

		if(N<=2)
			printf("%d\n",(N==1)?1:3);
		else {
			int exp=(N-1)/2;
			binExp(pwr,exp);

			LL ans;
			if(N&1)
				ans=3*pwr[0][1]+pwr[1][1];
			else
				ans=3*pwr[0][0]+pwr[1][0];

			printf("%lld\n",ans%MOD);
		}
	}

	return 0;
}
