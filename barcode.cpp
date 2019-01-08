#include<bits/stdc++.h>
using namespace std;
long long dp[100][100];
int n,k,m,pp;
int main(){
    while(scanf("%d%d%d",&n,&k,&m)!=EOF){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
            if(j>=l)
        dp[i][j]+=dp[i-1][j-l];
            }
        }
    }
    printf("%lld\n",dp[k][n]);
    }
}


