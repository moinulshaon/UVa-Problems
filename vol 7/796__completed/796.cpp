#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 10100

vector<int> outarrow[SIZE];
int level[SIZE];
int low[SIZE];

struct briges{
    int start,end;
}tmp;

vector<briges> result;

void dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;

            dfs( y );

            low[x]=min( low[x],low[y] );

            if (  low[y]>level[x] ){
                tmp.start=x;
                tmp.end=y;
                if ( tmp.start>tmp.end )
                    swap( tmp.start,tmp.end );
                result.push_back(tmp);
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }

}

bool cmp( const briges&a,const briges&b ){
    if ( a.start!=b.start )
        return a.start<b.start;
    else
        return a.end<b.end;
}

int main(){
    freopen("in.txt","r",stdin);

    int kase,a,b,v,e;


    while (scanf("%d",&v)==1 ){




        for (int i=0;i<v;++i ){
            scanf("%d (%d)",&e,&a);
            while ( a-- ){
                scanf("%d",&b);
                outarrow[e].push_back(b);
                outarrow[b].push_back(e);
            }

        }


        memset( level,-1,sizeof(level));



        result.clear();
        for (int i=0;i<v;++i){
            if ( level[i]== -1 ){
                level[i]=0;
                dfs(i);
            }
        }

        sort( result.begin(),result.end(),cmp );

        printf("%d critical links\n",result.size());
        for (int i=0;i<result.size();++i){
            printf("%d - %d\n",result[i].start,result[i].end);
        }
        printf("\n");

        for (int i=0;i<v;++i){
            outarrow[i].clear();
        }
    }
    return 0;

}
