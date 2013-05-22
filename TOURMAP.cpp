#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <set>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

set<string>begn;

void putOrDelete(string &chk)
{
	if(begn.find(chk)==begn.end())
		begn.insert(chk);
	else
		begn.erase(chk);
}

int main()
{
	int T,N;
	scanf("%d",&T);

	char inp[5001][3][52];
	map<string,int>indx;

	while(T--){
		begn.clear();	indx.clear();

		scanf("%d",&N);
		FOR(i,1,N){
			scanf("%s%s%s",inp[i][0],inp[i][1],inp[i][2]);

			string frm(inp[i][0]),to(inp[i][1]);
			putOrDelete(frm);
			putOrDelete(to);

			indx[frm]=i;
		}

		int city;
		if(indx.find(*begn.begin())!=indx.end())
			city=indx[*begn.begin()];
		else {
			set<string>::iterator it=begn.begin();
			it++;
			city=indx[*it];
		}		

		int cost=0;
		while(city!=-1){
			printf("%s %s %s\n",inp[city][0],inp[city][1],inp[city][2]);

			inp[city][2][strlen(inp[city][2])-1]=0;
			cost+=atoi(inp[city][2]);

			string nxt=string(inp[city][1]);
			if(indx.find(nxt)==indx.end())
				city=-1;
			else
				city=indx[nxt];
		}
		printf("%d$\n",cost);
	}

	return 0;
}
