#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

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
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int N,K;
	list<int>pos[100001];
	map<int,int>id;

	Input(N),Input(K);

	int tmp,val=0;
	FOR(i,0,N){
		Input(tmp);
		if(id.find(tmp)==id.end())
			id[tmp]=val++;

		PB(pos[id[tmp]],i);
	}
	
	int tot=0;
	FOR(i,0,val){
		list<int>::iterator it=pos[i].begin();
		int lft=*it;

		tot++,it++;

		while(it!=pos[i].end()){
			if((*it)+1-lft>K){
				tot++;
				lft=(*it);
			}
			it++;
		}
	}
	printf("%d\n",tot);	

	return 0;
}
