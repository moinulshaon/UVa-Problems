#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;
char map[110][110];
char input[110];
int dim,len;

bool uptodown(int r,int c)
{
    if (r+len<=dim)
    {
        for (int i=0;i<len;++i)
            if (map[r+i][c]!=input[i])
                return false;
        return true;
    }
    return false;
}

bool righttoleft(int r,int c)
{
    //printf("%d %d %d\n",c,r,c+1-len);
    if (c+1-len>=0)
    {
        for (int i=0;i<len;++i)
            if (map[r][c-i]!=input[i])
                return false;
        return true;
    }
    return false;
}



int main()
{
    int startr,startc,finishr,finishc;

    scanf("%d",&dim);
    getchar();

    while (1)
    {
        if (!dim) return 0;

        for (int i=0;i<dim;++i)
            gets(map[i]);



        while ( gets(input) && !(input[0]>='0' && input[0]<='9') )
        {
            len=strlen(input);
            for (int i=0;i<dim;++i)
            {
                for (int j=0;j<dim;++j)
                {
                    if (input[0]==map[i][j])
                    {
                        startr=i;
                        startc=j;

                        /*if (uptodown(i,j))
                        {
                            finishr=i;
                            finishc=j;
                            i=j=dim*2;
                            //printf("true\n");
                        }
                        else if (strncmp(input,&map[i][j],len)==0)
                        {
                            finishr=i;
                            finishc=j;
                            //printf("true %d %d\n",i,j);
                            i=j=dim*2;
                        }
                        else if (righttoleft(i,j))
                        {
                            finishr=i;
                            finishc=j;
                            printf("true %d %d\n",i,j);
                            i=j=dim*2;
                        }
                        else */if (diag1uptodown(i,j))
                        {
                            finishr=i;
                            finishc=j;
                            printf("true %d %d\n",i,j);
                            i=j=dim*2;
                        }


                    }
                }
            }

        }

        dim=atoi(input);



    }
}
