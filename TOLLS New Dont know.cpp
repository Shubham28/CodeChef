#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{

	int T;
	scanf("%d",&T);

	while(T--){
		int N,M;
		scanf("%d",&N);
		scanf("%d",&M);

		int S,E,B;
		long double tot=0;
		FOR(inp,0,M){
			scanf("%d",&S);
			scanf("%d",&E);
			scanf("%d",&B);
			tot+=pow(B+0.0l,125.0l/64.0l);
		}
		tot/=(long double)(M);
		tot=pow(tot,64.0l/125.0l);
		tot/=(N-1);
		tot*=2;
		int ans=int(ceil(tot)+1e-7);
		if(ans<=0)
			ans=1;
		else if(ans>=1000000)
			ans=999999;

	}

	return 0;
}
