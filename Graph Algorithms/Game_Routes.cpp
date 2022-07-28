#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1 ;
vector<int>adj[N] ;
int n , m ,x , y;
long long dp[N] ;
int mod = 1e9 + 7 ;
bool visited[N];

void dfs(int now){

    long long sum = 0 ;

    for(auto i : adj[now]){
        if(visited[i]){
            sum += dp[i] ;
            continue ;
        }
        visited[i] = true ;
        dfs(i) ;
        sum += dp[i] ;
        sum %= mod ;
    }

    dp[now] = max(dp[now] , sum);
}
int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;
    for(int i = 0 ; i < m ;  i++ ){
        cin >> x >> y ;
        adj[x].push_back(y) ;
    }

    dp[n] = 1 ;
    dfs(1) ;
    cout << dp[1] ;

    return 0 ;
}