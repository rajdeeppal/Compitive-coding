#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long countTriplets ( std::vector< long >& arr , long r ){
  map<long long,long long> l,m;
  long ans  ; // r == m
  int n = arr.size() ;
  for(int i=0;i<n;i++)
    m[arr[i]]++;
   for(int i=0;i<n;i++)
   {
    m[arr[i]]--;
    if(arr[i]%r==0)
    {
     ans+=l[arr[i]/r]*m[arr[i]*r];
    }
    l[arr[i]]++;
   }
   return ans; 
  /*
  unordered_map < long , bool > vis ;
  for ( long x : arr ){
    vis [ x ] = false ;
  }
  unordered_map < long , int > trace ;
  for ( long x : arr ){
    trace [ x ]++ ;
  }
  long triplet = 0 ;
  for ( int i = 0 ; i < arr.size() ; ++i ){
    if ( ! vis[arr[i]] ){
    vis [ arr [ i ] ] = true ;
    long num = arr[ i ] ;
    int c = 0 ;
    long factor =  1 ;
    for ( int j = 0 ; j < 3 ; ++j , num *= r ){
      if ( trace.find ( num ) != trace.end()){
        factor *= trace[ num ] ;
        c += 1 ;
      }
      else
        break;
    }
    if( c == 3 ){
      triplet += factor ;
    }
  }
  }

  return triplet ;*/
}
int main(int argc, char const *argv[]) {
  long n ;
  std::cin >> n;
  long r ;

  std::cin >> r ;
  std::vector< long > arr( n );
  for ( long i = 0 ; i< n ; ++i ){
    std::cin >> arr [ i ];
  }


  long m = countTriplets( arr , r ) ;
std::cout << m << '\n';

  return 0;
}
