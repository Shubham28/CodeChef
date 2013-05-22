#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define PB(A,B) A.push_back(B);
#define PII pair<int,int>

using namespace std;

int dr[]={-1,0,0,1};
int dc[]={0,-1,1,0};

int main()
{
	int T;
	scanf("%d",&T);

	char grid[101][101];
	int R,C;
	PII S,D;
	int dist[101][101];

	while(T--){
		scanf("%d %d",&R,&C);
		scanf("%d %d",&S.first,&S.second);
		scanf("%d %d",&D.first,&D.second);

		FOR(rw,0,R)
			scanf("%s",grid[rw]);

		if(S.first==D.first && S.second==D.second){
			printf("0\n");
			continue;
		}

		MEM(dist,-1);
		queue< PII >brd;

		dist[S.first][S.second]=0;
		brd.push(S);

		while(!brd.empty()){
			PII prs=brd.front();
			int cst=dist[prs.first][prs.second];
			brd.pop();

			FOR(a,0,4)
				for(int ml=1;;ml++){
					int nr=prs.first+ml*dr[a],nc=prs.second+ml*dc[a];

					if(0<=nr && nr<R && 0<=nc && nc<C && grid[nr][nc]!='#'){
						if(dist[nr][nc]==-1){
							dist[nr][nc]=cst+1;
							brd.push(PII(nr,nc));
						}
					} else
						break;
				}
		}

		if(dist[D.first][D.second]!=-1)
			printf("%d\n",dist[D.first][D.second]);
		else
			printf("0\n");
	}

	return 0;
}
