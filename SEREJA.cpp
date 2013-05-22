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
#define PII pair<int,int>
#define LL long long
#define ULL unsigned long long

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

const int MOD=1000000007;

int N;
int ar[100002],dupl[100002];

bool cmprt(const int &a, const int &b)
{
	if(ar[a]<ar[b])		return 1;
	if(ar[a]>ar[b])		return 0;
	return (ar[a]<ar[b]);
}

int lfLess[100002];
int lfEGrt[100002],lfGrt[100002];
int rtELess[100002],rtEGrt[100002];

PII stk[100002];

bool compEG(const int a,const int b)
{
	return (a<b);
}

bool compG(const int a,const int b)
{
	return (a<=b);
}

bool compEL(const int a,const int b)
{
	return (a>b);
}

bool compL(const int a,const int b)
{
	return (a>=b);
}

void preProcess(int st,int inc,int *ptr,bool (*compFunc)(const int,const int))
{
	int len=0;
	for(int i=st;i>=0 && i<N;i+=inc){
		int nxt=ar[i];

		while(len>0 && (*compFunc)(stk[len-1].first,nxt)){
			(ptr)[stk[len-1].second]=i;
			len--;
		}
		stk[len++]=PII(ar[i],i);
	}
	while(len>0){
		(ptr)[stk[len-1].second]=-1;
		len--;
	}
}

inline LL binExp(ULL bs, LL exp)
{
	if(bs==0)	return 0;
	if(exp==0)	return 1;

	ULL ans=1;
	for(;exp!=0;exp>>=1,bs=(bs*bs)%MOD)
		if(exp&1)
			ans=(ans*bs)%MOD;

	return (LL)ans;
}

int main()
{
	bool adj=0;

	Input(N);
	FOR(i,0,N){
		Input(ar[i]);
		if(i>0 && ar[i-1]==ar[i])
			adj=1;

		dupl[i]=i;
	}
	if(adj){
		printf("0\n");
		return 0;
	}

	sort(dupl,dupl+N,cmprt);

	preProcess(0,1,rtEGrt,compEG);
	preProcess(N-1,-1,lfEGrt,compEG);
	preProcess(N-1,-1,lfGrt,compG);
	preProcess(0,1,rtELess,compEL);
	preProcess(N-1,-1,lfLess,compL);

	LL prod=1;
	FOR(sml,0,N){
		int pos=dupl[sml];

		int lftBnd=lfLess[pos]+1;
		int rtBnd=rtELess[pos]-1;
		if(rtBnd==-2)	rtBnd=N-1;

		for(int grt=pos-1;grt>=lftBnd;){
			int rang=ar[grt]-ar[pos];

			int L=max(lfEGrt[grt]+1,lftBnd);

			int R=rtEGrt[grt]-1;
			if(R==-2)		R=N-1;
			R=min(R,rtBnd);

			LL tot=(grt+1ll-L)*(R+1ll-pos);
			prod=(prod*binExp(rang,tot))%MOD;
			grt=lfEGrt[grt];
		}

		for(int grt=pos+1;grt<=rtBnd;){
			int rang=ar[grt]-ar[pos];

			int L=max(min(pos,lfGrt[grt]+1),lftBnd);

			int R=rtEGrt[grt]-1;
			if(R==-2)		R=N-1;
			R=min(R,rtBnd);

			LL tot=(pos+1ll-L)*(R+1ll-grt);

			prod=(prod*binExp(rang,tot))%MOD;

			grt=rtEGrt[grt];
			if(grt==-1)		grt=N;
		}
	}
	printf("%lld\n",prod);

	return 0;
}
