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

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	char bld[1001];
	int L,ans=0;

	while(T--){
		MEM(bld,0);
		scanf("%d%s",&L,bld);

		FOR(a,0,L){
			if(bld[a]=='0' && a+1<L && bld[a+1]=='1')
				bld[a]='1';

			if(bld[a]=='1' && a+1<L && bld[a+1]=='0'){
				bld[a++ + 1]='1';
			}
		}
		printf("%d\n",count(bld,bld+L,'0'));
	}

	return 0;
}
