#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	vector< VI >age(10,VI(2));

	char ans[505];
	int anslen;

	while(T--){
		anslen=0;

		FOR(inp,0,10){
			scanf("%d",&age[inp][0]);
			age[inp][1]=inp;
		}
		SORT(age);

		if(age[0][1]==0){

			if(age[1][0]==age[0][0]){
				EFOR(fill,0,age[1][0])
					ans[anslen++]='0'+age[1][1];
			} else {
				ans[anslen++]='1';
				EFOR(fill,0,age[0][0])
					ans[anslen++]='0';
			}

			ans[anslen]=0;
			printf("%s\n",ans);
		} else {
			EFOR(fill,0,age[0][0])
				ans[anslen++]=48+age[0][1];

			ans[anslen]=0;
			printf("%s\n",ans);
		}
	}

//	fclose(stdin);
	return 0;
}
