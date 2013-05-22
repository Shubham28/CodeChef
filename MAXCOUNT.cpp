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

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int N;
	int elm[10005];

	while(T--){
		scanf("%d",&N);
		MEM(elm,0);

		int mx,frq=-1,tmp;
		FOR(a,0,N){
			scanf("%d",&tmp);
			++elm[tmp];

			if( (elm[tmp]>frq) || (elm[tmp]==frq && tmp<mx))
				mx=tmp,frq=elm[tmp];
		}

		printf("%d %d\n",mx,frq);
	}

	return 0;
}
