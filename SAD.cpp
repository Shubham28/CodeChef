#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define ALL(A) A.begin(),A.end()
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
	int R,C;
	Input(R),Input(C);

	int inp[101][101];

	int lo[101],hi[101];
	list<int>rws[101];
	list<int>cls[101];

	FOR(i,0,101)
		lo[i]=100000005;

	MEM(hi,-1);

	FOR(r,0,R){
		FOR(c,0,C){
			Input(inp[r][c]);

			if(inp[r][c]<lo[r]){
				rws[r].clear();
				lo[r]=inp[r][c];
				PB(rws[r],c);

			} else if(inp[r][c]==lo[r])
				PB(rws[r],c);

			if(inp[r][c]>hi[c]){
				cls[c].clear();
				hi[c]=inp[r][c];
				PB(cls[c],r);

			} else if(inp[r][c]==hi[c])
				PB(cls[c],r);
		}
	}

	int ans=-1;
	FOR(a,0,R){
		int chk=lo[a];
		for(list<int>::iterator it=rws[a].begin();it!=rws[a].end();it++){
			int use=*it;
			if(chk==hi[use]){
				ans=chk;
				break;
			}
		}
	}

	if(ans!=-1)
		printf("%d\n",ans);
	else
		printf("GUESS\n");

	return 0;
}
