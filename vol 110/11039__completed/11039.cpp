#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int &a,const int b){
    return a>b;
}

int main(){



    int n,kase,tmp;
    scanf("%d",&kase);

    while (kase--){
        vector<int> blue,red;

        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d",&tmp);
            if ( tmp>0 ){
                blue.push_back( tmp );
            }else{
                red.push_back( -tmp );
            }
        }

        sort(red.begin(),red.end(),cmp);
        sort(blue.begin(),blue.end(),cmp);


        if ( blue.size()+red.size()==0 ){
            printf("0\n");
        }
        else if ( blue.size()==0 || red.size()==0 ){
            printf("1\n");
        }else if ( blue[0]>red[0] ){
            int ans=1;
            int num=blue[0];
            int bluePointer=1,redPointer=0;
            bool takeBlue=false;
            for (int i=1;i<n;++i){
                if ( takeBlue ){
                    if (bluePointer<blue.size() && blue[bluePointer]<num ){
                        ++ans;
                        takeBlue=false;
                        num=blue[bluePointer];
                    }
                    ++bluePointer;
                }
                else{
                    if (redPointer<red.size() && red[redPointer]<num ){
                        ++ans;
                        takeBlue=true;
                        num=red[redPointer];
                    }
                    ++redPointer;
                }
            }
            printf("%d\n",ans);
        }else{
            int ans=1;
            int num=red[0];
            int bluePointer=0,redPointer=1;
            bool takeBlue=true;
            for (int i=1;i<n;++i){
                if ( takeBlue ){
                    if (bluePointer<blue.size() && blue[bluePointer]<num ){
                        ++ans;
                        takeBlue=false;
                        num=blue[bluePointer];
                    }
                    ++bluePointer;
                }
                else{
                    if (redPointer<red.size() && red[redPointer]<num ){
                        ++ans;
                        takeBlue=true;
                        num=red[redPointer];
                    }
                    ++redPointer;
                }
            }
            printf("%d\n",ans);
        }

    }
    return 0;
}
