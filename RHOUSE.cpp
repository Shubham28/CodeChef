#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

struct edge{
	int fr,to;
	int cst;
};

int V,E;
edge *con[400005];
bool rest[100005],rch[100005];

int P[100005],rnk[100005];

void createSet(int nm)
{		P[nm]=nm,rnk[nm]=rch[nm]=0;		}

int findSet(int nm)
{
	if(nm!=P[nm])
		P[nm]=findSet(P[nm]);

	return P[nm];
}

void mergeSet(int x,int y)
{
	int px=findSet(x);
	int py=findSet(y);

	if(px==py)		return;

	if(rnk[px]>=rnk[py])		P[py]=px;
	else		P[px]=py;

	if(rnk[px]==rnk[py])	rnk[px]++;
	return;
}

bool cmp(edge *fr,edge *sc)
{
	return (fr->cst<sc->cst);
}

int main()
{
	int T;
	scanf("%d",&T);

	EFOR(ini,0,400000)
		con[ini]=new edge;

	char ser[100005];
	while(T--){
		scanf("%d%d",&V,&E);

		scanf("%s",ser);
		FOR(a,0,V){
			rest[a]=(ser[a]=='R');
			if(!rest[a])
				createSet(a);
		}

		FOR(a,0,E){
			scanf("%d%d%d",&(con[a]->fr),&(con[a]->to),&(con[a]->cst));
			--(con[a]->fr),--(con[a]->to);
		}
		sort(con,con+E,cmp);

		LL ans=0;
		FOR(a,0,E){
			int nd1=con[a]->fr,nd2=con[a]->to;
			int val=con[a]->cst;

			if(val<=0){
				ans+=val;
				if(rest[nd1] && rest[nd2])
					continue;

				if(!rest[nd1] && !rest[nd2]){
					int p1=findSet(nd1),p2=findSet(nd2);
					bool now=rch[p1]|rch[p2];

					rch[p1]=rch[p2]=now;
					mergeSet(p1,p2);
				} else {
					if(rest[nd2])
						swap(nd1,nd2);

					int pr=findSet(nd2);
					rch[pr]=1;
				}
			} else {
				if(rest[nd1] && rest[nd2])
					continue;

				if(!rest[nd1] && !rest[nd2]){
					int p1=findSet(nd1),p2=findSet(nd2);
					if(p1==p2)
						continue;

					bool r1=rch[p1],r2=rch[p2];
					if(r1 && r2)
						continue;

					ans+=val;
					rch[p1]=rch[p2]=r1|r2;
					mergeSet(p1,p2);
				} else {
					if(rest[nd2])
						swap(nd1,nd2);

					int pr=findSet(nd2);
					if(rch[pr])
						continue;

					ans+=val;
					rch[pr]=1;
				}
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
