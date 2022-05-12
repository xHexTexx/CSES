#include<bits/stdc++.h>

using namespace std;

int n , x ;
vector<int>lis ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> x ;
        auto it = lower_bound(lis.begin() , lis.end() , x) ;
        if(it == lis.end())lis.push_back(x);
        else *it = x ;
    }

    cout << lis.size() ;

    return 0 ;
}