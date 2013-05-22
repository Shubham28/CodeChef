#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
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

int main()
{
	int N,W;
	Input(N),Input(W);
	W--;

	int ht[400005];
	deque<int>mnQ,mxQ;

	int ans=0;
	FOR(i,0,N){
		Input(ht[i]);

		while(!mnQ.empty() && ht[mnQ.front()]>ht[i])
			mnQ.pop_front();
		mnQ.push_front(i);

		while(!mxQ.empty() && ht[mxQ.front()]<ht[i])
			mxQ.pop_front();
		mxQ.push_front(i);

		if(i>=W){
			if(ht[mxQ.back()]-ht[mnQ.back()]==W)
				++ans;

			if(!mnQ.empty() && mnQ.back()==(i-W))
				mnQ.pop_back();

			if(!mxQ.empty() && mxQ.back()==(i-W))
				mxQ.pop_back();
		}
	}
	printf("%d\n",ans);

	return 0;
}
