#include<bits/stdc++.h>

using namespace std;

const int N = 2e5  + 1 ;

int n , q , x , y , dp[N][20] , level[N] ;

vector<int>tree[N];

void dfs(int now ,int pa , int lvl){

    level[now] = lvl ;
    dp[now][0] = pa ;

    for(int i = 1 ; i <= 18 && (1 << i) < lvl ; i ++ ){
        dp[now][i] = dp[dp[now][i - 1]][i - 1];
    }

    for(auto i : tree[now]){
        dfs(i , now , lvl + 1);
    }

    return ;    
}

int lca(int x , int y){

    if(level[y] > level[x])swap(x , y) ;

    if(level[x] > level[y]){
        int MAX = 0 ;
        for(int i = 1 ; i <= 18 && (1 << i) < level[x] - level[y] ; i ++){
            MAX = max(MAX , i);
        }
        return lca(dp[x][MAX] , y) ;
    }

    if(level[x] == level[y]){
        if(x == y)return x ;
        else {
            int MAX = 0 ;
            for(int i = 1 ; i <= 18 && (1 << i) < level[x] ; i ++ ){
                if(dp[x][i] != dp[y][i]){
                    MAX = max(MAX , i);
                }
            }
            return lca(dp[x][MAX] , dp[y][MAX]);
        }
    }

    return 0 ;
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 2 ; i <= n ; i ++ ){
        cin >> x ;
        tree[x].push_back(i) ;
    }

    dfs(1 , -1 , 1);

    while(q -- ){
        cin >> x >> y ;
        cout << lca(x , y) << '\n' ;
    }

    return 0 ;
}