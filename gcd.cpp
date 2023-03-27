#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(x%y==0)
    return y;
    return gcd(y,x%y);
}
int main(int argc, char const *argv[])
{
    cout<<gcd(5,10);
}
