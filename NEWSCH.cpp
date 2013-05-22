#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())
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

/*
T(n) = 12,36,108,324,972
D(n) = 12,24,84,240,732

D(n) = T(n)-D(n-1)

D(3) = T(3)-D(2)
	 = T(3)-{T(2)-D(1)}
	 = T(3)-{T(2)-T(1)-D(0)}
	 = T(3)-T(2)+T(1)

D(n) is sum of GP with ratio -3
*/

const ULL MOD=1000000007;
const ULL modInv4=250000002;

int main()
{

	int T,N;
	Input(T);

	while(T--){
		Input(N);

		if(N==2)
			printf("12\n");
		else if(N==3)
			printf("24\n");
		else {
			ULL pow3=1,bs=3;
			for(int exp=N-1;exp!=0;exp>>=1,bs=(bs*bs)%MOD)
				if(exp&1)
					pow3=(pow3*bs)%MOD;

			ULL num=pow3+((N&1)?-1:1);
			num=(num*modInv4)%MOD;
			ULL D=(num*12)%MOD;

			printf("%lld\n",(long long)D);
		}
	}

	return 0;
}
