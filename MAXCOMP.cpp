#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define SZ(A) int(A.size())

using namespace std;

inline void Input(int &N)
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

vector< VI >ord(2005, VI(3));
int cmpn[2005];

bool cmp(VI o1,VI o2)
{
	if(o1[1]<o2[1])			return 1;
	else if(o2[1]<o1[1])	return 0;
	else
		return o1[0]<o2[0];
}

int main()
{
	int T;
	Input(T);

	int N,ans;
	while(T--){
		Input(N);

		FOR(i,0,N)
			Input(ord[i][0]),Input(ord[i][1]),Input(ord[i][2]);

		sort(ord.begin(),ord.begin()+N,cmp);
		MEM(cmpn,0);

		ans=0;
		FOR(now,0,N){
			cmpn[now]=ord[now][2];

			FOR(prv,0,now)
				if(ord[prv][0]<ord[now][0] && ord[prv][1]<=ord[now][0])
					cmpn[now]=max(cmpn[now],cmpn[prv]+ord[now][2]);

			ans=max(ans,cmpn[now]);
		}
		printf("%d\n",ans);
	}

	return 0;
}
