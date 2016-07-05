#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

struct mathv{
    mathv(){x=0;y=0;}
    mathv(int a,int b){x=a;y=b;}
    int x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }
    bool operator == (mathv & p){
        return x==p.x && y==p.y;
    }

};

int dot2D(mathv& v1, mathv& v2){
    return v1.x * v2.x + v1.y * v2.y;
}
int dot2D(mathv& o, mathv& a, mathv& b){
    return (a.x-o.x) * (b.x-o.x) - (a.y-o.y) * (b.y-o.y);
}
int cross2D(mathv& v1, mathv& v2){
    return v1.x * v2.y - v1.y * v2.x;
}
int cross2D(mathv& o, mathv& a, mathv& b){
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

double length2D(mathv& v){
    return sqrt(v.x * v.x + v.y * v.y);
}
double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}


struct mathl{
    mathv p1,p2;
};
double distance2DPointAndLine(mathv& p, mathl& l){
    mathv v1 = p - l.p1, v2 = l.p2 - l.p1;
    return fabs(cross2D(v1, v2)) / length2D(v2);
}
double distance2DPointAndSegment(mathv& p, mathl& s)
{
    mathv p1p = p - s.p1, p1p2 = s.p2 - s.p1;
    mathv p2p = p - s.p2, p2p1 = s.p1 - s.p2;


    if (dot2D(p1p, p1p2) > 0 && dot2D(p2p, p2p1) > 0)
        return distance2DPointAndLine(p, s);
    else
        return min( distance2DPointAndPoint(p, s.p1),distance2DPointAndPoint(p, s.p2) );
}


bool intersect2DSegmentAndPoint(mathl& s, mathv& p){
    return cross2D(s.p1, s.p2, p) == 0 && dot2D(p, s.p1, s.p2) <= 0;
}

bool isColinearThreePoint(mathv& p1, mathv& p2, mathv& p){
    return p.x >= min(p1.x, p2.x)
        && p.x <= max(p1.x, p2.x)
        && p.y >= min(p1.y, p2.y)
        && p.y <= max(p1.y, p2.y);
}
bool isColinearFourPoint(mathv& a1, mathv& a2, mathv& b1, mathv& b2)
{
    return isColinearThreePoint(a1, a2, b1)
        || isColinearThreePoint(a1, a2, b2)
        || isColinearThreePoint(b1, b2, a1)
        || isColinearThreePoint(b1, b2, a2);
}
bool intersectTwoSegment(mathv& a1, mathv& a2, mathv& b1, mathv& b2)
{
    double c1 = cross2D(a1, a2, b1);
    double c2 = cross2D(a1, a2, b2);
    double c3 = cross2D(b1, b2, a1);
    double c4 = cross2D(b1, b2, a2);

    if (c1 * c2 < 0 && c3 * c4 < 0) return true;
    if (c1 == 0 && isColinearThreePoint(a1, a2, b1)) return true;
    if (c2 == 0 && isColinearThreePoint(a1, a2, b2)) return true;
    if (c3 == 0 && isColinearThreePoint(b1, b2, a1)) return true;
    if (c4 == 0 && isColinearThreePoint(b1, b2, a2)) return true;
    return false;
}

int main(){

    freopen("in.txt","r",stdin);

    int kase,total,a,b;
    mathl segments[1000];
    scanf("%d",&kase);

    while (kase--){


        scanf("%d",&total);
        for (int i=0;i<total;++i){
            scanf("%d %d %d %d",&segments[i].p1.x,&segments[i].p1.y,&segments[i].p2.x,&segments[i].p2.y);
        }
        int result=total;
        for (int i=0;i<total; ++i){
            for (int j=i+1; j<total ;++j){

                if ( intersectTwoSegment(segments[i].p1, segments[i].p2, segments[j].p1, segments[j].p2) ){

                    if (  (segments[i].p1==segments[j].p1) || (segments[i].p1==segments[j].p2)||
                        (segments[i].p2==segments[j].p1) || (segments[i].p2==segments[j].p2))
                        ++result;
                    else {
                        result+=2;
                    }
                    //cout<<"Segment "<<i<<' '<<j<<' '<<result<<endl;

                }


            }
        }

        printf("%d\n",result);
        if (kase)printf("\n");

    }
    return 0;

}
