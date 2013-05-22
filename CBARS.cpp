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


int N;
LL ini[65][65],odd[65][65],ret[65][65];

void matPrd(LL prd[65][65],LL fir[65][65],LL sec[65][65])
{
	FOR(i,0,N)	FOR(j,0,N)		prd[i][j]=0;

	FOR(rw,0,N)		FOR(cl,rw,N){
		FOR(all,0,N){
			prd[rw][cl]+=(fir[rw][all]*sec[all][cl]);
			prd[rw][cl]%=MOD;
		}
		prd[cl][rw]=prd[rw][cl];
	}
}

void binExp(LL prd[65][65], LL bs)
{
	if(bs==1)
		FOR(i,0,N)	FOR(j,0,N)		prd[i][j]=ini[i][j];
	else {
		LL mid[65][65];
		binExp(mid,bs/2);

		MEM(ret,0);
		matPrd(ret,mid,mid);

		if(bs&1){
			MEM(odd,0);
			matPrd(odd,ini,ret);
			FOR(i,0,N)	FOR(j,0,N)		prd[i][j]=odd[i][j];
		} else
			FOR(i,0,N)	FOR(j,0,N)		prd[i][j]=ret[i][j];
	}
}

int main()
{
	LL A,B;
	scanf("%lld %lld",&A,&B);

	if(B==1){
		printf("%d\n",1<<A);
		return 0;
	}
	N=1<<A;

	bool ar1[A],ar2[A];
	FOR(rw1,0,N){
		FOR(i,0,A)
			ar1[i]=(rw1>>i)&1;

		FOR(rw2,0,N){
			FOR(i,0,A)
				ar2[i]=(rw2>>i)&1;

			bool vald=1;
			FOR(j,1,A)
				if(ar1[j-1]==ar1[j] && ar1[j]==ar2[j-1] && ar2[j-1]==ar2[j]){
					vald=0;
					break;
				}

			if(vald)
				ini[rw1][rw2]=1;
		}
	}

	LL fin[65][65];
	binExp(fin,B-1);

	LL ret=0;
	FOR(i,0,N)		FOR(j,0,N){
		ret+=fin[i][j]%MOD;
		ret%=MOD;
	}

	printf("%lld\n",ret);

	return 0;
}
