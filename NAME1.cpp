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
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

void addCount(int cnt[], char name[], int L)
{
	FOR(i,0,L)
		cnt[name[i]-'a']++;

	return;
}

int main()
{
	int T;
	scanf("%d",&T);

	int N;
	char name[40100];
	int par[30],child[30];

	while(T--){
		MEM(par,0);	MEM(child,0);

		scanf("%s",name);
		addCount(par,name,strlen(name));

		scanf("%s",name);
		addCount(par,name,strlen(name));

		scanf("%d",&N);
		FOR(i,0,N){
			scanf("%s",name);
			addCount(child,name,strlen(name));
		}

		bool posb=1;
		FOR(i,0,28)
			if(par[i]<child[i]){
				posb=0;
				break;
			}

		printf("%s\n",(posb)?"YES":"NO");
	}

	return 0;
}
