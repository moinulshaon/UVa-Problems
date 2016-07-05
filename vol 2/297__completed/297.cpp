#include <cstdio>
#include <cstring>
#include <iostream>
#define sz 1500
#define WHITE 1
#define BLACK 2

using namespace std;

int tree1[sz];
int tree2[sz];
int val[sz];

void takeTree1(int nodeNumber){
    char c;
    cin>>c;
    if (c=='p'){
        for (int i=1;i<=4;++i)
            takeTree1(4*nodeNumber+i);
    }
    else if (c=='f')
        tree1[nodeNumber]=BLACK;
}
void takeTree2(int nodeNumber){
    char c;
    cin>>c;
    if (c=='p'){
        for (int i=1;i<=4;++i)
            takeTree2(4*nodeNumber+i);
    }
    else if (c=='f')
        tree2[nodeNumber]=BLACK;
}

void del(int n){
    if (n>=sz)return ;
    tree1[n]=tree2[n]=WHITE;
    del(4*n+1);
    del(4*n+2);
    del(4*n+3);
    del(4*n+4);

}

int main(){

    //freopen("in.txt","r",stdin);
    del(0);
    int kase,len;
    cin>>kase;

    val[0]=1024;
    for (int i=1;i<sz;++i){
        val[i]=val[(i-1)/4]/4;
        //printf("%d %d\n",i,val[i]);
        //getchar();
    }


    while (kase--){

        memset(tree1,WHITE,sizeof(tree1));
        takeTree1(0);
        memset(tree2,WHITE,sizeof(tree2));
        takeTree2(0);



        int cnt=0;
        for (int i=0;i<sz;++i)
            if (tree1[i]==BLACK || tree2[i]==BLACK){
                cnt+=val[i];
                del(i);
            }
        printf("There are %d black pixels.\n",cnt);
    }
    return 0;
}

