#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int> absolutePermutation(int n, int k) {
std::vector< int > vec( n );
std::vector< int > els ( 1 , -1 );
unordered_map < int , bool > trace ;

for ( int i = 1 ; i <= k ; ++i ){
  trace [ i ] = false ;
}
for ( int i =  1 ; i <=  n  ; ++i ){
  if( i + k  <= n && i - k > 0 && ( !trace [ i + k ] || !trace[ i - k ] )){
    int p = min( i + k  , i - k  ) ;
    if ( !trace[ p ] ){
    vec[ i - 1 ] =  p ;
    trace [ p ] = false ;
  }
  else{
    vec[ i - 1 ] = max( i + k  , i - k  ) ;
    trace[ max (i + k  , i - k ) ] = true ;
  }
  }
  else if( i + k  <= n && !trace [ i + k ] )
    {
      vec[ i - 1 ] = ( i + k ) ;
      trace [ i + k ] = true ;
    }
  else if ( i - k > 0 && !trace[ i - k ]){
    vec [ i - 1 ] = ( i - k ) ;
    trace [ i - k ] = true ;
  }

  else {
    return els ;
    break ;
  }
}

return vec ;
//for ( int i = 0 ; i < )

}
int main(int argc, char const *argv[]) {

    int n , k ;
    std::cin >> n ;
    std::cin >> k ;

    std::vector< int  > vec = absolutePermutation( n, k ) ;
    for ( int x  : vec ){
      std::cout << x <<" " ;
    }
  return 0;
}
