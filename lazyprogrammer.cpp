#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,g,pt;
int val[maxn];
double ans,x;
int u,v,w;
struct pa{
    int a;
    int b;
    int d;
    bool operator < (const pa x)const{
    return d<x.d;
    }
};
vector<pa> f;
priority_queue<pair<int,int>> q;
void clean(){
    for(int i=0;i<n;i++)
        val[i]=0;
    while(!f.empty())
        f.pop_back();
    while(!q.empty())
        q.pop();
    return;
}
int main(){
    scanf("%d ",&t);
    while(t--){
        scanf(" %d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            f.push_back({u,v,w});
        }
        sort(f.begin(),f.end());
        pt=0;
        ans=0.0;
        for(int i=0;i<n;i++){
            q.push({f[i].a,i});
            val[i]=f[i].b;
            pt+=(f[i].b);
            x=f[i].d;
            while(pt>x){
                g=q.top().second;
                if(pt-val[g]<=x){
                    ans+=(double(pt-x)/double(q.top().first));
                    val[g]-=(pt-x);
                    pt=x;
                    break;
                }
                else{
                    ans+=(double(val[g])/double(q.top().first));
                    pt-=(val[g]);
                    q.pop();
                }
            }
        }
        printf("%.2f\n",ans);
        clean();
    }
}
