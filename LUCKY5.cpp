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

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	char inp[100005];
	while(T--){
		scanf("%s",&inp);

		int ans=0,L=strlen(inp);
		FOR(a,0,L)
			if(inp[a]!='4' && inp[a]!='7')
				++ans;

		printf("%d\n",ans);
	}

	return 0;
}
