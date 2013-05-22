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
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

bool isSubSeq(char lrg[],int L,char sml[], int S)
{
	int pos=0;
	for(int dn=0;dn<S;dn++,pos++){
		if(pos==L)		return 0;

		while(lrg[pos]!=sml[dn]){
			if(pos==L-1)	return 0;

			pos++;
		}
	}
	return 1;
}

int main()
{
	int T;
	scanf("%d",&T);

	char husb[25005],wife[25005];
	while(T--){
		scanf("%s%s",husb,wife);
		int H=strlen(husb),W=strlen(wife);

		bool posb;

		if(H==W)
			posb=(strcmp(husb,wife)==0);
		else if(H<W)
			posb=isSubSeq(wife,W,husb,H);
		else
			posb=isSubSeq(husb,H,wife,W);

		printf("%s\n",(posb)?"YES":"NO");
	}

	return 0;
}
