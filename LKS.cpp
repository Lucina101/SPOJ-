#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int dp[2][maxn],v[1000],w[1000],n,k,x;
 main(){
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&v[i],&w[i]);
    int ans=0;
    for(int i=1;i<=n;i++){
        x=i&1;
        for(int j=0;j<=k;j++){
            if(j-w[i]>=0){
                dp[x][j]=max(dp[(x+1)&1][j],dp[(x+1)&1][j-w[i]]+v[i]);
            }
            else
                dp[x][j]=dp[(x+1)&1][j];
            ans=max(ans,dp[x][j]);
        }
    }
    printf("%d\n",ans);
//dp[i][j] consider first i knapsack with weight not more than j

}
