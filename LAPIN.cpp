#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	int T;
	cin>>T;

	char S[1001];
	int L;
	int fir[30],sec[30];

	while(T--){
		scanf("%s",S);
		L=strlen(S);

		MEM(fir,0);		MEM(sec,0);

		FOR(i,0,L/2){
			fir[S[i]-'a']++;
			sec[S[L-1-i]-'a']++;
		}

		bool same=1;
		FOR(i,0,26)
			if(fir[i]!=sec[i]){
				same=0;
				break;
			}

		printf("%s\n",(same)?"YES":"NO");
	}

	return 0;
}
