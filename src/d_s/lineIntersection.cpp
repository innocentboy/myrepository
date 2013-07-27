/*
 * lineIntersection.cpp
 *
 *  Created on: Mar 6, 2013
 *      Author: indresh
 */

#include <iostream>
#include <set>
#include<vector>

#define EPS 1E-9
using namespace std;


struct point{
	double X;
	double Y;
};

point operator-(point&a ,point&b){
	return point(a.X-b.X,a.Y-b.Y);
}
int ccw(point p,point q,point r){
	point pq=(q-p),pr=(r-p); //pq=x1i+y1j, pr=x2i+y2j pqXpr=X1Y2-X2Y1
	double cp=pq.X*pr.Y-pq.Y*pr.X;
	if(cp<0) return +1;//left turn
	if(cp>0) return -1;//right turn
	return 0;
}
struct segment{

	point left,right;
	int id;
    double gey_y(double x){
    	if(abs(left.X-right.X)<EPS) return left.Y;
    	else
    		return left.Y+(right.Y-left.Y)*(x-left.X)/(right.X-left.X);
    }
};

struct event{
	double x;
	int id; //to point the segment
	int  type; // +1 for left point -1 for right ppoint

	event (double x ,int type,int id):x(x),type(type),id(id){

    }

	bool operator<(event &e){
    	if(abs(x-e.x)>EPS) return x<e.x;
    	else
    		return type>e.type;
    }
};

bool isPointOnSegment(point &p,segment &s){
  double MinX,MaxX,MinY,MaxY;
  if(s.left.X<s.right.X){
	  MinX=s.left.X;
	  MaxX=s.right.X;
  }
  else{
	  MaxX=s.left.X;
	  MinX =s.right.X;
  }
  if(s.left.Y<s.right.Y){
 	  MinY=s.left.Y;
 	  MaxY=s.right.Y;
   }
   else{
 	  MaxY=s.left.Y;
 	  MinY =s.right.Y;
   }
   if((p.X>MinX && p.X<MaxX) && (p.Y>MinY && p.Y<MaxY)){
	  return true;
   }
   return false;
}


bool isSegmentIntersect(segment a ,segment b){
   	int d1=ccw(a.left,a.right,b.left);
   	int d2=ccw(a.left,a.right,b.right);
   	int d3=ccw(b.left,b.right,a.left);
   	int d4=ccw(b.left,b.right,a.right);

   if(((d1>0 && d2<0) || (d1<0 && d2>0)) &&((d3>0&&d4<0)||(d3<0&&d4>0))){
	  return true;
   }
   if(((0==d1)&& isPointOnSegment(b.left,a))){
	 return true;
   }
   if(((0==d2)&&(isPointOnSegment(b.right,a)))){
	 return true;
   }
   if((0==d3) && isPointOnSegment(a.left,b)){
	 return true;
   }
   if((0==d4)&& isPointOnSegment(a.right,b)){
	 return true;
   }
   	 return false;
}
bool operator<(segment &a,segment &b){
	double x=max(a.left.X,b.left.X);
	return a.gey_y(x)<b.gey_y(x)+EPS;
}
vector<event> e;
set<segment> Ssegs;
segment next(set<segment>::iterator it){
	return it==Ssegs.begin()?Ssegs.end():it++;
}
segment pre(set<segment>::iterator it){
	return it--;
}

pair<int,int> solve(vector<segment> Vsegs){

	size_t N=Vsegs.size();
	for(size_t t=0;t<N;t++){
		e.push_back(event(Vsegs[t].left,1,t));
		e.push_back(event(Vsegs[t].right,-1,t));
	}
	sort(e.begin(),e.end());
    vector<set<segment>::iterator > where(Vsegs.size());
	N=e.size();
	for(size_t t=0;t<N;t++){
		int id=e[t].id;
		 set<segment>::iterator next,pre;
          if(e[t].type==1){

             next=Ssegs.lower_bound(Vsegs[id]);
             if((next!=Ssegs.end()) && isSegmentIntersect(*next,Vsegs[id]))
            	 return make_pair(id,next->id);
             pre=pre(next);
             if((pre!=Ssegs.end()) &&  isSegmentIntersect((*pre),Vsegs[id]))
                        	 return  make_pair(id,pre->id);
             where[id]=Ssegs.insert(Vsegs[id]);
          }
          else{
                    next=next(where[id]);
                    pre=pre(where[id]);
                    if(pre!=Ssegs.end() && next!=Ssegs.end() && isSegmentIntersect(*next,*pre)){
                    	return  make_pair(pre->id,next->id);
                    }
                    Ssegs.erase(where[id]);
          }

}
	return make_pair(-1,-1);
}
