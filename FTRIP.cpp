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
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int primes[170];
int P=0;

void SieveFull(int N)
{
	int range=(N-1)/2;
	int limit=int(sqrt(N+0.)+1e-9)/2;

	bool chk[range+1];
	FOR(cl,0,range+1)
		chk[cl]=1;

	EFOR(i,1,limit){
		if(chk[i-1])
			for(int j=2*i*(i+1);j<=range;j+=(2*i+1))
				chk[j-1]=0;
	}

	FOR(i,0,range)
		if(chk[i])
			primes[P++]=2*i+3;

	return;
}

bool done[1005];
int factPwr[1005][170];

void preCompute()
{
	primes[P++]=2;
	SieveFull(1001);

	MEM(done,0);
	MEM(factPwr,0);
}

void calPowers(int base)
{
	if(done[base])
		return;

	done[base]=1;
	for(int pr=0;pr<P && primes[pr]<=base;pr++){
		for(int pwr=primes[pr];pwr<=base;pwr*=primes[pr])
			factPwr[base][pr]+=(base/pwr);
	}
	return;
}

void nCr(int tot, int opt, int ret[])
{
	if(opt==0)		return;

	calPowers(tot);
	calPowers(opt);		calPowers(tot-opt);

	for(int i=0;i<P && primes[i]<=tot;i++){
		ret[i]+=factPwr[tot][i];
		ret[i]-=(factPwr[opt][i]+factPwr[tot-opt][i]);
	}
}

int numr[170],denr[170];

int main()
{
	preCompute();

	int T;
	scanf("%d",&T);

	int S,N,M,K;
	double tot;
	while(T--){
		scanf("%d%d%d%d",&S,&N,&M,&K);

		MEM(denr,0);
		nCr(S-1,N-1,denr);

		tot=0;
		FOR(frd,K,M){
			int notCh=M-1-frd;

			if(frd<=(N-1) && notCh<=(S-N)){
				MEM(numr,0);
				nCr(M-1,frd,numr);
				nCr(S-M,N-frd-1,numr);

				double tmp=1;
				FOR(i,0,P){
					int dif=numr[i]-denr[i];
					for(int j=1;j<=abs(dif);j++){
						if(dif<0)
							tmp/=double(primes[i]);
						else if(dif>0)
							tmp*=double(primes[i]);
					}
				}
				tot+=tmp;
			}
		}

		printf("%.6lf\n",tot);
	}

	return 0;
}
