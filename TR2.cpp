#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>

#define FOR(A,B,C) for(short A=B;A<C;A++)
#define ALL(A) A.begin(),A.end()
#define SZ(A) short(A.size())

using namespace std;

short T,M,N,fir,sec;
char dirn;
short ans[101];

struct nodeDep{
	short dep,count;
	struct nodeDep *left,*right;
};

inline void calcPath(pair<short,short>graphs[],struct nodeDep *first, short node)
{
	short chk=first->count-1;
	if(chk>=0)
		ans[chk]=max(ans[chk],first->dep);

	short leftind=graphs[node].first;
	if(leftind!=-1){

		if(first->left==NULL){
			struct nodeDep *subl;
			subl=new struct nodeDep;
			subl->count=0,subl->dep=first->dep+1;
			subl->left=NULL,subl->right=NULL;
			first->left=subl;
		}
		(first->left)->count+=1;
		calcPath(graphs,first->left,leftind);
	}

	short rightind=graphs[node].second;
	if(rightind!=-1){

		if(first->right==NULL){
			struct nodeDep *subr;
			subr=new struct nodeDep;
			subr->count=0,subr->dep=first->dep+1;
			subr->left=NULL,subr->right=NULL;
			first->right=subr;
		}
		(first->right)->count+=1;
		calcPath(graphs,first->right,rightind);
	}

	return;
}

int main()
{
	scanf("%hd",&T);
	while(T--){
		scanf("%hd",&M);

		struct nodeDep *first;
		first=new struct nodeDep;
		first->count=0,first->dep=0;
		first->left=NULL,first->right=NULL;

		memset(ans,0,sizeof(ans));

		FOR(each,0,M){
			scanf("%hd",&N);

			pair<short,short>graphs[N];
			memset(graphs,-1,sizeof(graphs));

			FOR(city,0,N-1){
				scanf("%hd",&fir);
				scanf("%1s",&dirn);
				scanf("%hd",&sec);

				if(dirn=='L')
					graphs[fir-1].first=sec-1;
				else
					graphs[fir-1].second=sec-1;
			}
			calcPath(graphs,first,0);
		}

		FOR(res,0,M-1)
			printf("%hd ",ans[res]);
		printf("%hd\n",ans[M-1]);

	}

	return 0;
}
