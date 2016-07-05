#include <cstdio>
#include <cstring>
#define TOTAL 26

using namespace std;

char line[100];
int parent[TOTAL];
int p[TOTAL];
bool pos[TOTAL];

int find1(int x){
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find1(parent[x]);
}

int find2(int x){
    return p[x]<0?x:(p[x]=find2(p[x]));
}


int main(){
    freopen("in.txt","r",stdin);

    int kase,tx,ty;
    scanf("%d",&kase);
    getchar();
    while (kase--){

        for (int i=0;i<TOTAL;++i)
            parent[i]=i;
        memset(p,-1,sizeof(p));

        while (true){
            gets(line);
            if (strlen(line)==5 && line[0]!='*'){
                tx=find1(line[1]-'A');
                ty=find1(line[3]-'A');

                if (tx!=ty){
                    parent[ty]=parent[tx];
                }

                tx=find2(line[1]-'A');
                ty=find2(line[3]-'A');
                if(tx!=ty){
                    p[tx]+=p[ty];
                    p[ty]=tx;
                }
            }
            else
                break;
        }
        memset(pos,false,sizeof(pos));
        gets(line);
        int len=strlen(line);
        for (int i=0;i<len;++i){
            if (line[i]>='A' && line[i]<='Z')
                pos[ line[i]-'A' ]=true;
        }


        int disjoint=0;
        for (int i=0;i<TOTAL;++i)
        {
            if (pos[i] && find1(i)==i)
                ++disjoint;
        }
        int acorn=0;
        for (int i=0;i<TOTAL;++i)
        {
            if (pos[i] && p[i]==-1)
                ++acorn;
        }

        printf("There are %d tree(s) and %d acorn(s).\n",disjoint-acorn,acorn);
    }
    return 0;
}
