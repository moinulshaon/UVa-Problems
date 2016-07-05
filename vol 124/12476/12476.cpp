#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

#define SIZE 20100

using namespace std;


vector<int> out[SIZE];



struct tt{
    int city,len;
    bool must;
    bool operator <(const tt&b)const {
        return len>b.len;
    }
}tmp,u;


char str[2*SIZE];
int len;

int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,a,b;
        scanf("%d",&n);

        for (int i=0;i<=n;++i){
            out[i].clear();
        }
        for (int i=1;i<=n;++i){
            scanf("%d %d",&a,&b);
            out[i].push_back(a);
            out[i].push_back(b);
        }


        scanf("%s",str);
        len=strlen(str);

        priority_queue<tt> pq;

        tmp.city= 1;
        tmp.len= -1;
        tmp.must=false;

        //memset(vis,false,sizeof(vis));

        pq.push(tmp);
        bool pos=false;
        while( !pq.empty() ){
            u=pq.top();pq.pop();
            //if ( vis[ u.city ][u.len][u.must] )continue;

            //printf("%d %d %d\n",u.city,u.len,u.must);
            //getchar();
            if ( u.len==len-1 ){
                pos=true;
                break;
            }

            //vis[ u.city ][ u.len ][ u.must ]=true;

            int mm=u.len+1;
            if ( str[mm]=='L' ){
                if ( out[ u.city ][0]!=-1 ){
                    tmp.city=out[ u.city ][0];
                    tmp.len=mm;
                    tmp.must=false;
                    pq.push(tmp);
                }
                if ( !u.must ){
                    tmp.city=u.city;
                    tmp.len=mm;
                    tmp.must=true;
                    pq.push(tmp);
                }
            }else{
                if ( out[ u.city ][1]!=-1 ){
                    tmp.city=out[ u.city ][1];
                    tmp.len=mm;
                    tmp.must=false;
                    pq.push(tmp);
                }
                if ( !u.must ){
                    tmp.city=u.city;
                    tmp.len=mm;
                    tmp.must=true;
                    pq.push(tmp);
                }
            }
        }
        if ( pos )printf("Case %d: Yes\n",kk);
        else printf("Case %d: No\n",kk);
    }
    return 0;
}
