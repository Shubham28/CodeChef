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

int main()
{
	int T,N,M;
	Input(T);

	int snt[101],sfl[101];

	while(T--){
		Input(N),Input(M);
		MEM(snt,0);		MEM(sfl,0);

		int val,lvl;
		FOR(i,0,N){
			Input(val),Input(lvl);
			snt[lvl]+=val;
		}
		FOR(i,0,M){
			Input(val),Input(lvl);
			sfl[lvl]+=val;
		}

		int add=0;
		FOR(i,1,101){
			int dif=snt[i]-sfl[i];
			if(dif<0)
				add-=dif;
		}
		printf("%d\n",add);
	}

	return 0;
}
