#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

sort( scores.begin() , scores.end() , greater< int >() );
std::vector< int > v ;
for ( int x : scores ){
  if( find( v.begin() , v.end() , x ) == v.end() ){
    v.push_back ( x );
  }
}
/*
for( int a : v ){
  std::cout << a << '\n';
}*/
std::vector<int> ans;
for ( int x : alice ){
  auto it = find( v.begin() , v.end() , x );
  if( it != v.end() ){
    ans.push_back( it - v.begin() + 1 );
  //  std::cout << "found" << '\n';
    }
  else{
    //std::cout << "not found" << '\n';
    if ( x < v.back() ){
      //std::cout << "last" << '\n';
      v.push_back ( x ) ;
      ans.push_back( v.size()  ) ;
    }
    else{
      auto index = upper_bound( v.begin() , v.end() , x ,std::greater<int>());
      std::cout <<x<< "index "<< *index << '\n';
      auto custom   =  v.insert( index , x );
      ans.push_back( ( custom - v.begin() + 1 ) );
    }
  }
}

return ans;
}
int main(int argc, char const *argv[]) {

  int score_count ;
  int alice_count ;
  std::cin >> score_count;
  std::vector< int > scores (score_count ) ;

  for( int i = 0 ; i < score_count ; ++i ){
    std::cin >> scores[ i ];
  }
  std::cin >> alice_count ;
    std::vector< int > alice ( alice_count ) ;
  for( int i = 0 ; i < alice_count ; ++i ){
    std::cin >> alice [ i ];
  }

  std::vector< int > v(  alice_count );
  v = climbingLeaderboard( scores , alice );

  for( int x : v ){
    std::cout << x << '\n';
  }
  return 0;
}
