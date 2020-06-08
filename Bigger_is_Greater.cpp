#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
string biggerIsGreater(string w) {
  int len = w.length();
  std::vector< int > v( len ) ;
  std::map< int , char > trace ;
  for( int i = 0 ; i < len ; ++i ){
    int index = w[ i ] - 'a' ;
    v[ i ] = index ;
    trace[ index ] = w[ i ] ;
  }

  for( int x : v ){
    //char ch = x + '0';
    std::cout << x << '\n';
  }
std::cout << "/* message */" << '\n';

  int i ;
   for ( i = v.size() - 1 ; i > 0 ; --i ){
     if( v[ i - 1 ] < v[ i ]){
       break;
     }
   }
   if( i == 0 )
     return "no answer" ;
   int x = v[ i - 1 ] , mid = i ;
   for( int j = i + 1 ; j < v.size() ; ++j ){
     if ( v[ j ] > x && v[ j ] < v[ mid ] ){
       mid = j;
     }
   }
   swap( v[ i - 1 ], v [ mid ]) ;
   sort( v.begin() + i , v.end() );
  // std::cout << "loc : "<< v.begin() << '\n';
  for( int x : v ){
    //char ch = x + '0';
    std::cout << x << '\n';
  }

  //string ans = "";
  std::vector< char > ans ;
  for ( int x : v ){
    ans.push_back( trace[ x ] );
  }

  for ( auto x : trace ){
    std::cout << x.first <<" : "<< x.second << '\n';
  }
  string out = "";
  for( char ch : ans ){
    out += ch ;
  }
  return out ;

}
int main(int argc, char const *argv[]) {
  string w;
  std::cin >> w;
  string ans =  biggerIsGreater(w) ;
  std::cout << ans << '\n';
  return 0;
}
