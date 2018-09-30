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
    string kuro, shiro, katie;
    cin >> kuro >> shiro >> katie;
    int length = kuro.length();
    int kuroMax = 0;
    int shiroMax = 0;
    int katieMax = 0;
    map<char, int> ku, sh, ka;
    for(int i = 0; i < kuro.length(); i++) {
        ku[kuro[i]]++;
        if(ku[kuro[i]] > kuroMax) {
            kuroMax = ku[kuro[i]];
        }
    }
    for(int i = 0; i < shiro.length(); i++) {
        sh[shiro[i]]++;
        if(sh[shiro[i]] > shiroMax) {
            shiroMax = sh[shiro[i]];
        }
    }
    for(int i = 0; i < katie.length(); i++) {
        ka[katie[i]]++;
        if(ka[katie[i]] > katieMax) {
            katieMax = ka[katie[i]];
        }
    }

    kuroMax += n;
    shiroMax += n;
    katieMax += n;
    if(kuroMax > length) {
        kuroMax = length;
        if((kuroMax + n - length) == 1) {
            kuroMax -= 1;
        }
    }
    if(shiroMax > length) {
        shiroMax = length;
        if((shiroMax + n - length)  == 1) {
            shiroMax -= 1;
        }
    }
    if(katieMax > length) {
        katieMax = length;
        if((katieMax + n - length) == 1) {
            katieMax -= 1;
        }
    }
    int maxV = max(kuroMax, max(shiroMax, katieMax));
    int count = 0;
    string winner = "";
    if(kuroMax == maxV) {
        winner = "Kuro";
        count++;
    }
    if(shiroMax == maxV) {
        winner = "Shiro";
        count++;
    }
    if(katieMax == maxV) {
        winner = "Katie";
        count++;
    }
    if(count >= 2) {
        cout << "Draw";
    }
    else {
        cout << winner;
    }


    
    return 0;
}