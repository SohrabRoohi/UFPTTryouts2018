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
    int64 leftSum = 0;
    int64 rightSum = 0;
    vector<int> values;
    for(int i = 0; i < n / 2; i++) {
        int64 val;
        cin >> val;
        values.push_back(val);
        leftSum += val;
    }
    for(int i = n / 2; i < n; i++) {
        int64 val;
        cin >> val;
        values.push_back(val);
        rightSum += val;
    }
    int index = n / 2;
    bool goRight = true;
    if(leftSum < rightSum) {
        goRight = false;
    }
    if(leftSum == rightSum) {
        cout << leftSum;
        return 0;
    }
    if(goRight) {
        while (leftSum > rightSum) {
            rightSum += values[index-1];
            leftSum -= values[index-1];
            index--;
        }
        if(leftSum == rightSum) {
            cout << leftSum;
            return 0;
        }
    }
    else {
        while (rightSum > leftSum) {
            rightSum -= values[index];
            leftSum += values[index];
            index++;
        }
        if (leftSum == rightSum) {
            cout << leftSum;
            return 0;
        }
    }
    int lastLeftSum = index - 1;
    int lastRightSum = index;
    while(leftSum != rightSum) {
        if(leftSum > rightSum) {
            leftSum -= values[lastLeftSum];
            lastLeftSum--;
        }
        else if(rightSum > leftSum) {
            rightSum -= values[lastRightSum];
            lastRightSum++;
        }
    }
    if(leftSum == rightSum) {
        cout << leftSum;
        return 0;
    }
    return 0;
}