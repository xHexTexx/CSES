#include<bits/stdc++.h>

using namespace std;

int main(){

    //Solve by HexTex 
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    set<int>sett ;

    int n , x ; cin >> n ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> x ;
        sett.insert(x) ;
    }

    cout << sett.size() ;
    
    return 0 ;
}