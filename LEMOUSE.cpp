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
#define LL long long

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int R,C;
	bool grid[102][102];
	int cnt[102][102][2];

	bool left,right,above,below;
	char tmp[102];
	while(T--){
		scanf("%d%d",&R,&C);

		FOR(i,0,R){
			scanf("%s",tmp);
			FOR(j,0,C)
				grid[i][j]=tmp[j]-'0';
		}

		MEM(cnt,0);

		int ini=grid[0][0]+grid[0][1]+grid[1][0]+grid[1][1];
		cnt[1][0][1]=ini+((R>2)?grid[2][0]:0);
		cnt[0][1][0]=ini+((C>2)?grid[0][2]:0);
		cnt[1][0][0]=cnt[0][1][1]=20000;


		FOR(rw,0,R)		FOR(cl,0,C)
			if(rw+cl>=2){
				//	2-bit encoding for last position

				above=(rw>0)?grid[rw-1][cl]:0;
				below=(rw+1<R)?grid[rw+1][cl]:0;

				left=(cl>0)?grid[rw][cl-1]:0;
				right=(cl+1<C)?grid[rw][cl+1]:0;

				if(cl>0)
					cnt[rw][cl][0]=min(cnt[rw][cl-1][0]+above+below+right,cnt[rw][cl-1][1]+below+right);
				else
					cnt[rw][cl][0]=20000;

				if(rw>0)
					cnt[rw][cl][1]=min(cnt[rw-1][cl][0]+below+right,cnt[rw-1][cl][1]+left+right+below);
				else
					cnt[rw][cl][1]=20000;
			}

		printf("%d\n",min(cnt[R-1][C-1][0],cnt[R-1][C-1][1]));
	}

	return 0;
}
