#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void almostSorted(vector<int> arr) {
int n = arr.size() ;
std::vector< int > sorted ( arr.begin() , arr.end() );
sort( sorted.begin() , sorted.end() ) ;
/*for( int x : sorted ){
  std::cout << x << '\n';
}*/
int def = 0 ;
std::vector< int >  trac ;
for ( int i = 0 ; i < n ; i++ ){
  if( arr[ i ] != sorted[ i ] ){
    def += 1 ;
    trac.push_back( i ) ;
  }
}
if( def == 2 ){
  swap( arr[ trac [ 0 ] ] , arr[ trac [ 1 ] ] ) ;
  std::cout << "yes" << '\n';
  std::cout << "swap "<< trac[ 0 ] + 1 <<" "<<trac [ 1 ] + 1 << '\n';
  return ;
}

reverse ( arr.begin() + trac[ 0 ] , arr.begin() + trac.back() +  1 ) ;
//std::cout << "reverse " << '\n';
/*for( int x : arr ){
  std::cout << x <<" ";
}
std::cout << "sorted " << '\n';
std::cout << '\n';
for ( int x : sorted ){
  std::cout << x << " ";
}*/
def = 0 ;
for ( int i = 0 ; i < n ; i++ ){
  if( arr[ i ] != sorted[ i ] ){
    def += 1 ;
    //trac.push_back( i ) ;
  }
}
//std::cout << "def "<<def << '\n';
if( def == 0 ){
  std::cout << "yes" << '\n';
  std::cout << "reverse "<< trac[ 0 ] + 1 <<" "<< trac.back() + 1 << '\n';
  return ;
}
std::cout << "no" << '\n';
}

int main(int argc, char const *argv[]) {
  int n ;
  std::cin >> n ;
  std::vector< int > vec( n ) ;
  for ( int i = 0 ; i < n ; ++i ){
    std::cin >> vec [ i ];
  }
  almostSorted( vec ) ;
  return 0;
}
