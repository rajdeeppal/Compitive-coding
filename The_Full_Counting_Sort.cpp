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
void countSort( std::vector< std::vector< string > >& arr ){
int n = arr.size() ;
int max_rank = 0 ;
unordered_map < int , std::vector< string >  > collection ;
for( int i = 0 ; i < n / 2 ; ++i ){
  int rank  = stoi( arr[ i ] [ 0 ] );
  max_rank = max( rank , max_rank ) ;
  collection[ rank ].push_back( "-" );
}
for ( int i = n / 2 ; i < n ; ++i ){
  int rank  = stoi( arr[ i ] [ 0 ] );
  max_rank = max( rank , max_rank ) ;
  collection[ rank ].push_back( arr[ i ][ 1 ] ) ;
}
std::cout << " max rank - > "<< max_rank << '\n';
std::cout << " --------------------------------------- " << '\n';
for ( auto ele : collection ){
  std::cout << ele.first << " ";
  std::vector< string > vec = ele.second;
  for ( string str : vec ){
    std::cout << str <<  " " ;
  }
  std::cout  << '\n';
}
string ans = "";
for ( int i = 0  ; i <= max_rank ; ++i ){
  std::vector< string > v = collection[ i ] ;
  for ( string str : v ){
    ans  += str ;
    ans += " " ;
  }
}

std::cout << " ---------------------- " << '\n';
std::cout << ans << '\n';
/*for ( auto vec : collection ){
  for( string s : vec ){
    std::cout << s <<" " << '\n';
  }
  std::cout  << '\n';
}*/
}
int main(int argc, char const *argv[]) {
  int n ;
  std::cin >> n ;
  std::vector< std::vector< string > > arr (  n , std::vector< string> ( 2 ) );
  for( int i = 0 ; i < n ; ++i ){
    std::string s , x ;
    std::cin >> x ;
    std::cin >> s ;
    arr[ i ][ 0 ] = x  ;
    arr[ i ][ 1 ] = s ;
    //std::cin >> x ;
  }
    countSort(arr);
  return 0;
}
