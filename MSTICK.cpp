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
	while((ch=getchar())>='0'&&ch<='9');

	return;
}

int N,fr,to;
int ar[100005];

int minSg[400005],maxSg[400005];

void init(int ind,int st,int en)
{
	if(st==en){
		minSg[ind]=st;
		maxSg[ind]=st;
	} else {
		int nxt=ind<<1,mid=(st+en)>>1;
		init(nxt,st,mid);
		init(nxt+1,mid+1,en);

		if(ar[minSg[nxt]]<=ar[minSg[nxt+1]])
			minSg[ind]=minSg[nxt];
		else
			minSg[ind]=minSg[nxt+1];

		if(ar[maxSg[nxt]]>=ar[maxSg[nxt+1]])
			maxSg[ind]=maxSg[nxt];
		else
			maxSg[ind]=maxSg[nxt+1];
	}
	return;
}

int query(int ind,int st,int en,bool isMin)
{
	int p1,p2;

	if(fr>en || to<st)		return -1;
	if(fr<=st && en<=to)		return (isMin)?minSg[ind]:maxSg[ind];

	int nxt=ind<<1,mid=(st+en)>>1;
	p1=query(nxt,st,mid,isMin);
	p2=query(nxt+1,mid+1,en,isMin);

	if(p1==-1)		return p2;
	if(p2==-1)		return p1;
	if(ar[p1]<=ar[p2])		return (isMin)?p1:p2;

	return (isMin)?p2:p1;
}

int main()
{
	Input(N);
	FOR(i,0,N)
		Input(ar[i]);

	init(1,0,N-1);

	int Q,L,R;
	Input(Q);
	while(Q--){
		Input(L),Input(R);

		fr=L,to=R;
		int fastest=ar[query(1,0,N-1,true)];

		double ret=fastest;

		int center=ar[query(1,0,N-1,false)];
		ret=max(ret,fastest+(center-fastest)/2.);

		int left=-1;
		if(L>0){
			fr=0,to=L-1;
			left=ar[query(1,0,N-1,false)];
			ret=max(ret,fastest+left+0.);
		}

		int right=-1;
		if(R<N-1){
			fr=R+1,to=N-1;
			right=ar[query(1,0,N-1,false)];
			ret=max(ret,fastest+right+0.);
		}

		printf("%.1lf\n",ret);
	}

	return 0;
}
