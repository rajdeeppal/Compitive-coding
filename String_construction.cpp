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
int stringConstruction ( string str ) {
  //unordered_map < char , int > trace ;
  set < char  > trace ;
  for(char x : str ){
    //trace [ x ]++;
    trace.insert( x ) ;
  }
  return trace.size() ;
}
int main(int argc, char const *argv[]) {
  string str ;
  std::cin >> str ;
  int cost = stringConstruction( str )  ;
  std::cout << "cost : "<<cost << '\n';
  return 0;
}
