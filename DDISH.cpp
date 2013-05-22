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
#define ALL(A) A.begin(),A.end()
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(LL &N)
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

LL fact[12];
LL nCr[15][15];

inline void calComb(int N)
{
	MEM(nCr,0);
	nCr[0][0]=1;
	EFOR(row,1,N){
		nCr[row][0]=1;
		EFOR(col,1,row)
			nCr[row][col]=nCr[row-1][col-1]+nCr[row-1][col];
	}
	return;
}

LL maxComb(int digits)
{
	if(digits>10 || digits==0)
		return 0;

	LL zero=nCr[9][digits-1]*(digits-1ll)*fact[digits-1];
	LL noZero=nCr[9][digits]*fact[digits];

	return zero+noZero;
}

char conv[20];
int ln;
LL cnt[(1<<10)+5][2];

LL sameLen(int mask,bool eq)
{
	int used=__builtin_popcount(mask);
	if(used==ln)
		return !eq;

	LL &tmp=cnt[mask][eq];
	if(tmp!=-1)
		return tmp;

	tmp=0;
	if(!eq)
		return nCr[10-used][ln-used]*fact[ln-used];

	int prs=conv[used]-'0';
	EFOR(now,0,prs){
		if(used==0 && now==0)
			continue;

		if(!(mask&(1<<now)))
			tmp+=sameLen(mask|(1<<now),(now==prs));
	}
	return tmp;
}

LL cntLess(LL T)
{
	sprintf(conv,"%lld",T);
	ln=strlen(conv);

	LL tot=0;
	FOR(i,1,ln)
		tot+=maxComb(i);

	if(ln<=10){
		MEM(cnt,-1);
		tot+=sameLen(0,1);
	}
	return tot;
}

int main()
{
	fact[0]=1,fact[1]=1;
	FOR(i,2,12)		fact[i]=fact[i-1]*i;
	calComb(12);

	LL T,L,R;
	Input(T);
	while(T--){
		Input(L),Input(R);

		printf("%lld\n",cntLess(R+1)-cntLess(L));
	}

	return 0;
}
