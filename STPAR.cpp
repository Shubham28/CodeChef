#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
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
	int N;
	Input(N);

	while(N!=0){
		bool psb=1;
		stack<int>side;

		int inp=1,val=1;
		for(;inp<=N;inp++){
			int tmp;
			Input(tmp);

			if(tmp!=val){
				if(side.empty() || tmp<side.top())
					side.push(tmp);
				else if(side.top()==inp){
					side.pop();
					val++;
				} else
					psb=0;
			} else
				val++;

			while(!side.empty() && val==side.top()){
				side.pop();
				++val;
			}
		}
		for(;inp<=N;inp++){
			int tmp;
			Input(tmp);
		}

		if(psb)
			printf("yes\n");
		else
			printf("no\n");

		Input(N);
	}

	return 0;
}
