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
string organizingContainers(vector<vector<int>> container) {
//map <  int , unsigned long int > limit ;
std::vector< unsigned long int > limit ( container.size() ) ;
unsigned long int sum = 0 ;
for ( long i = 0 ; i < container.size() ; ++i ){
  sum = 0 ;
  for ( long j = 0 ; j < container[ i ].size() ; ++j ){
    sum += container[ i ][ j ] ;
  }
  limit [ i ] = sum ;
  //limit[ i ] = accumulate(container[ i ].begin(), container[ i ].end(), 0);
}

sort( limit.begin() , limit.end() ) ;
for( int i = 0 ; i < container.size() ; ++i ){
  std::cout << "->"<<limit[ i ] << '\n';
}
std::vector< unsigned long int > prefix ( container[ 0 ].size() , 0 );
//std::vector< int > sufix ( container[ 0 ].size() , 0 );

for ( long i = 0  ; i < container.size()  ; ++i  ){
  for ( long j = 0 ; j < container[ i ].size() ; ++j ){
    std::cout << "adding : "<< prefix[ j ] <<" + "<< container [ i ] [ j ] ;
    prefix [ j ] += container [ i ][ j ] ;
    std::cout << " = " << prefix[ j ] << '\n';
    //sufix [ j ] += container [ a ][ j ] ;
  }
}

sort( prefix.begin() , prefix.end() ) ;
for ( unsigned long int x : prefix ){
  std::cout << x << '\n';
}
for( int i = 0 ; i < container[ 0 ].size() ; ++i ){
  if( limit[ i ] < prefix[ i ] )
  {
    std::cout << limit[ i ] <<" : "<< prefix [ i ]<< '\n';
    return "Impossible";
  }
}
return "Possible";
}


int main()
{

        int n;
        cin >> n;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        cout << result << "\n";

    //fout.close();

    return 0;
}
