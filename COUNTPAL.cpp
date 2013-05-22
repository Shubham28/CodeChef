#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define VB vector<bool>
#define PB(A,B) A.push_back(B);
#define LL long long
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	char inp[1050];
	int MOD=1000000007;

	scanf("%s",inp);
	int N=strlen(inp);

	vector< VB >pal;
	FOR(row,0,N+5)
		PB(pal,VB(N+5-row,false));

	FOR(row,0,N+5)
		pal[row][0]=1;

	FOR(len,1,N)
		FOR(pos,0,N-len){
			if(inp[pos]!=inp[pos+len])
				pal[pos][len]=false;
			else {
				if(len==1)
					pal[pos][len]=true;
				else 
					pal[pos][len]=pal[pos+1][len-2];
			}
		}

	LL ways[N+5];
	memset(ways,0,sizeof(ways));
	ways[0]=1;

	FOR(pos,1,N){
		LL tmp=pal[0][pos];
		FOR(brk,0,pos)
			if(pal[brk+1][pos-brk-1])
				tmp+=ways[brk],tmp%=MOD;

		ways[pos]=tmp;
	}
	printf("%lld\n",ways[N-1]);

	return 0;
}
