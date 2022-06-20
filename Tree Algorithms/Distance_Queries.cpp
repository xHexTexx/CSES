#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;

vector<int>tree[N] ;

int depth[N] , dp[N][20] , n , q ,x , y ;

void dfs(int now , int pa , int lvl){
    
    depth[now] = lvl ;
    dp[now][0] = pa ;

    for(int i = 1 ; i <= 18 && (1 << i) < lvl ; i++){
        dp[now][i] = dp[dp[now][i - 1]][i - 1] ;
    }

    for(auto i : tree[now]){
        if(i != pa)dfs(i , now , lvl + 1);
    }

}

int solve(int x , int y){
    
    if(x == y)return x ;
    if(depth[x] != depth[y]){
        if(depth[y] > depth[x])swap(x , y);
        int MAX = 0 ;
        for(int i = 1 ; i <= 18 && (1 << i) <= (depth[x] - depth[y]) ; i ++ ){
            MAX = max(MAX , i);
        }
        return solve(dp[x][MAX] , y);
    }
    else {
        int MAX = 0 ;
        for(int i = 1 ; i <= 18 && (1 << i) < depth[x] ; i ++ ){
            if(dp[x][i] != dp[y][i])MAX = max(MAX , i);
        }
        return solve(dp[x][MAX] , dp[y][MAX]);
    }
    
    return 0 ;
}


int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 0 ; i < n - 1 ; i ++ ){
        cin >> x >> y ;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1 , -1 , 1) ;

    for(int i = 0 ; i < q ; i ++ ){
        cin >> x >> y ;
        cout << depth[x] + depth[y] - 2 * depth[solve(x , y)] << '\n' ;
    }

    return 0 ;
}