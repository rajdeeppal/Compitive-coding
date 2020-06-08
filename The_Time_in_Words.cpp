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
string timeInWords(int h, int m) {
unordered_map < int , string > hr ;
unordered_map < int , string > min ;

hr[ 1 ] = "one " ;
hr[ 2 ] = "two " ;
hr[ 3 ] = "three " ;
hr[ 4 ] = "four " ;
hr[ 5 ] = "five " ;
hr[ 6 ] = "six " ;
hr[ 7 ] = "seven " ;
hr[ 8 ] = "eight " ;
hr[ 9 ] = "nine " ;
hr[ 10 ] = "ten " ;
hr[ 11 ] = "eleven " ;
hr[ 12 ] = "twelve " ;
min[ 0 ] = "o' clock " ;
min [1 ] = "one " ;
min [2 ] = "two " ;
min [3 ] = "three " ;
min [4 ] = "four ";
min [5 ] = "five ";
min	[ 6 ] = "six ";
min [ 7 ] = "seven " ;
min [ 8 ] = "eight " ;
min [	9 ] = "nine " ;
min [ 10 ] = "ten " ;
min [ 11 ] = "eleven " ;
min [ 12 ] ="twelve " ;
min [ 13 ] = "thirteen " ;
min [ 14 ] = "fourteen " ;
min [ 15 ] = "quater " ;
min [ 16 ] = "sixteen " ;
min [ 17 ] = "seventeen " ;
min [ 18 ] ="eighteen " ;
min [ 19 ] = "nineteen " ;
min [ 20 ] ="twenty " ;
min [ 21 ] = "twenty one " ;
min [ 22 ] ="twenty two " 	;
min [ 23 ] ="twenty three " 	;
min [ 24 ] ="twenty four " ;
min [ 25 ] = "twenty five " ;
min [ 26 ] ="twenty six"  ;
min [ 27 ] ="twenty seven " ;
min [ 28 ] = "twenty eight " ;
min [ 29 ] = "twenty nine " ;
min [ 30 ] = "half ";

string ans = "" ;
if( m == 0 )
{
  ans = hr[ h ] + min [ 0 ];
  return ans ;
}
if( m <= 30 ){
  ans += min [ m ] ;
  if( m != 15 && m != 30 && m != 1 )
    ans += "minutes " ;
  if ( m == 1 )
    ans += "minute " ;
  ans += "past " ;

  ans += hr[ h ] ;
}
else {
  m = 60 - m ;
  ans += min [ m ] ;
  if( m != 15 && m != 30 )
    ans += "minutes " ;
  ans += "to " ;
  if( h == 12 )
    h =  1 ;
  ans += hr[  1 ] ;
}
return ans ;
}
int main(int argc, char const *argv[]) {
  int h , m ;
  std::cin >> h ;
  std::cin >>  m ;
  string res = timeInWords( h,  m ) ;
  std::cout << res << '\n';
  return 0;
}
