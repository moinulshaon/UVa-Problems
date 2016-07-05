#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

bool vis[10000];

int BFS(int s,int f){

    queue<int> q;
    queue<int> qcnt;
    int tmp,a,b,tt;
    char arr[6],aa[6];
    if ( !vis[s] )q.push(s);
    qcnt.push(0);
    vis[s]=true;
    int rr= -1;

    while ( !q.empty() ){
        tmp=q.front();
        q.pop();
        a=qcnt.front();
        qcnt.pop();

        if ( tmp==f ){
            rr=a;
            break;
        }
        sprintf(arr,"%d",tmp+10000);
        //printf("%d %s %c\n",tmp+10000,arr,arr[0]);
        for (int i=1;i<=4;++i){
            memcpy(aa,arr,sizeof(aa));
            aa[i]= ( ( arr[i]-'0' )+1 )%10+'0';

            tt=atoi(aa)-10000;
            //printf("%d %d\n",tmp,tt);
            if ( !vis[tt] ){
                q.push(tt);
                qcnt.push(a+1);
                vis[tt]=true;
            }
        }
        for (int i=1;i<=4;++i){
            memcpy(aa,arr,sizeof(aa));
            aa[i]= ( ( arr[i]-'0' )-1+10 )%10+'0';
            tt=atoi(aa)-10000;
            //printf("%d %d\n",tmp,tt);
            if ( !vis[tt] ){
                q.push(tt);
                qcnt.push(a+1);
                vis[tt]=true;
            }
        }
    }
    return rr;

}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int tmp,kase,ini,final,a,b;
    scanf("%d",&kase);

    while (kase--){
        ini=0;
        for (int i=0;i<4;++i){
            scanf("%d",&tmp);
            ini+= tmp*int ( pow(10,3-i) +1e-6);
        }
        final=0;
        for (int i=0;i<4;++i){
            scanf("%d",&tmp);
            final+= tmp*int ( pow(10,3-i) +1e-6);
        }
        memset(vis,false,sizeof(vis));
        scanf("%d",&a);
        while (a--){
            b=0;
            for (int i=0;i<4;++i){
                scanf("%d",&tmp);
                b+= tmp*int ( pow(10,3-i) +1e-6);
            }
            vis[b]=true;
        }
        //printf("%d %d\n",ini,final);
        printf("%d\n",BFS(ini,final));
    }
}
