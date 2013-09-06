#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

#define L 100030
#define UI unsigned int
UI prime[L/64];

#define gP(n) (n==2 || ( (n&1) && (prime[n>>6]&(1<<((n>>1)&31))) ))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

int P=0;
int primes[9610];

void sieve()
{
	MEM(prime,-1);

	UI i,sqrtN=(UI)sqrt((double)L)+1;

	for(i=3;i<sqrtN;i+=2)
		if(gP(i)){
			UI i2=i+i;
			for(UI j=i*i;j<L;j+=i2)		rP(j);
		}
}

bool kFactr[100002][5];
int cumF[100002][5];

void preCompute()
{
	sieve();
	MEM(kFactr,0);

	EFOR(i,2,L-30){
		if(gP(i)){
			primes[P++]=i;
			kFactr[i][1]=1;
		} else {
			int cnt=0,dup=i;

			for(int chk=0;primes[chk]*primes[chk]<=dup && cnt<=5;chk++)
				if(dup%primes[chk]==0){
					dup/=primes[chk];
					cnt++;

					while(dup%primes[chk]==0)
						dup/=primes[chk];
				}

			if(dup!=1)
				cnt++;

			if(cnt<=5)
				kFactr[i][cnt]=1;
		}
	}

	MEM(cumF,0);
	EFOR(j,2,L-30)
		EFOR(all,1,5)
			cumF[j][all]=cumF[j-1][all]+kFactr[j][all];
}

int main()
{
	preCompute();

	int T;
	Input(T);

	int A,B,K;
	while(T--){
		Input(A),Input(B),Input(K);

		printf("%d\n",cumF[B][K]-cumF[A-1][K]);
	}

	return 0;
}
