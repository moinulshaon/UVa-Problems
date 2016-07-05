#include <iostream>
#include <cstdio>
#include <cmath>
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
bool intersectTwoSegment(mathl& s1,mathl& s2){
    return intersectTwoSegment(s1.p1, s1.p2, s2.p1, s2.p2);
}

int main(){

    freopen("in.txt","r",stdin);

    int kase;

    scanf("%d",&kase);
    //int k=1;
    while (kase--){

        mathl givenSegment;
        mathv pointUpperLeft,pointLowerRight;

        scanf("%d %d %d %d",&givenSegment.p1.x,&givenSegment.p1.y,&givenSegment.p2.x,&givenSegment.p2.y);

        scanf("%d %d %d %d",&pointUpperLeft.x,&pointUpperLeft.y,&pointLowerRight.x,&pointLowerRight.y);

        mathl up;
        up.p1=pointUpperLeft;
        up.p2=mathv( pointLowerRight.x,pointUpperLeft.y );

        mathl right;
        right.p1=mathv( pointLowerRight.x,pointUpperLeft.y );
        right.p2=pointLowerRight;

        mathl bottom;
        bottom.p1=pointLowerRight;
        bottom.p2=mathv( pointUpperLeft.x,pointLowerRight.y );

        mathl left;
        left.p1=mathv( pointUpperLeft.x,pointLowerRight.y );
        left.p2=pointUpperLeft;

        //cout<<up.p1.x<<' '<<up.p1.y<<' '<<up.p2.x<<' '<<up.p2.y<<endl;
        //cout<<right.p1.x<<' '<<right.p1.y<<' '<<right.p2.x<<' '<<right.p2.y<<endl;
        //cout<<bottom.p1.x<<' '<<bottom.p1.y<<' '<<bottom.p2.x<<' '<<bottom.p2.y<<endl;
        //cout<<left.p1.x<<' '<<left.p1.y<<' '<<left.p2.x<<' '<<left.p2.y<<endl;
        //cout<<k++<<' ';

        if (intersectTwoSegment( up,givenSegment )||
            intersectTwoSegment( right,givenSegment )||
            intersectTwoSegment( bottom,givenSegment )||
            intersectTwoSegment( left,givenSegment )){

            printf("T\n");

        }else {
           if (
               (givenSegment.p1.x < right.p1.x
                && givenSegment.p1.x> left.p1.x
                && givenSegment.p1.y < up.p1.y
                && givenSegment.p1.y> bottom.p1.y)||
               (givenSegment.p1.x < right.p1.x
                && givenSegment.p1.x> left.p1.x
                && givenSegment.p1.y > up.p1.y
                && givenSegment.p1.y< bottom.p1.y)||
               (givenSegment.p1.x < left.p1.x
                && givenSegment.p1.x> right.p1.x
                && givenSegment.p1.y < up.p1.y
                && givenSegment.p1.y> bottom.p1.y)||
               (givenSegment.p1.x < left.p1.x
                && givenSegment.p1.x> right.p1.x
                && givenSegment.p1.y > up.p1.y
                && givenSegment.p1.y< bottom.p1.y)

            )
                printf("T\n");
            else
                printf("F\n");
        }


    }
    return 0;

}
