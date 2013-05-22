#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <sstream>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SZ(A) A.size()

using namespace std;

int dist[105][105];

int main()
{
//	freopen("Input.txt","r",stdin);
	int T,N;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		cin.ignore(1,'\n');

		FOR(rw,0,N+1)		FOR(cl,0,N+1)
			dist[rw][cl]=100000000;

		string tmp;
		FOR(f,0,N){
			getline(cin,tmp);

			stringstream sstr;
			sstr<<tmp;
			int val;
			while(sstr>>val)
				dist[f][val-1]=1;
		}

		FOR(dg,0,N)	dist[dg][dg]=0;

		FOR(md,0,N)
			FOR(fr,0,N)		FOR(to,0,N)
				dist[fr][to]=min(dist[fr][to],dist[fr][md]+dist[md][to]);

		int popl=0;
		double ave=10000000.;
		FOR(rw,0,N){
			double tmp=accumulate(dist[rw],dist[rw]+N,0);
			tmp/=(double)N;
			if(tmp<ave)
				popl=rw,ave=tmp;
		}
		printf("%d %6lf\n",popl+1,ave);
	}

	return 0;
}
