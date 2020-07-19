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
int steadyGene(string gene) {
  int len = gene.length() ;
  int occerance = len / 4 ;
  unordered_map <  char , int > rule ;
  for( char ch : gene ){
    rule [ ch ]++ ;
  }
  unordered_map < char , int > need ;
  unordered_map < char , bool > flag ;
  string s = "ACGT" ;
  for( char ch : s ){
    std::cout << ch<<" = "<< rule[ ch ] << '\n';
  }
  for( char ch : s ){
    flag [ ch ] = false ;
  }
  int t ;
  int l = 0 ;
  for( char ch : s ){
    if( rule[ ch ] > occerance ){
      t = ( rule[ ch ] - occerance ) ;
      need [ ch ] = t ;
      flag [ ch ] = true ;
      l += 1 ;
    }
    else
      need[ ch ] = INT_MAX ;
  }
  for( char ch : s ){
    std::cout<<ch <<" : "<<need [ ch ]  << '\n';
  }
  unordered_map < char , int > calculation ;
  int ini = 0 ;
  int li = 0 ;
  int length = INT_MAX ;
  int skip = 0 ;
  for( int i = 0 ; i < len ; ++i ){
    char ch = gene[ i ] ;
    calculation [ ch ]++;

    if( !flag [ ch ] && skip == 0 )
        ini += 1 ; // i++
    else if( flag [ ch ] && calculation [ ch ] == need [ ch ] ){
        li += 1 ;
        skip += 1 ;
      }
    else if ( flag [ ch ] && calculation [ ch ] > need [ ch ] ){
      skip += 1 ;
      while( !flag [ gene [ ini ] ] ){
        ini += 1 ;
      }
      if( gene [ ini ] == ch ){
        calculation [ gene [ ini ] ] = calculation [ gene [ ini ] ] - 1 ;
        ini += 1 ;
        while( !flag [ gene [ ini ] ] ){
          ini += 1 ;
        }
      }
      else{
        /*
        while( gene[ ini ] != ch ){
          if( flag [ gene [ ini ] ] ){
            //li -= 1 ;
            calculation [ gene [ ini ] ] -= 1 ;
            if( calculation [ gene [ ini ] ] == 0 )
                li -= 1 ;
          }
          ini += 1 ;
        }
        calculation [ ch ] -= 1 ;
        ini += 1 ;*/
        calculation['A'] = 0 ;
        calculation['C'] = 0 ;
        calculation['G'] = 0 ;
        calculation['T'] = 0 ;
        calculation[ ch ]++;
        skip = 1 ;
        ini = i ;
        li = 0 ;
      }
    }
    else if( flag [ ch ] ){
      skip += 1 ;
      std::cout << "normal found at "<< i << " "<< ch << '\n';
    }


    if( li == l ){
      std::cout<< ini << " - > "<< i << " = "<< (i - ini ) << '\n';
      length = min( ( i - ini ) , length ) ;
      while( !flag[ gene [ ini ] ] ){
        ini += 1 ;
      }
      calculation[ gene [ ini ] ] = calculation[ gene [ ini ] ] - 1 ;
      ini += 1 ;
      li -= 1 ;
      skip = 1 ;
      while( !flag[ gene [ ini ] ] ){
        ini += 1 ;
      }
        /*std::cout<< ini << " - > "<< i << " = "<< (i - ini ) << '\n';
        length = min( ( i - ini ) , length ) ;
        calculation[ gene [ ini ] ] = calculation[ gene [ ini ] ] - 1 ;
        std::cout << "back "<< ini << gene[ ini ] << calculation [ gene [ ini ] ]<< '\n';
        skip = 0 ;
        li -= 1 ;
        ini += 1 ;*/
        /*skip = 1 ;
        ini = i ;
        li = 0 ;
        calculation['A'] = 0 ;
        calculation['C'] = 0 ;
        calculation['G'] = 0 ;
        calculation['T'] = 0 ;
        calculation[ ch ]++;*/

      }
      std::cout << "******************************************** "<< ini <<" , "<< i << '\n';
  }
  return length ;
}
int main(int argc, char const *argv[]) {
  int n ;
  std::cin >> n ;
  string s ;
  std::cin >> s ;
  int i = 0 ;
  for( char ch : s ){
    std::cout << ch<<"=" << i++ <<"  ";
  }
  std::cout << '\n';

  std::cout << '\n';
  int c = steadyGene( s ) ;
  std::cout << c << '\n';
  return 0;
}
