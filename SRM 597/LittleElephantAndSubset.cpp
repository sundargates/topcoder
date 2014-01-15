#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

#include <sstream>
#include <typeinfo>
#include <fstream>
using namespace std;

#define FOR(i,x,y) for(int i=x; i<=y; i++)
#define FORN(i,n) FOR(i,0,(n-1))
#define FORE(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define db(x) cout << (#x) << " = " << x << endl;
#define CLR(x) memset(x,0,sizeof(x));
#define sz(x) ((int)x.size())
#define mp make_pair
#define pb push_back
#define re return
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define LIMIT 1000000007

class LittleElephantAndSubset {
    public:
    int N; 

    int getNumber(int N) {

        this->N = N; 
        ll dp[1<<10][2];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;

        FOR(i, 1, N) {

            // db(dp[2][1]);
            // db (i);
            FORN(index, (1<<10)) {
                dp[index][i%2] = dp[index][(i+1)%2];
            }
            int rep = 0;
            int j = i;
            bool success = true;
            while(j) {
                if ( (rep ^ (1 << (j % 10)) ) < rep) {
                    success = false;
                    break;
                }
                rep |= (1 << (j % 10));
                j /= 10;
            }
            if (!success) {
                continue;
            }


            FORN(index, (1<<10)) {

                if ((index ^ rep) < index) {
                    // dp[index][i%2] = dp[index][(i+1)%2];
                    continue;
                }

                // db(index);
                // db((index|rep));
                // db(((i+1)%2));
                // db((i%2));
                // db(dp[index][((i+1)%2)]);
                dp[(index | rep)][i%2] += dp[index][((i+1)%2)];
                // dp[(index | rep)][i%2] %= LIMIT;
                // db(dp[index | rep][i%2]);
            }

        }

        ll res = 0;
        FOR(i, 1, ((1<<10) - 1)) {
            res += dp[i][N%2];
            if (res > LIMIT)
                res %= LIMIT;
        }
    
        return (int)res;
    }
};

// CUT begin
ifstream data("LittleElephantAndSubset.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int N, int __expected) {
    time_t startClock = clock();
    LittleElephantAndSubset *instance = new LittleElephantAndSubset();
    int __result = instance->getNumber(N);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

void run_test(const set<int> &case_set) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int N;
        from_stream(N);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(N, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1387674865;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "LittleElephantAndSubset (1000 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
