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
int activityNotifications(vector<int> expenditure, int d) {

int len = expenditure.size() ;

multiset < int > block ;

int cnt = 0 ;

for ( int i = 0 ; i < d ; ++i ){
  block.insert( expenditure [ i ] ) ;
}
int base = 0 ;
for ( int i = d ; i < len ; ++i  ){
  std::multiset<int>::iterator it = block.begin();
  std::advance(it, block.size() / 2);
  int median = *it;
  if( expenditure [ i ] >= median * 2 ) cnt += 1 ;
  block.erase (block.begin() ) ;
  block.insert( expenditure[ i ] ) ;
}

return cnt ;
}

int main(int argc, char const *argv[]) {
  int d ;
  int n ;
  std::cin >> n ;
  std::cin >> d ;
  std::vector< int > v ( n ) ;
  for ( int i = 0 ; i < n ; ++i ){
    std::cin >> v [ i ] ;
  }
  int c = activityNotifications( v , d ) ;
  std::cout << c << '\n';
  return 0;
}
