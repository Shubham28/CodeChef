#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	LL N;

	scanf("%d",&T);
	while(T--){
		scanf("%lld",&N);

		int ln=1;
		for(int ps=0;(N>>ps)>1;ln++,ps++);

		for(int op=0;op<ln-1;op++)
			printf("(");

		for(int ps=ln-1;ps>0;ps--){
			if((N>>ps)&1)
				printf("A");
			printf(")");
		}
		if(N&1)
			printf("A");

		printf("\n");
	}

//	fclose(stdin);
	return 0;
}
