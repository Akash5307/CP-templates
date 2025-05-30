#include<bits/stdc++.h>
using namespace std;
#define int long long int
using Point=complex<int>;
int dot(Point a,Point b){
    return (conj(a)*b).real();
}
int cross(Point a,Point b){
    return (conj(a)*b).imag();
}
struct CHT{
    vector<Point>hull;
    vector<Point>vec;
    void addLine(int m,int c){
        Point nv={m,c};
        while(!vec.empty() and dot(vec.back(),nv-hull.back())<0){
            hull.pop_back();
            vec.pop_back();
        }
        if(!hull.empty()){
            Point direction=Point(0,1)*(nv-hull.back());
            vec.push_back(direction);
        }
        hull.push_back(nv);
    }
    int query(int x){
        Point q={x,1};
        auto it=lower_bound(vec.begin(),vec.end(),q,[](Point a,Point b){
            return cross(a,b)>0;
        });
        int ind=it-vec.begin();
        return dot(q,hull[ind]);
    }
};
