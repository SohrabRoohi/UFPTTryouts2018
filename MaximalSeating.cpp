/*
  Sohrab Roohi
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/*
    ifstream in("C:\\Users\\Sohrab\\CLionProjects\\UFPTTryouts2018\\input.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("C:\\Users\\Sohrab\\CLionProjects\\UFPTTryouts2018\\output.txt");
    cout.rdbuf(out.rdbuf());
     */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            bool good = true;
            if (i - 1 >= 0) {
                if(s[i-1] == '1') {
                    good = false;
                }
            }
            if(i + 1 < n) {
                if(s[i+1] == '1') {
                    good = false;
                }
            }
            if(!good) {
                cout << "NO";
                return 0;
            }
        }
        else if(s[i] == '0') {
            bool notSurrounded = true;
            if (i - 1 >= 0) {
                if(s[i-1] == '1') {
                    notSurrounded = false;
                }
            }
            if(i + 1 < n) {
                if(s[i+1] == '1') {
                    notSurrounded = false;
                }
            }
            if(notSurrounded) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    
    return 0;
}