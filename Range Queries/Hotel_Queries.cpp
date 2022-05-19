#include<bits/stdc++.h>

using namespace std;

const int N = 200001 ;

int n , m , want ;

int arr[N] ;

class Segment {

    public :
        int seg[4 * N] ;

        void update(int l , int r , int idx , int val , int now){
            
            if(l > idx || r < idx)return ;
            
            if(l == r){
                seg[now] = val ;
                return ;
            }

            int mid = (l + r) >> 1 ;
            update(l , mid , idx , val , now * 2) ; update(mid + 1 , r , idx , val , now * 2 + 1) ;
            seg[now] = max(seg[now * 2] , seg[now * 2 + 1]) ;
        }

        int query(int l , int r , int nl , int nr , int now){
            
            if(seg[now] < want)return INT_MAX ;

            else if(nl == nr){
                if(seg[now] >= want){
                    return nl ;
                }
                else {
                    return INT_MAX ;
                }
            }
            else {
                int mid = (nl + nr) >> 1 ;
                int res = INT_MAX ;
                if(seg[now * 2] >= want){
                    res = min(res , query(l , r , nl , mid , now * 2));
                    if(res < INT_MAX)return res ;
                }
                if(seg[now * 2 + 1] >= want){
                    res = min(res , query(l , r , mid + 1 , nr , now * 2 + 1 ));
                }
                return res ;
            }


        }

}Seg;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        Seg.update(1 , n , i , arr[i] , 1) ;
    }

    while(m -- ){
        int idx ;
        cin >> want ;
        idx = Seg.query(1 , n , 1 , n , 1) ;
        if(idx == INT_MAX){
            cout << 0 << ' ';
        }
        else {
            cout << idx << ' ';
            arr[idx] -= want ;
            Seg.update(1 , n , idx , arr[idx] , 1) ;
        }
    }
    return 0 ;
}