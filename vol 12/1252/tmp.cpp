#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int M,N;
char s[135][15];
map < pair< vector<int>,int > ,int> MAP;

int flere(vector <int> list,int level,int used){
    int i,j,k=M;
    if(MAP.find(make_pair(list,used))!=MAP.end())
        return MAP[make_pair(list,used)];
    if(list.size()==1)
        return level;
    for(i=0;i<M;i++){
        if(used & (1<<i))
            continue;
        vector <int> a,b;
        for(j=0;j<list.size();j++){
            if(s[list[j]][i]=='0')
                a.push_back(list[j]);
            else
                b.push_back(list[j]);
        }
        if(a.size()==0 || b.size()==0)
            continue;
        k = min(k,max(flere(a,level+1,used|(1<<i)),flere(b,level+1,used|(1<<i))));
    }
    return MAP[make_pair(list,used)] = k;
}

main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,m,i,j;
    while(~scanf(" %d %d",&M,&N) && (M+N)){
        gets(s[0]);
        for(n=0;n<N;n++)
            gets(s[n]);
        vector <int> list;
        MAP.clear();
        for(n=0;n<N;n++)
            list.push_back(n);
        printf("%d\n",flere(list,0,0));
    }

}
