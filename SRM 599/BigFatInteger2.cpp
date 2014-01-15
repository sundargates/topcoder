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
typedef pair<ll,ll> ii;

class BigFatInteger2 {
    public:
    int A; 
    int B; 
    int C; 
    int D; 

    vector<ii> solve(int A) {

        vector<ii> res;
        unsigned i = 2;
        while ( (i * i) <= A) {

            unsigned count = 0;
            while (A % i == 0) {
                A /= i;
                count ++;
            }
            if (count) {
                res.pb(mp(i, count));
            }
            i++;
        }
        if (A != 1)
            res.pb(mp(A, 1));
        return res;
    }
    void display(vector<ii> v) {
        FORN(i, sz(v))  {
            db(v[i].first);
            db(v[i].second);
        }

    }
    string isDivisible(int A, int B, int C, int D) {

        this->A = A; 
        this->B = B; 
        this->C = C; 
        this->D = D; 

        vector<ii> factorsA = solve(A);
        FORN(i, sz(factorsA)) {
            factorsA[i].second *= B;
        }

        // db("");
        // display(factorsA);

        vector<ii> factorsC = solve(C);
        FORN(i, sz(factorsC)) {
            factorsC[i].second *= D;
        }

        // db("");
        // display(factorsC);

        FORN(i, sz(factorsC)) {

            int index = -1;
            FORN(j, sz(factorsA))  
                if (factorsA[j].first == factorsC[i].first) {
                    index = j;
                    break;
                }

            if (index == -1)
                return "not divisible";

            if (factorsA[index].second < factorsC[i].second)
                return "not divisible";
        }
        return "divisible";
    }
};

// CUT begin
ifstream data("BigFatInteger2.sample");

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

bool do_test(int A, int B, int C, int D, string __expected) {
    time_t startClock = clock();
    BigFatInteger2 *instance = new BigFatInteger2();
    string __result = instance->isDivisible(A, B, C, D);
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
        int A;
        from_stream(A);
        int B;
        from_stream(B);
        int C;
        from_stream(C);
        int D;
        from_stream(D);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(A, B, C, D, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1387611605;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "BigFatInteger2 (500 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
