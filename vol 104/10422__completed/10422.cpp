#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int mover[8]={1,2,2,1,-1,-2,-2,-1};
int movec[8]={2,1,-1,-2,-2,-1,1,2};


struct config
{
    int row,col,step;
    char board[5][6];

    void assaign(int a,int b,int c,char temp[5][6])
    {
        row=a;
        col=b;
        step=c;
        for (int i=0;i<5;++i)
            for (int j=0;j<6;++j)
                board[i][j]=temp[i][j];
    }
};



string standard="111110111100 110000100000";

map <string,bool> checked;

int compare (config a)
{
    string temp;
    for (int i=0;i<5;++i)
        temp.append(a.board[i]);
    if (checked[temp]==true)
        return -1;
    if (temp==standard) return 1;
    checked[temp]=true;
    return 0;
}



int main()
{
    int test;

    char input[5][6];

    freopen("input.txt","r",stdin);

    scanf("%d",&test);
    getchar();

    while (test--)
    {
        checked.clear();
        config start;

        for (int i=0;i<5;++i)
            gets(input[i]);

        for (int i=0;i<5;++i)
            for (int j=0;j<6;++j)
            {

                if (input[i][j]==' ')
                    start.assaign(i,j,0,input);

            }

        if (compare(start)==1)
        {
            printf("Solvable in 0 move(s).\n");
            continue;
        }

        queue <config> q;

        q.push(start);

        bool flag=true;
        while (!q.empty() && flag)
        {
            config temp=q.front();
            q.pop();

            for (int i=0;i<8 && flag;++i)
            {
                int trow=temp.row+mover[i],tcol=temp.col+movec[i];

                if (trow<0 || trow >4 || tcol<0 || tcol >4)
                    continue;

                config tmp;

                char tempboard[5][6];

                for (int j=0;j<5;++j)
                    for (int k=0;k<6;++k)
                        tempboard[j][k]=temp.board[j][k];


                tempboard[temp.row][temp.col]=temp.board[trow][tcol];
                tempboard[trow][tcol]=' ';

                tmp.assaign(trow,tcol,temp.step+1,tempboard);

                if (tmp.step>10)
                {
                    flag=false;
                    printf("Unsolvable in less than 11 move(s).\n");
                    break;
                }
                int judge=compare(tmp);

                if (judge==1)
                {
                    printf("Solvable in %d move(s).\n",tmp.step);
                    flag=false;
                }
                else if (judge==0)
                    q.push(tmp);
            }
        }
    }
    return 0;

}
