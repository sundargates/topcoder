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
#include <cfloat>
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
#define sqr(a) ( (a) * (a) )
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define VALUE 100

class UnionOfIntervals {
    public:

    vector<ll> lowerBound, upperBound;
    ll findindex (ll value) {

        ll res = 0;
        FORN(i, sz(lowerBound)) {

            if (lowerBound[i] > value)
                continue;

            res += abs(min (upperBound[i], value) - lowerBound[i] + 1);
        }
        // db(value);
        // db(res);
        return res - 1;
    }
    int solve(ll index) {

        ll low = INT_MAX;
        ll high = INT_MIN;

        FORN(i, sz(lowerBound)) {
            low = min(lowerBound[i], low);
            high = max(upperBound[i], high);
        }

        ll res = INT_MAX;

        FORN(i, 50) {

            ll mid = low + (high - low)/2;
            ll t = findindex(mid);
            // db(t);

            if (t < index) 
                low = mid + 1;

            else if(t > index)
                high = mid;

            else {
                res = min(res, mid);
                high = mid;
            }

        }
        return res;


    }
    int nthElement(vector<int> _lowerBound, vector<int> _upperBound, int n) {

        FORN (i, sz(_lowerBound)) {
            lowerBound.pb(_lowerBound[i]);
            upperBound.pb(_upperBound[i]);
        }

        return solve(n);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> lowerBound, vector<int> upperBound, int n, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    UnionOfIntervals *instance = new UnionOfIntervals();
    int __result = instance->nthElement(lowerBound, upperBound, n);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int lowerBound[] = {
                1, 5
            };
            int upperBound[] = {
                3, 7
            };
            int n = 4;
            int __expected = 6;
            return do_test(to_vector(lowerBound), to_vector(upperBound), n, __expected, __no);
        }
        case 1: {
            int lowerBound[] = {
                1, 3
            };
            int upperBound[] = {
                4, 5
            };
            int n = 3;
            int __expected = 3;
            return do_test(to_vector(lowerBound), to_vector(upperBound), n, __expected, __no);
        }
        case 2: {
            int lowerBound[] = {
                -1500000000
            };
            int upperBound[] = {
                1500000000
            };
            int n = 1500000091;
            int __expected = 91;
            return do_test(to_vector(lowerBound), to_vector(upperBound), n, __expected, __no);
        }

        // Your custom testcase goes here
        case 3:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "UnionOfIntervals (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 3; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379582851;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
