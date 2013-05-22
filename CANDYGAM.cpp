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

int A[51][51];
int N,M;

LL preR[51][51],preC[51][51];
LL cumSum[51][51];
LL optAlc[2][51][51][51];
LL optBob[2][51][51][51];

inline LL MX(LL A,LL B)
{	return (A>=B)?A:B;	}

void calcPrefixSum()
{
	MEM(preR,0);	MEM(preC,0);

	FOR(i,0,N){
		preR[i][0]=A[i][0];
		FOR(j,1,M)		preR[i][j]=preR[i][j-1]+A[i][j];
	}
	FOR(j,0,M){
		preC[0][j]=A[0][j];
		FOR(i,1,N)		preC[i][j]=preC[i-1][j]+A[i][j];
	}
}

void calcSum()
{
	MEM(cumSum,0);

	FOR(i,0,N)		FOR(j,0,M){
		LL abv=0,lft=0,diag=0;

		if(i)	abv=cumSum[i-1][j];
		if(j)	lft=cumSum[i][j-1];
		if(i && j)		diag=cumSum[i-1][j-1];

		cumSum[i][j]=A[i][j]+abv+lft-diag;
	}
}

LL findSum(int r1,int c1,int r2,int c2)
{
	LL abv=0,lft=0,diag=0;

	if(r1)	abv=cumSum[r1-1][c2];
	if(c1)	lft=cumSum[r2][c1-1];
	if(r1 && c1)		diag=cumSum[r1-1][c1-1];

	return cumSum[r2][c2]-abv-lft+diag;
}

int main()
{
	int T;
	Input(T);

	while(T--){
		Input(N),Input(M);
		FOR(i,0,N)		FOR(j,0,M)
			Input(A[i][j]);

		calcPrefixSum();
		calcSum();

		MEM(optAlc,0);		MEM(optBob,0);

		EFOR(rLen,1,N){
			int now=rLen&1,prev=(rLen-1)&1;
			MEM(optAlc[now],0);			MEM(optBob[now],0);

			EFOR(cLen,1,M){

				EFOR(rw1,0,N-rLen)	EFOR(cl1,0,M-cLen){
					LL &tmpA=optAlc[now][cLen][rw1][cl1];
					LL &tmpB=optBob[now][cLen][rw1][cl1];
					tmpB=-1;

					int rw2=rw1+rLen-1,cl2=cl1+cLen-1;
					LL tot=findSum(rw1,cl1,rw2,cl2);

					if(rLen==1 && cLen==1)
						tmpA=tmpB=A[rw1][cl1];
					else {
						if(rLen>1){
							tmpB=MX(tmpB,tot-optAlc[prev][cLen][rw1+1][cl1]);
							tmpB=MX(tmpB,tot-optAlc[prev][cLen][rw1][cl1]);
						} else
							tmpB=tot;

						if(cLen>1){
							tmpB=MX(tmpB,tot-optAlc[now][cLen-1][rw1][cl1+1]);
							tmpB=MX(tmpB,tot-optAlc[now][cLen-1][rw1][cl1]);
						} else 
							tmpB=MX(tmpB,tot);

						LL firstR=preR[rw1][cl2]-((cl1>0)?preR[rw1][cl1-1]:0);
						LL lastR=preR[rw2][cl2]-((cl1>0)?preR[rw2][cl1-1]:0);
						LL firstC=preC[rw2][cl1]-((rw1>0)?preC[rw1-1][cl1]:0);
						LL lastC=preC[rw2][cl2]-((rw1>0)?preC[rw1-1][cl2]:0);

						if(firstR<=lastR && firstR<=firstC && firstR<=lastC)
							tmpA=tot-optBob[prev][cLen][rw1+1][cl1];
						else if(lastR<=firstR && lastR<=firstC && lastR<=lastC)
							tmpA=tot-optBob[prev][cLen][rw1][cl1];
						else if(firstC<=firstR && firstC<=lastR && firstC<=lastC)
							tmpA=tot-optBob[now][cLen-1][rw1][cl1+1];
						else if(lastC<=firstR && lastC<=lastR && lastC<=firstC)
							tmpA=tot-optBob[now][cLen-1][rw1][cl1];						
					}
				}
			}
		}
		LL alice=optAlc[N&1][M][0][0];
		LL bob=findSum(0,0,N-1,M-1)-alice;
		printf("%lld\n",(alice==bob)?alice+bob:MX(alice,bob));
	}

	return 0;
}
