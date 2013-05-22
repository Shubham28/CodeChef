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
#define VI vector<int>
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
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
//	freopen("Input.txt","r",stdin);
	int T;
	Input(T);

	while(T--){
		int A,B,C;
		Input(A),Input(B),Input(C);

		VI dim(3);
		dim[0]=A,dim[1]=B,dim[2]=C;

		queue< VI >cub;
		cub.push(dim);

		LL ans=0;
		while(!cub.empty()){
			VI prs=cub.front();
			cub.pop();

			sort(ALL(prs));
			if(prs[0]==1){
				ans+=(LL)prs[0]*(LL)prs[1]*(LL)prs[2];
				continue;
			}

			int sm=1;
			for(;sm*2<=prs[0];sm<<=1);

			VI frm(3);
			LL prd=1;
			FOR(d,0,3){
				prd*=(LL)prs[d]/(LL)sm;
				frm[d]=((LL)prs[d]/(LL)sm)*(LL)sm;
			}
			ans+=prd;

			VI tmp(3);
			if(frm[0]==prs[0] && frm[1]==prs[1] && frm[2]==prs[2])
				continue;
			else if(frm[0]==prs[0] && frm[1]==prs[1] && frm[2]!=prs[2]){
				tmp[0]=frm[0],tmp[1]=frm[1],tmp[2]=prs[2]-frm[2];
				cub.push(tmp);
			} else if(frm[0]==prs[0] && frm[1]!=prs[1] && frm[2]==prs[2]){
				tmp[0]=frm[0],tmp[1]=prs[1]-frm[1],tmp[2]=frm[2];
				cub.push(tmp);
			} else if(frm[0]==prs[0] && frm[1]!=prs[1] && frm[2]!=prs[2]){
				tmp[0]=frm[0],tmp[1]=prs[1]-frm[1],tmp[2]=prs[2];
				cub.push(tmp);
				tmp[0]=frm[0],tmp[1]=frm[1],tmp[2]=prs[2]-frm[2];
				cub.push(tmp);
			} else if(frm[0]!=prs[0] && frm[1]==prs[1] && frm[2]==prs[2]){
				tmp[0]=prs[0]-frm[0],tmp[1]=frm[1],tmp[2]=frm[2];
				cub.push(tmp);
			} else if(frm[0]!=prs[0] && frm[1]==prs[1] && frm[2]!=prs[2]){
				tmp[0]=prs[0]-frm[0],tmp[1]=frm[1],tmp[2]=prs[2];
				cub.push(tmp);
				tmp[0]=frm[0],tmp[1]=frm[1],tmp[2]=prs[2]-frm[2];
				cub.push(tmp);
			} else if(frm[0]!=prs[0] && frm[2]==prs[2] && frm[1]!=prs[1]){
				tmp[0]=prs[0]-frm[0],tmp[2]=frm[2],tmp[1]=prs[1];
				cub.push(tmp);
				tmp[0]=frm[0],tmp[2]=frm[2],tmp[1]=prs[1]-frm[1];
				cub.push(tmp);
			} else {
				tmp[0]=prs[0],tmp[1]=prs[1],tmp[2]=prs[2]-frm[2];
				cub.push(tmp);
				tmp[0]=prs[0]-frm[0],tmp[1]=prs[1],tmp[2]=frm[2];
				cub.push(tmp);
				tmp[0]=frm[0],tmp[1]=prs[1]-frm[1],tmp[2]=frm[2];
				cub.push(tmp);
			}
		}
		printf("%lld\n",ans);
	}

//	fclose(stdin);
	return 0;
}
