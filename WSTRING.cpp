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

char inp[10005];
int L;

int lTot[10005],rTot[10005];
int betw[10005],cnt[30];
int lt,rt,bt;

void cntTotal(int opt[],int &len,int ini,int dirn)
{
	len=0;
	MEM(cnt,0);

	int best=0;
	for(int i=ini;i>=0 && i<L;i+=dirn){
		if(inp[i]=='#')
			opt[len++]=best;
		else {
			cnt[inp[i]-'a']++;
			best=max(best,cnt[inp[i]-'a']);
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);

	int best;
	while(T--){
		scanf("%s",inp);
		L=strlen(inp);

		cntTotal(lTot,lt,0,1);
		cntTotal(rTot,rt,L-1,-1);
		reverse(rTot,rTot+rt);

		bt=0,best=0;
		MEM(cnt,0);		MEM(betw,0);

		FOR(i,0,L){
			if(inp[i]=='#'){
				betw[bt++]=best;
				MEM(cnt,0);
				best=0;
			} else {
				cnt[inp[i]-'a']++;
				best=max(best,cnt[inp[i]-'a']);
			}
		}

		int ans=0;
		FOR(i,0,bt)
			if(lTot[i]>0 && betw[i+1]>0 && betw[i+2]>0 && rTot[i+2]>0)
				ans=max(ans,lTot[i]+betw[i+1]+betw[i+2]+rTot[i+2]+3);

		printf("%d\n",ans);
	}

	return 0;
}
