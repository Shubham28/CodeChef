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

int main()
{
	int T;
	Input(T);

	int N,M,K;
	int cnt;
	while(T--){
		Input(N),Input(M),Input(K);

		if(N>M)
			swap(N,M);

		if(N==1 && (M==1 || M==2))
			cnt=0;
		else
			cnt=((N==1)?K:int(ceil(K/2.0)+1e-9));

		printf("%d\n",cnt);
	}

	return 0;
}
