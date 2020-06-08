#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int pairs(int k, vector<int> arr) {
unordered_map < int , bool > trace ;

for( int x : arr ){
  trace[ x ] = true ;
}
int ct = 0 ;
for ( int x : arr ){
  if( x > k ){
    if( trace[ x - k ] ){
      std::cout << x << ":" << x - k << '\n';
      //std::cout << "1" << '\n';
      ct++;
    }
  }

}
return ct ;
}
int main(int argc, char const *argv[]) {
  int n , k ;
  std::cin >> n;
  std::cin >> k;
  std::vector< int > arr( n );
  for( int i = 0 ; i < n ; ++i ){
    std::cin >> arr[ i ];
  }
  int m  = pairs ( k , arr );
  std::cout << m << '\n';
  return 0;
}
