#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

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

int main()
{
	int T;
	Input(T);

	int N,K,R,J;
	int rom[100005],jul[100005];

	while(T--){
		Input(N),Input(K);

		Input(R);
		EFOR(a,1,R)
			Input(rom[a]);

		Input(J);
		EFOR(a,1,J)
			Input(jul[a]);

		sort(rom,rom+R);	sort(jul,jul+J);

		int frRm,toRm;
		if(R==0 || rom[1]>K)
			frRm=0,toRm=0;
		else if(rom[1]<=K){
			frRm=1;
			for(int a=1;a<=R;a++){
				if(rom[a]<=K)
					toRm=a;
				else
					break;
			}
		}

		int frJl,toJl;
		if(J==0 || jul[1]>K)
			frJl=0,toJl=0;
		else {
			frJl=1;
			for(int a=1;a<=J;a++){
				if(jul[a]<=K)
					toJl=a;
				else
					break;
			}
		}

		int spnd=(frRm==0)?K:(K-toRm+frRm-1);
		int work=(frJl==0)?0:(toJl-frJl+1);
		int pos=1;

		if(spnd==0 && work==0){
			printf("1\n");
			continue;
		}

		int hol,miss;
		EFOR(dy,2,N-K+1){
			if(rom[frRm]<dy)		++frRm;
			if(jul[frJl]<dy)		++frJl;

			if(toRm+1<=R && rom[toRm+1]<=dy+K-1)		++toRm;
			if(toJl+1<=J && jul[toJl+1]<=dy+K-1)		++toJl;

			if(frRm>R || rom[frRm]>=dy+K)		hol=K;
			else
				hol=K-(toRm-frRm+1);

			if(frJl>J || jul[frJl]>=dy+K)
				miss=0;
			else
				miss=toJl-frJl+1;

			if(hol>spnd)
				spnd=hol,work=miss,pos=dy;
			else if(hol==spnd && miss<work)
				work=miss,pos=dy;
		}
		printf("%d\n",pos);
	}

	return 0;
}
