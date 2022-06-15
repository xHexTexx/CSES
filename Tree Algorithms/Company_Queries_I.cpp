#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;
int n , q , x , l , dp[N][20] , level[N];

vector<int>adj[N] ;

void dfs(int now , int pa , int cnt){

    level[now] = cnt ;
    dp[now][0] = pa ;

    for(int i = 1 ; (i <= 18) && (1 << i) < cnt ; i ++ ){
        dp[now][i] = dp[dp[now][i - 1]][i - 1] ;
    }

    cnt ++ ;

    for(auto i : adj[now]){
        dfs(i , now , cnt) ;
    }
}

int solve(int now , int l){

    if(l >= level[now])return - 1 ;
    else {
        if(l == 0)return now ;
        int MAX = 0 ;
        for(int i = 1  ; i <= 18 && (1 << i) <= l ; i ++ ){
            MAX = max(MAX , i) ;
        }
        return solve(dp[now][MAX] , l - (1 << MAX));
    }
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> q ;

    for(int i = 2 ; i <= n ; i ++ ){
        cin >> x ;
        adj[x].push_back(i) ;
    }

    dfs(1 ,-1 ,1) ;

    while(q -- ){
        cin >> x >> l ;
        cout << solve(x , l) << '\n' ;
        
    }

    return 0 ;

}