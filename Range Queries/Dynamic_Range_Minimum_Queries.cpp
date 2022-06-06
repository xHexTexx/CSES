#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;

class Segment {

    public :
        int seg[4 * N];

        void init(){
            memset(seg , 0x3f3f3f3f , sizeof(seg));
        }

        void update(int nl , int nr , int idx , int val , int now){
            if(nr < idx || nl > idx)return ;
            if(nl == nr){
                seg[now] = val ;
                return ;
            }
            int mid = (nl + nr) >> 1 ;
            update(nl , mid , idx , val , now * 2) ; update(mid + 1 , nr , idx ,val , now * 2 + 1);
            seg[now] = min(seg[now * 2] , seg[now * 2 + 1]);
        }

        int query(int l , int r , int nl , int nr , int now){
            if(nl > r || nr < l)return INT_MAX ;
            if(nl >= l && nr <= r)return seg[now];
            int mid = (nl + nr) >> 1 ;
            return min(query(l , r , nl , mid , now * 2),query(l , r , mid + 1 , nr , now * 2 + 1));        
        }
}Seg;

int n , q , x , l , r , cmd , idx ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> x ;
        Seg.update(1 , n , i , x , 1);
    }
    while(q -- ){
        cin >> cmd ;
        if(cmd == 1){
            cin >> idx >> x ;
            Seg.update(1 , n , idx , x , 1);
        }
        else {
            cin >> l >> r ;
            cout << Seg.query(l , r , 1 , n , 1) << '\n' ;
        }
    }


    return 0 ;
}