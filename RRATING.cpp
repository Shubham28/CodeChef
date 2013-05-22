#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

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
	multiset<int, greater<int> >top,ratng;
	multiset<int>::iterator it;

	int N;
	Input(N);

	int qr,rt;
	EFOR(a,1,N){
		Input(qr);

		it=top.end();
		if(qr==1){
			Input(rt);

			if(it==top.begin())
				ratng.insert(rt);
			else {
				it--;
				if((*it)>=rt)
					ratng.insert(rt);
				else {
					ratng.insert(*it);
					top.erase(it);
					top.insert(rt);
				}
			}

			if((SZ(top)+SZ(ratng))%3==0){
				it=ratng.begin();
				top.insert(*it);
				ratng.erase(it);
			}

		} else {
			if(it==top.begin())
				printf("No reviews yet\n");
			else {
				it--;
				printf("%d\n",(*it));
			}
		}
	}

	return 0;
}
