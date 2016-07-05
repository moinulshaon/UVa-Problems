#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int num[20];

vector<int> sol[500];

int totalSolution;
int sum,n;

void func(vector<int> serial,int ind,int s){

    if (s>sum || ind >=n)return ;
    printf("%d\t",s);
    for (int j=0;j<serial.size();++j)
        printf("+%d",serial[j]);
    printf("\n");
    if (s==sum){
        sol[totalSolution++]=serial;
        return ;
    }

    func( serial, ind+1, s);
    serial.push_back(num[ind]);
    func( serial, ind+1, s+num[ind]);
}


int main(){

    while(true){
        scanf("%d %d",&sum,&n);
        if (!sum && !n)return 0;

        for (int i=0;i<n;++i)
            scanf("%d",&num[i]);
        printf("Sums of %d:\n",sum);
        totalSolution=0;
        vector<int> tmp;
        func(tmp,0,0);

        if (totalSolution){
            for (int i=0;i<totalSolution;++i){
                printf("%d",sol[i][0]);
                for (int j=1;j<sol[i].size();++j)
                    printf("+%d",sol[i][j]);
                printf("\n");
            }
        }
        else
            printf("NONE\n");
    }

}
