#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,inf=1e9;
int t,n,k,p,x,v[maxn],ans,c;
vector<int> a[maxn];
bool b[maxn];

int main(){
    scanf("%d",&t);
    while(t--){
        priority_queue<pair<int,int>> q;
        scanf("%d%d%d",&n,&k,&p);
        for(int i=1;i<=n;i++){
            a[i].clear();
            b[i]=false;;
        }
        for(int i=1;i<=p;i++){
            scanf("%d",&v[i]);
            a[v[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)
            a[i].push_back(p+1);
        for(int i=1;i<=n;i++)
            reverse(a[i].begin(),a[i].end());
        ans=0,c=0;
        for(int i=1;i<=p;i++){
            if(b[v[i]]){
                a[v[i]].pop_back();
                q.push(make_pair(a[v[i]].back(),v[i]));
                continue;
            }
            if(c<k){
                b[v[i]]=true;
                a[v[i]].pop_back();
                ans++;
                c++;
                q.push(make_pair(a[v[i]].back(),v[i]));
            }
            else{
                auto it=q.top(); q.pop();
                b[it.second]=false;
                a[v[i]].pop_back();
                b[v[i]]=true;
                q.push(make_pair(a[v[i]].back(),v[i]));
                ans++;
            }
        }
        printf("%d\n",ans);
    }

}
