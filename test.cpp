#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;



int check_pal ( string& s ){
  int low = 0 ;
  int high = s.length() - 1 ;
  while ( high > low ) {
    /* code */
    if( s[ high ] != s[ low ]){
      if( s[ high - 1 ] == s [ low ] )
        return high ;
      else if ( s[ low + 1 ] == s[ high ])
        return low ;
    }
    else{
      high -= 1;
      low += 1 ;
    }
  }
  return -1;
}
int main(int argc, char const *argv[]) {
  string s;
  std::cin >> s;
  int p = check_pal( s );
  std::cout << "index = "<< p << '\n';
  return 0;
}
