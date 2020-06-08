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
int travel_to_cities ( std::vector< std::vector< int > >&  roads , std::vector< std::vector<int> >& rails , int u , int v ){
  int source = u - 1 ;
  int desti = v - 1 ;
  int m = 999 ;
  int mid_station  ;
  for ( int j =  0 ; j < roads[ 0 ].size() ; ++j  ){
    if( j == source ) continue ;
    if ( j != desti )
    {
      if( roads[ source ] [ j ] < m ){
      //m = min( m , roads [ source ] [ j ] ) ;
      m = roads[ source ] [ j ] ;
      mid_station = j ;
    }
    }
  }
  std::cout << " roads : "<< m  << '\n';
 m += rails[ mid_station ][ desti ] ;
 return m ;
}
int main(int argc, char const *argv[]) {
  int n ;
  int u , v ;
  std::cin >>  n ;
  std::vector< std::vector< int > > roads( n , std::vector< int > ( n ) ) ;
  std::vector< std::vector< int > > rails( n , std::vector< int > ( n ) ) ;
  for ( int i = 0 ; i < n ; ++i ){
    for ( int j = 0 ; j < n ; ++j ){
      std::cin >> roads[ i ] [ j ];
    }
  }
  for ( int i = 0 ; i < n ; ++i ){
    for ( int j = 0 ; j < n ; ++j ){
      std::cin >> rails[ i ] [ j ];
    }
  }
  std::cin >> u ;
  std::cin >> v ;
  int len = travel_to_cities( roads , rails , u , v ) ;
  std::cout << len << '\n';
  return 0;
}
