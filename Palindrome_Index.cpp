#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool pallindrom( string sub  ){
  int low = 0;
  int high = sub.length() - 1 ;
  int i =  0 ;
  while (high > low)
    {
      //std::cout << i++ << '\n';
        if (sub[low++] != sub[high--])
        {
            //printf("%s is Not Palindrome", str);
            return false ;
        }
    }
    return true ;
}
int check_pal ( string& s ){
  if(pallindrom( s ) )
    return -1 ;
  int ret = - 1 ;
  int len = s.length();
  for ( int i = 0 ; i < len ; ++i ){
    string sub = s.substr( 0 , i ) + s.substr( i + 1 );
  //  std::cout << "->"<< sub << '\n';
    if ( pallindrom( sub ) ){
      ret = i ;
      return ret ;
      break;
    }
  }
  return ret ;
}
int main(int argc, char const *argv[]) {
  string s;
  std::cin >> s;
  int p = check_pal( s );
  std::cout << "index = "<< p << '\n';
  return 0;
}
