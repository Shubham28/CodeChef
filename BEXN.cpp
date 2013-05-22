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
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define PII pair<int,int>

using namespace std;

int remn[1000002];
char name[1000002][17];
int stk[1000002];

int main()
{
	int T;
	scanf("%d",&T);

	int inp,len=0;
	FOR(a,0,T){
		scanf("%d",&inp);

		if(inp==-1){
			int mn=stk[len-1];
			printf("%d %s\n",(len-1-mn),name[mn]);

			len=mn;
		} else {
			remn[len]=inp;
			scanf("%s",name[len]);

			if(inp>0){
				stk[len]=(len==0 || inp<=remn[stk[len-1]])?len:stk[len-1];
				len++;
			}
		}
	}

	return 0;
}
