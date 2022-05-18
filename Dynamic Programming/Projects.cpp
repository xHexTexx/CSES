#include<bits/stdc++.h>

using namespace std;

int n , l , r , val , mid ;

long long dp[200001] ;

struct event {
    int s , p , val ;
    bool operator < (const event & rhs)const { 
        if(p == rhs.p)return val > rhs.val ;
        else return p < rhs.p ;
    }
};

vector<event>vec ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> l >> r >> val ;
        vec.push_back({l , r , val});
    }

    vec.push_back({-1 , -1 , 0});

    sort(vec.begin(), vec.end());

    for(int i = 1 ; i <= n ; i ++ ){

        l = 0 , r = i - 1;
        while(l < r){
            mid = (l + r + 1) >> 1 ;
            if(vec[mid].p < vec[i].s)l = mid ;
            else r = mid - 1;
        }
        dp[i] = vec[i].val + dp[l] ;
        dp[i] = max(dp[i] , dp[i - 1]);
    }

    cout << dp[n] ;

    return 0 ;
}