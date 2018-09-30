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

    int n, k;
    cin >> n >> k;
    int cost = 0;
    vector<int> firstWeek, secondWeek;
    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        firstWeek.push_back(cost);
    }
    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        secondWeek.push_back(cost);
    }
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> differences;
    for(int i = 0; i < n; i++) {
        int difference = firstWeek[i] - secondWeek[i];
        differences.push(make_pair(difference, i));
    }
    for(int i = 0; i < k; i++) {
        auto it = differences.top();
        cost += firstWeek[it.second];
        differences.pop();
    }
    while(!differences.empty()) {
        auto it = differences.top();
        cost += min(firstWeek[it.second], secondWeek[it.second]);
        differences.pop();
    }
    cout << cost;


    
    return 0;
}