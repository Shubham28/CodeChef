#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define ULL unsigned long long

using namespace std;

inline void Input(ULL &N)
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
	int N;
	scanf("%d",&N);

	if(N>=70){
		printf("Yes\n");
		return 0;
	}

	set<int>cnt[65];
	map<ULL,int>used;
	bool pair=0;

	ULL prev,now;
	Input(prev);
	++used[prev];

	FOR(i,1,N){
		Input(now);
		++used[now];

		if((used[now]==2 && pair) || used[now]==4){
			printf("Yes\n");
			return 0;
		}
		if(used[now]==2)
			pair=1;

		FOR(ps,0,64)
			if( ((now>>ps)&1)!=((prev>>ps)&1) ){
				if(cnt[ps].find(i-1)==cnt[ps].end()){
					cnt[ps].insert(i);

					if(SZ(cnt[ps])>1){
						printf("Yes\n");
						return 0;
					}
				}
			}

		prev=now;
	}
	printf("No\n");

	return 0;
}
