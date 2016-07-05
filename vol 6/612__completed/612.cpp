#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

map <char,int> ind;
int row,col;
struct node
{
    char line[55];
    int val;
}arr[105];

void func(int n)
{
    int cnt[4]={0},temp=0,tt;
    for (int i=col-1;i>=0;--i)
    {
        ++cnt[ind[arr[n].line[i]]];
        tt=ind[arr[n].line[i]];
        for (int j=tt+1;j<4;++j)
            temp+=cnt[j];
    }
    arr[n].val=temp;
}

bool cmp(node a,node b)
{
    if (a.val<b.val)
        return true;
    return false;
}


int main()
{

    freopen("input.txt","r",stdin);

    int test;
    scanf("%d",&test);

    ind['T']=0;
    ind['G']=1;
    ind['C']=2;
    ind['A']=3;

    while (test--)
    {
        scanf("%d %d",&col,&row);
        for (int i=0;i<row;++i)
            scanf("%s",arr[i].line);
        for (int i=0;i<row;++i)
            func(i);
        stable_sort(arr,arr+row,cmp);
        for (int i=0;i<row;++i)
            printf("%s\n",arr[i].line);

        if (test)printf("\n");

    }
    return 0;

}
