#include<bits/stdc++.h>

using namespace std;

multiset<int>mts ;
int n , q , x ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> x ;
        mts.insert(-x) ;
    }

    while(q -- ){
        cin >> x ;
        auto it = mts.lower_bound(-x) ;

        if(it == mts.end()){
            cout << -1 << '\n' ;
        }
        else {
            cout << *it * -1 << '\n' ;
            mts.erase(it) ; 
        }
    }
    return 0 ;
}