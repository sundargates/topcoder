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

class WolfInZooDivTwo {
    public:
    int dp[301][51];
    int N;
    vector<ii> pairs;
    int solve(int index, int remaining)
    {
        if(index==N && remaining!=TOTAL_PAIRS)
            return 0;

        if(index > pairs[remaining].first)
            return 0;

        int &res = dp[index][remaining];
        if(res!=-1)
            return res;

        res = 0;
        int res1 = solve(index+1, remaining);


    }
    int count(int N, vector<string> L, vector<string> R) {
        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<string> L, vector<string> R, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    WolfInZooDivTwo *instance = new WolfInZooDivTwo();
    int __result = instance->count(N, L, R);
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
            int N = 5;
            string L[] = {
                "0 1"
            };
            string R[] = {
                "2 4"
            };
            int __expected = 27;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }
        case 1: {
            int N = 10;
            string L[] = {
                "0 4 2 7"
            };
            string R[] = {
                "3 9 5 9"
            };
            int __expected = 798;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }
        case 2: {
            int N = 100;
            string L[] = {
                "0 2 2 7 10 1",
                "3 16 22 30 33 38",
                " 42 44 49 51 57 60 62",
                " 65 69 72 74 77 7",
                "8 81 84 88 91 93 96"
            };
            string R[] = {
                "41 5 13 22 12 13 ",
                "33 41 80 47 40 ",
                "4",
                "8 96 57 66 ",
                "80 60 71 79",
                " 70 77 ",
                "99",
                " 83 85 93 88 89 97 97 98"
            };
            int __expected = 250671525;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }
        case 3: {
            int N = 3;
            string L[] = {
                "1"
            };
            string R[] = {
                "2"
            };
            int __expected = 6;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "WolfInZooDivTwo (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1373351024;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
