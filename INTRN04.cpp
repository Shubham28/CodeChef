#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	int cst[105][105];
	char inp[105],fir[105],sec[105];

	scanf("%d",&T);
	while(T--){
		scanf("%s",inp);
		int L=strlen(inp);

		if(L==1){
			printf("1\n");
			continue;
		}

		MEM(cst,0);

		FOR(fl,0,L)
			cst[fl][fl]=1;

		EFOR(len,2,L)
			EFOR(fr,0,L-len){
				cst[fr][fr+len-1]=999999;
				EFOR(brk,fr+1,fr+len-1){
					int ln1=0,ln2=0;

					FOR(in,fr,brk)		fir[ln1++]=inp[in];
					EFOR(in,brk,fr+len-1)	sec[ln2++]=inp[in];
					fir[ln1]=0,sec[ln2]=0;

					if(strcmp(fir,sec)==0)
						cst[fr][fr+len-1]=min(cst[fr][fr+len-1],cst[fr][brk-1]);
					else
						cst[fr][fr+len-1]=min(cst[fr][fr+len-1],cst[fr][brk-1]+cst[brk][fr+len-1]);
				}
			}
		printf("%d\n",cst[0][L-1]);
	}

//	fclose(stdin);
	return 0;
}
