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
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	int T,L;
	char inp[2005];

	//	State: Position, Last used character in non-decreasing, non-increasing sequence
	int bst[2][30][30];

	scanf("%d",&T);
	while(T--){
		scanf("%s",inp);
		L=strlen(inp);

		MEM(bst,0);
		bst[0][1+inp[0]-'a'][27]=bst[0][0][1+inp[0]-'a']=1;

		int ans=1;
		FOR(pos,1,L){
			int now=pos&1,prev=(pos-1)&1;
			MEM(bst[now],0);
			//	Skip the position
			memcpy(bst[now],bst[prev],sizeof(bst[prev]));

			//	Use the character in non-decreasing sequence
			EFOR(j,0,27)
				EFOR(i,0,1+inp[pos]-'a'){
					bst[now][1+inp[pos]-'a'][j]=max((int)bst[now][1+inp[pos]-'a'][j],1+bst[prev][i][j]);
					ans=max(ans,(int)bst[now][1+inp[pos]-'a'][j]);
				}

			//	Use the character in non-increasing sequence
			EFOR(i,0,27)
				RFOR(j,27,1+inp[pos]-'a'){
					bst[now][i][1+inp[pos]-'a']=max((int)bst[now][i][1+inp[pos]-'a'],1+bst[prev][i][j]);
					ans=max(ans,(int)bst[now][i][1+inp[pos]-'a']);
				}
		}
		printf("%d\n",ans);
	}

	return 0;
}
