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

#define INFY 10000000

class MonstersValley {
    public:
    vector<long long> dread; 
    vector<int> price; 
    ll dp[51][101];

    ll solve(int index, int remaining) {
        if (index == -1) {
            if (remaining >= 0)
                return 0;
            return -INFY;
        }

        if (remaining <= 0) {
            return -INFY;
        }

        ll &res = dp[index][remaining];
        if(res != -1)
            return res;

        res = -INFY;
        ll t1 = solve(index - 1, remaining - price[index]);
        if (t1 >= 0) {
            res = max(res, t1 + dread[index]);
        }

        ll t2 = solve(index - 1, remaining);
        if (t2 >= 0 && t2 >= dread[index]) {
            res = max(res, t2);
        }
        return res;

    }
    int minimumPrice(vector<long long> dread, vector<int> price) {

        // cout << endl << endl;
        this->dread = dread; 
        this->price = price; 
        memset(dp, -1, sizeof dp);

        FOR(i, 1, 100) {
            ll t = solve(sz(dread) - 1, i);
            if (t > 0) {
                return i;
            }
        }
    
        return -1;
    }
};

// CUT begin
ifstream data("MonstersValley.sample");

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

bool do_test(vector<long long> dread, vector<int> price, int __expected) {
    time_t startClock = clock();
    MonstersValley *instance = new MonstersValley();
    int __result = instance->minimumPrice(dread, price);
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
        vector<long long> dread;
        from_stream(dread);
        vector<int> price;
        from_stream(price);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(dread, price, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1388468164;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "MonstersValley (250 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
