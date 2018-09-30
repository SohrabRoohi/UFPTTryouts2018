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


    int v;
    cin >> v;
    int vBad = v;
    vector<pair<int,int>> values;
    map<int,int> costs;
    for(int i = 1; i <= 9; i++) {
        int cost;
        cin >> cost;
        values.push_back(make_pair(cost,i));
        costs.insert(make_pair(i,cost));
    }
    sort(values.begin(), values.end());
    string result = "";
    while(true) {
        int optimal = -1;
        int min = values[0].first;
        for(int i = 0; i < values.size(); i++) {
            if(values[i].first == min) {
                optimal = i;
            }
            else {
                break;
            }
        }
        if(values[optimal].first > v) {
            break;
        }
        v -= values[optimal].first;
        result += to_string(static_cast<long long>(values[optimal].second));
    }
    for(int i = 0; i < result.length(); i++) {
        string toConvert = "";
        toConvert += result[i];
        int allowed = costs[stoi(toConvert)];
        v += allowed;
        for(int j = 9; j >= 1; j--) {
            if(costs[j] <= v) {
                v -= costs[j];
                string a = to_string(static_cast<long long>(j));
                result[i] = a[0];
                break;
            }
        }
    }
    if(result.length() == 0) {
        cout << -1;
    }
    else {
       cout << result;
    }
    return 0;
}