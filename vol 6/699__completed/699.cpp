#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct node
{
    int val;
    node *left,*right;
};
int arr[200];
vector <int> result;
void inputfuncright(node *parent);

void inputfuncleft(node *parent)
{
    int v;
    scanf("%d",&v);
    if (v<0)
    {
        parent->left=NULL;
        return ;
    }

    node *tmp=new node;

    tmp->val=v;
    parent->left=tmp;

    inputfuncleft(tmp);
    inputfuncright(tmp);
}
void inputfuncright(node *parent)
{
    int v;
    scanf("%d",&v);
    if (v<0)
    {
        (*parent).right=NULL;
        return ;
    }

    node *tmp=new node;

    tmp->val=v;
    parent->right=tmp;

    inputfuncleft(tmp);
    inputfuncright(tmp);
}


void calc(node *tmp,int n)
{
    arr[n]+=tmp->val;
    if (tmp->left!=NULL)
        calc(tmp->left,n-1);
    if (tmp->right!=NULL)
        calc(tmp->right,n+1);
}

int main()
{
    freopen("in.txt","r",stdin);

    node root;
    int line=1;
    while (true)
    {
        scanf("%d",&root.val);
        if (root.val<0)return 0;

        printf("Case %d:\n",line++);
        inputfuncleft(&root);
        inputfuncright(&root);


        for (int i=0;i<200;++i)
            arr[i]=0;
        result.clear();
        calc(&root,100);

        bool on=false;
        for (int i=0;i<200;++i)
        {
            if (on || arr[i] )
            {
                result.push_back(arr[i]);
                on=true;
            }
        }
        on=true;
        for (int i=result.size()-1;i>=0 && on;--i)
        {
            if (result[i])
                on=false;
            else
                result.pop_back();
        }
        if (result.size()==0)
            result.push_back(0);
        printf("%d",result[0]);
        for (int i=1;i<result.size();++i)
            printf(" %d",result[i]);
        printf("\n\n");
    }
}
