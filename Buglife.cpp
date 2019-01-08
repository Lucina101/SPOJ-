#include<bits/stdc++.h>
using namespace std;
int t,n,x,u,v,k;
vector<int> a[2010][1000];
int c[3000];
bool ch,vis[3000];
void dfs(int nod){
    vis[nod]=true;
    for(auto &i: a[nod][k]){
            if(c[nod]==1){
                if(c[i]==0){
                c[i]=2;
                if(!vis[i])
                dfs(i);
                }
                else if(c[i]==1){
                    ch=false;
                    return;
                }
            }
            else if(c[nod]==2){
                if(c[i]==2){
                    ch=false;
                    return ;
                }
                else if(c[i]==0){
                    c[i]=1;
                    if(!vis[i])
                    dfs(i);
                }
            }
        }
    return ;
    }

int main(){
    scanf("%d",&t);
    for( k=1;k<=t;k++){
            ch=true;
        scanf("%d%d",&n,&x);
        memset(vis,false,sizeof(vis));
        memset(c,0,sizeof(c));
        for(int i=1;i<=x;i++){
            scanf("%d%d",&u,&v);
            a[u][k].push_back(v);
            a[v][k].push_back(u);
        }
        for(int j=1;j<=n;j++){
        if(!vis[j]){
        c[j]=1;
        dfs(j);
        }
        }
        printf("Scenario #%d:\n",k);
        if(ch)
        printf("No suspicious bugs found!\n");
        else
        printf("Suspicious bugs found!\n");
    }
    }

