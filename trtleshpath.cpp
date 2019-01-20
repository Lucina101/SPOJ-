#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10,big=-1e9;
int t,n,key,r,u,v,s,d,tes;
int val[maxn];
map<string,int> f[11];
string kuy,kuy1;
char fuck[11],fuck1[11];
vector<pair<int,int>> b[maxn];
bool vis[maxn];
void clean(){
    for(int p=1;p<=n;p++)
        vis[p]=false,val[p]=big;
    return;
}

int main(){
    scanf("%d",&t);
    for(int i=0;i<t;i++){
       scanf("%d",&n);
        for(int j=1;j<=n;j++){
           scanf("%s ",fuck);
           kuy=string(fuck);
           f[i][kuy]=j;
            scanf("%d",&r);
            while(r--){
                scanf("%d%d",&u,&v);
                b[j].push_back({u,v});
            }
        }
        scanf("%d",&tes);
        while(tes--){
            clean();
            scanf("%s %s",fuck,fuck1);
            kuy=string(fuck);
            kuy1=string(fuck1);
            s=f[i][kuy];
            d=f[i][kuy1];
            priority_queue<pair<int,int>> a;
            a.push({0,s});
            val[s]=0;
            while(!vis[d]){
                while(vis[a.top().second])
                a.pop();
                u=a.top().second;
                if(u==d)
                    break;
                a.pop();
                for(auto x:b[u]){
                    if(!vis[x.first]){
                    if(val[x.first]==big){
                        val[x.first]=val[u]-x.second;
                        a.push({val[x.first],x.first});
                    }
                    else{
                        if(val[x.first]<val[u]-x.second){
                            val[x.first]=val[u]-x.second;
                            a.push({val[x.first],x.first});
                        }
                    }
                }
                }
                vis[u]=true;
            }
            printf("%d\n",-val[d]);
        }
        for(int kk=1;kk<=n;kk++){
            while(!b[kk].empty())
                b[kk].pop_back();
        }
    }
}
