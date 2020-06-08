#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
int distribute ( std::vector< int >& a , std::vector< int > & g ){

  sort( a.begin() , a.end() , greater < int >() ) ;
  sort( g.begin() , g.end() ) ;
  int i ;
  for( i = 0 ; i < g.size() ; ++i ){
    int skip = 0 ;
    int val = g [ i ] ;
      for( int j = 0  ; j < a.size() &&  val  > 0 ; ++j ){
        if ( a [ j ] != 0 ) {
          a [ j ] -= 1;
          val -= 1 ;
        }
        else skip += 1 ;
      }
      if ( skip == a.size() ) {
        //return i ;
        break ;
      }
  }
  for( int x : a ){
    std::cout << x << " " ;
  }
  return i - 1 ;
}
int main(int argc, char const *argv[]) {
  int candy ;
  int group ;
  std::cin >> candy;
  std::cin >> group;
  std::vector< int > a( candy );
  std::vector< int > g ( group );
  for ( int i = 0 ; i < candy ; ++i ){
    std::cin >> a[ i ];
  }
  for( int i = 0 ; i < group ; ++i ){
    std::cin >> g [ i ];
  }
  int c = distribute( a , g ) ;
  std::cout << c << '\n';
  return 0;
}
