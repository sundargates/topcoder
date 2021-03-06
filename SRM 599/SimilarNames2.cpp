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

class SimilarNames2 {
    public:
    vector<string> names; 
    int L; 

    ll dp[51][51];
    ll anotherdp[51];
    ll fact(unsigned n) {

        if (n == 0 || n == 1)
            return 1;

        ll &res = anotherdp[n];
        if (res != -1)
            return res;

        res = n * fact(n-1);
        res %= LIMIT;
        return res;
    }

    ll solve(int index, int previous) {

        if (index >= sz(names))
            return 1;

        ll &res = dp[index][previous];
        if (res != -1)
            return res;

        res = 0;
        if (index <= L - 1) {
            FORN(i, sz(names)) {
                if (i != previous) {
                    if (names[i].find(names[previous]) == 0) {
                        res += solve(index + 1, i);
                        res %= LIMIT;
                    }
                }
            }
        } else {
            unsigned remaining = sz(names) - index;
            res += fact(remaining);
            res %= LIMIT;
        }
        return res;
    }
    int count(vector<string> names, int L) {

        memset(dp, -1, sizeof dp);
        memset(anotherdp, -1, sizeof anotherdp);

        this->names = names; 
        this->L = L; 

        ll res = 0;
        FORN(i, sz(names)) {
            res += solve(1, i);
            res %= LIMIT;
        }
    
        return (int)res;
    }
};

// CUT begin
ifstream data("SimilarNames2.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(vector<string> names, int L, int __expected) {
    time_t startClock = clock();
    SimilarNames2 *instance = new SimilarNames2();
    int __result = instance->count(names, L);
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
        vector<string> names;
        from_stream(names);
        int L;
        from_stream(L);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(names, L, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1387606849;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 950 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "SimilarNames2 (950 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
