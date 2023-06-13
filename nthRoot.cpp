#include<bits/stdc++.h>
using namespace std;
double m=1e-8;
double binPow(double n,int p){
    if(p==0)
    return 1;
    double x=binPow(n,p/2);
    if(p%2==0)
        return x*x;
    else return x*x*n;
}
int main(){
    double n,mid;int p;
    cin>>n>>p;
    double lo=0,hi=n;
    while(hi-lo>m){
        mid=(lo+hi)/2;
        if(binPow(mid,p)<n)
            lo=mid;
        else hi=mid;
    }
    cout<<lo<<" "<<pow(5,1.0/2);
}