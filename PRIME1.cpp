#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

inline void Input(LL &inp)
{
	int ch;
	inp=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		inp=(inp<<3)+(inp<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

#define N 10000000
unsigned int prime[N/64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieveFull()
{
    memset(prime,-1,sizeof(prime));

    unsigned int i;
    unsigned int sqrtN=(unsigned int)sqrt(double(N))+1;

	for(i=3;i<sqrtN;i+=2)
		if(gP(i)){
	        unsigned int i2=i + i;
		    for(unsigned int j=i*i;j<N;j+=i2)
				rP(j);
		}
	return;
}

bool chk[100001];

void sieveRange(LL L,LL U)
{
	int range=U-L+1;

	FOR(all,0,range)
		chk[all]=true;

	for(LL i=1;i<range;i+=2)
		chk[i]=false;

	for(LL i=3;i*i<=U;i+=2){

		if(i>L && !chk[i-L])
			continue;

		LL j=(L/i)*i;
		if(j<L)
			j+=i;
		if(j==i)
			j+=i;
		j-=L;

		for(;j<range;j+=i)
			chk[j]=false;
	}

	FOR(i,0,range)
		if(chk[i])
			printf("%lld\n",(L+i));

	return;
}

int main()
{
	LL T;
	Input(T);

	sieveFull();
	while(T--){
		LL low,high;

		Input(low),Input(high);
		if(low<=2 && high>=2)
			printf("2\n");

		low=max(low,3ll);
		low=(low%2)?low:(low+1);

		high=(high%2)?high:(high-1);

		if(high<10000000){
			for(LL chk=low;chk<=high;chk+=2)
				if(gP(chk))
					printf("%lld\n",chk);
		} else if(low<10000000){
			for(LL chk=low;chk<10000000;chk+=2)
				if(gP(chk))
					printf("%lld\n",chk);
		} else
			sieveRange(low,high);

		printf("\n");
	}

	return 0;
}
