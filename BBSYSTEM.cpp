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
#define UI unsigned int

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');
}

const UI LIM=2229283;
const UI MOD=500009;

#define L 2229383

UI prime[L/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
	MEM(prime,-1);
	UI sqrtN=(UI)sqrt((double)L)+1;

	for(UI i=3;i<sqrtN;i+=2)
		if(gP(i)){
			UI i2=i+i;
			for(UI j=i*i;j<L;j+=i2)		rP(j);
		}
}

UI P=0;
UI pr[164670];

UI fct[LIM+10];

UI PrimeFact(UI N)
{
	for(UI c=0;pr[c]<=N;c++)
		if(N%pr[c]==0){
			N/=pr[c];
			int qt=pr[c],pw=1;

			while(N%pr[c]==0)
				qt*=pr[c],N/=pr[c],pw++;

			return ((N!=1)?(fct[qt]*fct[N]):(pw+1));
		}
}

UI grp[MOD+10];
UI ans[LIM+10];

int main()
{
	sieve();
	pr[P++]=2;
	for(UI chk=3;chk<=LIM;chk+=2)
		if(gP(chk))
			pr[P++]=chk;

	fct[1]=1,fct[2]=2;
	grp[1]=grp[2]=1;
	ans[2]=1;

	unsigned long long tmp;
	UI inc;
	for(UI a=3;a<LIM;a++){

		if((a&1) && gP(a))
			inc=2;
		else
			inc=PrimeFact(a);

		++grp[inc],fct[a]=inc;
		tmp=ans[a-1];		tmp*=grp[inc];
		ans[a]=tmp%MOD;
	}

	int T,inp;
	Input(T);

	UI outp;
	while(T--){
		Input(inp);

		if(inp<LIM)
			outp=ans[inp]-1;
		else
			outp=MOD-1;

		printf("%d\n",int(outp));
	}

	return 0;
}
