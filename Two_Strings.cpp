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

string twoStrings(string s1, string s2) {
unordered_map < char , int > trace ;
for ( char ch : s1 ){
  trace [ ch ] ++ ;
}
for( char ch : s2  ){
  if( trace [ ch ] > 0 )
    return "YES" ;
}
return "NO" ;
}

int main(int argc, char const *argv[]) {
  string txt , pat ;
  std::cin >> txt ;
  std::cin >>  pat ;
  string ans = twoStrings( txt , pat ) ;
  std::cout << ans << '\n';
  return 0;
}
