#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const double eps=1e-6;

struct point{
	double x,y;
	point(double x0=0,double y0=0){x=x0;y=y0;}
    double getdis(point p){
    	return double(sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)));
    }
    double xchen(point p){//this X P
        return x*p.y-p.x*y;
    }
    friend bool operator < (point a,point b){
		if(a.y!=b.y) return a.y<b.y;
		else return a.x<b.x;
	}
};

struct line{//line ax+by+c=0
	double a,b,c;
	line(double a0=0,double b0=0,double c0=0){a=a0;b=b0;c=c0;}
    void setline(point p1,point p2){
        a=p1.y-p2.y,b=p2.x-p1.x,c=p1.x*p2.y-p2.x*p1.y;
    }
    point getCrossPoint(line l1){//get the cross point of Line l1 and l2
        point tmp;
        tmp.x=(l1.b*c-b*l1.c)/(l1.a*b-l1.b*a);
        tmp.y=(l1.c*a-c*l1.a)/(l1.a*b-l1.b*a);
        return tmp;
    }
};

vector <point> p;

void ini(){
    p.clear();
    p.push_back(point(0,0));
    p.push_back(point(10,0));
    p.push_back(point(10,10));
    p.push_back(point(0,10));
}

line getLine(point p1,point p2){//get the Line that cross point p1 + p2/2
	line tmpLine;
	tmpLine.a=p2.x-p1.x;
	tmpLine.b=p2.y-p1.y;
	tmpLine.c=(p1.x*p1.x-p2.x*p2.x+p1.y*p1.y-p2.y*p2.y)/2.0;
	return tmpLine;
}

double xchen(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

bool cmp(point a,point b){
	if(fabs(xchen(p[0],a,b))<eps) return a.getdis(p[0])<b.getdis(p[0]);
	else return xchen(p[0],a,b)>0;
}

void deal(point s,point d,int flag){
    line l2=getLine(s,d);
    //cout<<"shoan "<<l2.a<<" "<<l2.b<<" "<<l2.c<<endl;
    vector <point> v;
    for(int i=0;i<p.size();i++){
        if(flag<0){
            if(p[i].getdis(s)<p[i].getdis(d)){
                v.push_back(p[i]);
            }
        }else{
            if(p[i].getdis(s)>p[i].getdis(d)){
                v.push_back(p[i]);
            }
        }
    }

    for (int i=0;i<v.size();++i){
        cout<<"b "<<v[i].x<<" "<<v[i].y<<endl;
    }cout<<endl;

    p.push_back(p[0]);
    for(int i=1;i<p.size();i++){
        line l1;
        l1.setline(p[i-1],p[i]);
        if( fabs(l1.a*l2.b-l1.b*l2.a)<eps ) continue;
        point tmp=l2.getCrossPoint(l1);
        //cout<<tmp.x<<" "<<tmp.y<<endl;
        if( fabs( fabs(tmp.x-p[i-1].x)+fabs(tmp.x-p[i].x)-fabs(p[i].x-p[i-1].x) ) > eps  ) continue;
        if( fabs( fabs(tmp.y-p[i-1].y)+fabs(tmp.y-p[i].y)-fabs(p[i].y-p[i-1].y) ) > eps  ) continue;
        v.push_back(tmp);
    }
/*
    for (int i=0;i<v.size();++i){
        cout<<"s "<<v[i].x<<" "<<v[i].y<<endl;
    }
*/
    p.clear();
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(p.size()>0 && ( fabs(p.back().x-v[i].x)<eps &&  fabs(p.back().y-v[i].y)<eps ) ) continue;
        p.push_back(v[i]);
    }
	if(p.size()>=1) sort(++p.begin(),p.end(),cmp);
}

double getarea(){
/*
    cout<<p.size()<<endl;
    for(int i=0;i<p.size();i++){
        cout<<"have "<<p[i].x<<" "<<p[i].y<<endl;
    }
*/
    double sum=0;
    for(int i=1;i<p.size()-1;i++){
        point p1=point(p[i].x-p[0].x,p[i].y-p[0].y);
        point p2=point(p[i+1].x-p[0].x,p[i+1].y-p[0].y);
        sum+=fabs(p2.xchen(p1))/2.0;
    }
    return sum;
}

void solve(){
    string str;
    point s(0,0),d;
    double area=getarea();
    while(cin>>d.x>>d.y>>str){
        //if(d.x<-eps || d.y<-eps || d.x>10+eps || d.y>10+eps){
            //printf("0.00\n");
            //break;
        //}
        if(str=="Colder"){
            if(fabs(d.x-s.x)>eps || fabs(d.y-s.y)>eps){
                deal(s,d,-1);
                area=getarea();
            }
        }
        else if(str=="Hotter"){
            if(fabs(d.x-s.x)>eps || fabs(d.y-s.y)>eps){
                deal(s,d,1);
                area=getarea();
            }
        }
        else{
            area=0;
        }
        printf("%.2lf\n",area);
        if(area<eps) break;
        s=d;
    }
    while(cin>>d.x>>d.y>>str){
        printf("0.00\n");
        continue;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    ini();
    solve();
    return 0;
}
