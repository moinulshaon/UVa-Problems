#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


struct mathv{
    mathv(){x=0;y=0;}
    mathv(double a,double b){x=a;y=b;}
    double x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }
}point[1100],save;
int vv;
int lim;
int cnt;

double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

int bfs(){

    bool vis[1100]={false};

    queue<pint> q;
    q.push( make_pair(0,0) );
    vis[0]=true;

    while ( !q.empty() ){

        pint f=q.front();q.pop();
        //cout<<f.first<<endl;
        if ( distance2DPointAndPoint( point[f.first],point[cnt] )< double(lim)*vv*60+1e-8 ){
            return f.second;
        }

        for (int i=1;i<cnt;++i){
            if (!vis[i] && distance2DPointAndPoint( point[f.first],point[i] )< double(lim)*vv*60+1e-8 ){
                q.push( make_pair( i,f.second+1 ) );
                vis[ i ]=true;
            }
        }

    }
    return -1;
}

int main(){

    FRO
    //ios_base::sync_with_stdio(false);

    string str;
    while ( true ){
        cin>>vv>>lim;

        if ( vv==0 && lim == 0 )break;

        cin>>point[0].x>>point[0].y;
        cin>>save.x>>save.y;

        cnt=1;
        getline(cin,str);
        while ( getline(cin,str) && str!="" ){
            istringstream ss(str);
            ss>>point[cnt].x>>point[cnt].y;
            cnt++;
            //cout<<str<<endl;
        }

        point[cnt]=save;

        int ans=bfs();

        if ( ans== -1 ){
            cout<<"No.\n";
        }else{
            cout<<"Yes, visiting "<<ans<<" other holes.\n";
        }

    }


    return 0;
}
