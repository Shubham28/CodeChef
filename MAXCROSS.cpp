#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

#define FOR(A,B,C) for(short A=B;A<C;A++)
#define EFOR(A,B,C) for(short A=B;A<=C;A++)
#define RFOR(A,B,C) for(short A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);

using namespace std;

short N;
char inp[1001][1001];
short ans[1001][1001];

inline void Input()
{
	char ch;
	N=0;

	ch=getchar();
	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	while(!(ch=='.' || ch=='X'))
		ch=getchar();

	FOR(row,0,N){
		inp[row][0]=ch;
		FOR(col,1,N){
			ch=getchar();
			inp[row][col]=ch;
		}
		inp[row][N]=0;
		ch=getchar();

		while(!(ch=='.' || ch=='X' || ch==EOF))
			ch=getchar();
	}
	return;
}

inline void secDiag()
{
	short strt,end;
	FOR(col,0,N){
		strt=-1,end=-1;
		EFOR(diag,0,col){
			if(inp[diag][col-diag]=='X'){
				if(strt==-1)
					strt=diag,end=diag;
				else
					++end;
			} else
				if(end!=-1){
					EFOR(filld,strt,end)
						ans[filld][col-filld]=max(ans[filld][col-filld],short(end-strt+1));
					strt=-1,end=-1;
				}
		}
		if(end!=-1)
			EFOR(filld,strt,end)
				ans[filld][col-filld]=max(ans[filld][col-filld],short(end-strt+1));
	}

	FOR(col,1,N){
		strt=-1,end=-1;
		FOR(diag,col,N){
			if(inp[N+col-diag-1][diag]=='X'){
				if(strt==-1)
					strt=diag,end=diag;
				else
					++end;
			} else
				if(end!=-1){
					EFOR(filld,strt,end)
						ans[N+col-filld-1][filld]=max(ans[N+col-filld-1][filld],short(end-strt+1));
					strt=-1,end=-1;
				}
		}
		if(end!=-1)
			EFOR(filld,strt,end)
				ans[N+col-filld-1][filld]=max(ans[N+col-filld-1][filld],short(end-strt+1));
	}
	return;
}

inline void firDiag()
{
	short strt,end;
	FOR(col,0,N){
		strt=-1,end=-1;
		FOR(diag,0,N-col){
			if(inp[diag][col+diag]=='X'){
				if(strt==-1)
					strt=diag,end=diag;
				else
					++end;
			} else
				if(end!=-1){
					EFOR(filld,strt,end)
						ans[filld][col+filld]=max(ans[filld][col+filld],short(end-strt+1));
					strt=-1,end=-1;
				}
		}
		if(end!=-1)
			EFOR(filld,strt,end)
				ans[filld][col+filld]=max(ans[filld][col+filld],short(end-strt+1));
	}

	FOR(row,1,N){
		strt=-1,end=-1;
		FOR(diag,0,N-row){
			if(inp[row+diag][diag]=='X'){
				if(strt==-1)
					strt=diag,end=diag;
				else
					++end;
			} else
				if(end!=-1){
					EFOR(filld,strt,end)
						ans[row+filld][filld]=max(ans[row+filld][filld],short(end-strt+1));
					strt=-1,end=-1;
				}
		}
		if(end!=-1)
			EFOR(filld,strt,end)
				ans[row+filld][filld]=max(ans[row+filld][filld],short(end-strt+1));
	}
	return;
}

inline void vert()
{
	short strt,end;
	FOR(col,0,N){
		strt=-1,end=-1;
		FOR(row,0,N){
			if(inp[row][col]=='X'){
				if(strt==-1)
					strt=row,end=row;
				else
					++end;
			} else
				if(end!=-1){
					EFOR(fillr,strt,end)
						ans[fillr][col]=max(ans[fillr][col],short(end-strt+1));
					strt=-1,end=-1;
				}
		}
		if(end!=-1)
			EFOR(fillr,strt,end)
				ans[fillr][col]=max(ans[fillr][col],short(end-strt+1));
	}
	return;
}

inline void horiz()
{
	short strt,end;
	FOR(row,0,N){
		strt=-1,end=-1;
		FOR(col,0,N){
			if(inp[row][col]=='X'){
				if(strt==-1)
					strt=col,end=col;
				else
					++end;
			} else
				if(end!=-1){
					EFOR(fillc,strt,end)
						ans[row][fillc]=(end-strt+1);
					strt=-1,end=-1;
				}
		}
		if(end!=-1)
			EFOR(fillc,strt,end)
				ans[row][fillc]=(end-strt+1);
	}
	return;
}

int main()
{
	Input();
	memset(ans,0,sizeof(ans));

	horiz();
	vert();
	firDiag();
	secDiag();
	FOR(row,0,N){
		FOR(col,0,N)
			printf("%hd ",ans[row][col]);
		printf("\n");
	}
	return 0;
}
