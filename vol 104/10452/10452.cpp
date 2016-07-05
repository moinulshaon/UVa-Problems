#include <cstdio>

using namespace std;

int row,col;
char mat[10][10];
char seq[]="IEHOVA#";

void recursion(int a,int b,int ind)
{
    if (a-1>=0 && mat[a-1][b]== seq[ind] )
    {
        printf(" forth");
        if (ind!=6)
            recursion(a-1,b,ind+1);
    }
    else if (b+1<col && mat[a][b+1]== seq[ind] )
    {
        printf(" right");
        if (ind!=6)
            recursion(a,b+1,ind+1);
    }
    else if (b-1>=0 && mat[a][b-1]== seq[ind] )
    {
        printf(" left");
        if (ind!=6)
            recursion(a,b+1,ind+1);
    }
}


int main()
{
    int kase,x,y;

    scanf("%d",&kase);

    while (kase--)
    {
        scanf("%d %d",&row,&col);
        for (int i=0;i<row;++i)
            scanf("%s",mat[i]);
        for (int i=0;i<row;++i)
            for (int j=0;j<col;++j)
                if ( mat[i][j]=='@' )
                {
                    x=i;
                    y=j;
                    i=j=15;
                }

        if (x-1>=0 && mat[x-1][y]== 'I' )
        {
            printf(" forth");
            recursion(a-1,b,ind+1);
        }
        else if (b+1<col && mat[a][b+1]== seq[ind] )
        {
            printf(" right");
            if (ind!=6)
                recursion(a,b+1,ind+1);
        }
        else if (b-1>=0 && mat[a][b-1]== seq[ind] )
        {
            printf(" left");
            if (ind!=6)
                recursion(a,b+1,ind+1);
        }

    }

}
