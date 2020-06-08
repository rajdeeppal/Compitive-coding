#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include<math.h>
using namespace std;
string encryption ( string & s ){
  int len = s.length() ;
  float sqt = sqrt( len ) ;
  int floor_sqt = floor( sqt ) ;
  int ceil_sqt = ceil( sqt ) ;
  std::cout << "row :"<< floor_sqt <<"col : "<< ceil_sqt << '\n';
  string res ;
  for ( int i = 0 ; i < ceil_sqt  ; ++i ){
    for ( int j = i ; j < len ; j += ceil_sqt ){
      res += s [ j ] ;
      std::cout << res << '\n';
    }
    res += " ";
  }
  return res ;
}
int main(int argc, char const *argv[]) {
  string s;
  getline( cin , s );
  s.erase(remove(s.begin(), s.end(), ' '), s.end());
  string p = encryption ( s ) ;
  std::cout << p << '\n';
  //std::cout << s << '\n';
  return 0;
}
