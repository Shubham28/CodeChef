#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>

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
	while((ch=getchar())>='0'&&ch<='9');

	return;
}

int main()
{
	int N;
	Input(N);

	int dist[255][255];

	FOR(rw,0,N)		FOR(cl,0,N)
		Input(dist[rw][cl]);

	FOR(bt,0,N)
		FOR(fr,0,N)		FOR(to,0,N){
			dist[fr][to]=min(dist[fr][to],dist[fr][bt]+dist[bt][to]);
		}

	int M,R,G,D;
	Input(M);

	int tot;
	while(M--){
		Input(R),Input(G),Input(D);
		tot=dist[R][G]+dist[G][D];

		printf("%d %d\n",tot,tot-dist[R][D]);
	}

	return 0;
}
