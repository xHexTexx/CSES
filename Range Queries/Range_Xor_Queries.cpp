#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;

int qs[N] , n , q , l , r ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> qs[i];
        qs[i] = (qs[i] ^ qs[i - 1]);
    }

    while(q -- ){
        cin >> l >> r ;
        cout << (qs[r] ^ qs[l - 1]) << '\n';
    }

    return 0 ;
}