#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define VL vector<long>
#define VLL vector<long long>
#define LL long long

using namespace std;

void CoinValue(long N,map<long,LL> &value)
{
	if(value.find(N/2)==value.end())
		CoinValue(N/2,value);

	if(value.find(N/3)==value.end())
		CoinValue(N/3,value);

	if(value.find(N/4)==value.end())
		CoinValue(N/4,value);

	LL ret=N;
	if(ret<value[N/2]+value[N/3]+value[N/4])
		ret=value[N/2]+value[N/3]+value[N/4];

	value[N]=ret;
	return;
}

int main()
{
	long N;

	while(scanf("%ld",&N)!=EOF){
		if(N<=4){
			printf("%ld\n",N);
			continue;
		}

		map<long,LL>value;
		value[0]=0,value[1]=1,value[2]=2,value[3]=3;
		CoinValue(N,value);
		printf("%lld\n",value[N]);
	}

	return 0;
}
