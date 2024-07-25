#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct node{
    int lazy_add,lazy_set,sum;
    node(){
        lazy_add=0,lazy_set=0,sum=0;
    }
};
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}
node t[8*100005];
vector<int>a;
void build(int id,int l,int r){
    if(l==r){
        //leaf
        t[id].sum=a[l],t[id].lazy_add=0,t[id].lazy_set=0;
        return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
}
void push_down(int v,int child){
    if(t[v].lazy_set!=0){
        t[child].lazy_set=t[v].lazy_set;
        t[child].lazy_add=0;
    }else{
        if(t[child].lazy_set!=0){
            t[child].lazy_set+=t[v].lazy_add;
            // t[child].lazy_add=0;
        }else{
            t[child].lazy_add+=t[v].lazy_add;
            // t[child].lazy_set=0;
        }
    }
}
void push(int id,int l,int r){
    if(t[id].lazy_add==0 and t[id].lazy_set==0)return ;
    if(l!=r){
        push_down(id,2*id);
        push_down(id,2*id+1);
    }
    if(t[id].lazy_add!=0){
        t[id].sum+=(r-l+1)*t[id].lazy_add;
        t[id].lazy_add=0;
    }else if(t[id].lazy_set!=0){
        t[id].sum=(r-l+1)*t[id].lazy_set;
        t[id].lazy_set=0;
    }
}
void update(int id,int l,int r,int lq,int rq,int val,int u_type){
    push(id,l,r);
    if(lq>r or rq<l)return ;
    if(lq<=l and r<=rq){
        if(u_type==0){
            t[id].lazy_set=val;
        }else{
            t[id].lazy_add+=val;
        }
        push(id,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,val,u_type);
    update(2*id+1,mid+1,r,lq,rq,val,u_type);
    t[id]=merge(t[2*id],t[2*id+1]);
}
int query(int id,int l,int r,int lq,int rq){
    push(id,l,r);
    if(lq>r or rq<l)return 0;
    if(lq<=l and r<=rq){
        return t[id].sum;
    }
    int mid=(l+r)/2;
    return query(2*id,l,mid,lq,rq)+query(2*id+1,mid+1,r,lq,rq);
}
void solve() {
  int n,q;
  cin >> n>>q;
  a=vector<int>(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1,1,n);
  while(q--){
    int ch,a,b,x;
    cin>>ch;
    if(ch==1){
        cin>>a>>b>>x;
        update(1,1,n,a,b,x,1);
    }else if(ch==2){
        cin>>a>>b>>x;
        update(1,1,n,a,b,x,0);
    }else{
        cin>>a>>b;
        cout<<query(1,1,n,a,b)<<"\n";
    }
  }
}
int32_t main() {
  int T = 1;
  // cin>>T;
  while (T--) {
    solve();
  }
  return 0;
}
