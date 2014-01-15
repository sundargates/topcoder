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

class LittleElephantAndPermutationDiv2 {
    public:
    int N; 
    int K; 

    int number; 
    ll dp[1<<10][101];
    int ones(int n) {
        int res = 0;
        while (n) {
            n &= (n - 1);
            res ++;
        }
        return res;
    }
    ll solve(int index, int remaining) {
        if (index == ((1<<N) - 1)) {
            if (remaining == 0)
                return 1;
            return 0;
        }

        ll &res = dp[index][remaining];
        if (res != -1)
            return res;

        res = 0;
        FORN(i, N) {
            if (!(index & (1<<i))) {
                int sel = max(ones(index) + 1, i + 1);
                res += solve(index | (1<<i), max(0, remaining - sel));
            }
        }
        return res;
    }

    ll fact(int n) {
        ll res = 1;
        FOR(i, 2, n)
            res *= i;
        return res;
    }
    long long getNumber(int N, int K) {

        this->N = N; 
        this->K = K; 

        memset(dp, -1, sizeof dp);
        ll res = solve(0, K);
        return res * fact(N);
    }
};

// CUT begin
ifstream data("LittleElephantAndPermutationDiv2.sample");

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

bool do_test(int N, int K, long long __expected) {
    time_t startClock = clock();
    LittleElephantAndPermutationDiv2 *instance = new LittleElephantAndPermutationDiv2();
    long long __result = instance->getNumber(N, K);
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
        int K;
        from_stream(K);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(N, K, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1387884059;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "LittleElephantAndPermutationDiv2 (500 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
