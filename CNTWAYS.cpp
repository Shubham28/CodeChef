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
#define ULL unsigned long long

using namespace std;

const unsigned int MOD=1000000007;

ULL fact[800005];
ULL modInv[400005];

inline ULL binExp(ULL bs)
{
	if(bs==0)	return 0;

	int exp=1000000005;
	ULL ans=1;
	for(;exp!=0;exp>>=1,bs=(bs*bs)%MOD)
		if(exp&1)
			ans=(ans*bs)%MOD;

	return ans;
}

void preComp()
{
	fact[0]=fact[1]=1;
	EFOR(a,2,800001)
		fact[a]=(fact[a-1]*a)%MOD;

	modInv[1]=modInv[0]=1;
	EFOR(a,1,400001)
		modInv[a]=binExp(fact[a]);
}

ULL nCr(int N,int R)
{
	ULL num=fact[N];
	ULL den=(modInv[R]*modInv[N-R])%MOD;

	return (num*den)%MOD;
}

int main()
{
	preComp();

	int R;
	scanf("%d",&R);

	int N,M,A,B;
	int wid,ht;
	ULL tot,ways1,ways2,prev,copy;

	while(R--){
		scanf("%d%d%d%d",&N,&M,&A,&B);

		tot=0,prev=0;
		EFOR(top,B,M){
			wid=(N-A),ht=top;
			ways1=nCr(wid+ht,ht);
			copy=ways1;
			ways1=(ways1+MOD-prev);

			wid=A,ht=(M-top);
			ways2=nCr(wid+ht,ht);

			tot+=(ways1*ways2)%MOD;
			tot%=MOD;
			prev=copy;
		}
		printf("%d\n",int(tot));
	}

	return 0;
}
