#include<bits/stdc++.h>

using namespace std;

int price[1001] , weight[1001] ;
int n , k , pre = 0 , now = 1 ;
int dp[2][100001] ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> k ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> price[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> weight[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= k ; j ++ ){
            dp[now][j] = dp[pre][j] ;
            if(price[i] <= j){
                dp[now][j] = max(dp[now][j] , dp[pre][j - price[i]] + weight[i]) ;
            }
        }
        swap(pre , now) ;
    }

    cout << dp[pre][k] ;
     
    return 0 ;
}