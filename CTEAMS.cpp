#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long
#define PII pair<int,int>

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
	int N;
	set< PII >yng,old;
	set< PII >::iterator it;
	LL Y=0,O=0;

	int rt,age;

	Input(N);
	EFOR(i,1,N){
		Input(age),Input(rt);

		if(i&1){
			it=old.begin();

			if(it==old.end() || (*it).first>age){
				yng.insert( PII(age,rt) );
				Y+=rt;
			} else {
				yng.insert(*it);
				Y+=((*it).second);
				O+=(rt-(*it).second);
				old.erase(it);
				old.insert( PII(age,rt) );
			}

		} else {
			it=yng.end();
			it--;

			if((*it).first<age){
				old.insert( PII(age,rt) );
				O+=rt;
			} else {
				old.insert(*it);
				O+=((*it).second);
				Y+=(rt-(*it).second);
				yng.erase(it);
				yng.insert( PII(age,rt) );
			}

		}
		printf("%lld\n",abs(Y-O));
	}

	return 0;
}
