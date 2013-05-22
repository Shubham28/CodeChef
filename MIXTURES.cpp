#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int main()
{
	vector< VI >mixt,smoke;
	FOR(ins,0,105){
		PB(mixt,VI(105-ins,0));
		PB(smoke,VI(105-ins,0));
	}

	int N;
	while(scanf("%d",&N)!=EOF){
		FOR(inp,0,N){
			Input(mixt[inp][0]);
			smoke[inp][0]=0;
		}

		FOR(len,1,N)
			FOR(pos,0,N-len){
				int tmix,tsmk=99999999;

				FOR(brk,0,len){
					int val=mixt[pos][brk]*mixt[pos+brk+1][len-brk-1]+smoke[pos][brk]+smoke[pos+brk+1][len-brk-1];
					if(val<=tsmk)
						tmix=(mixt[pos][brk]+mixt[pos+brk+1][len-brk-1])%100,tsmk=val;
				}

				mixt[pos][len]=tmix,smoke[pos][len]=tsmk;
		}
		printf("%d\n",smoke[0][N-1]);
	}

	return 0;
}
