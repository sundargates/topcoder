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
#define MOD 1000000007

class FoxAndShogi {
    public:
    int dp[51][51];
    vector<string> board;
    int N;

    vector< pair<int, char> > find_elements(int col)
    {

        vector< pair<int, char> > res;
        FORN (i, N)
            if (board[i][col] != '.')
                res.pb(mp(i, board[i][col]));

        return res;
    }
    int solve(int pos, int row_limit, vector< pair<int, char> > elements)
    {
        if (pos == sz(elements))
            return 1;

        int &res = dp[pos][row_limit];
        if(res!=-1)
            return res;

        if (elements[pos].second == 'U' && row_limit > elements[pos].first)
            return res = 0;

        if (row_limit >= N)
            return res = 0;

        int start_pos = (elements[pos].second == 'U') ? row_limit : max(elements[pos].first, row_limit);
        int end_pos = (elements[pos].second == 'U') ? elements[pos].first : N - 1;

        res = 0;
        FOR (i, start_pos, end_pos)
        {
            res += solve(pos+1, i+1, elements);
            res %= MOD;
        }
        // db("");
        // db(row_limit);
        // db(res);
        // db(pos);
        return res;
    }
    int differentOutcomes(vector<string> _board) {

        board = _board;
        N = sz(board);
        ull res = 1;
        FORN (i, N) {

            memset(dp, -1, sizeof dp);
            res *= solve(0, 0, find_elements(i));
            res %= MOD;

        }
        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FoxAndShogi *instance = new FoxAndShogi();
    int __result = instance->differentOutcomes(board);
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
            string board[] = {
                ".D.",
                "...",
                "..."
            };
            int __expected = 3;
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                ".D.",
                "...",
                ".U."
            };
            int __expected = 3;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "DDDDD",
                ".....",
                ".....",
                ".....",
                "....."
            };
            int __expected = 3125;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "DDDDD",
                "U....",
                ".U...",
                "..U..",
                "...U."
            };
            int __expected = 900;
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
                "....D..",
                "U....D.",
                "D.D.U.D",
                "U.U...D",
                "....U..",
                "D.U...D",
                "U.U...."
            };
            int __expected = 2268;
            return do_test(to_vector(board), __expected, __no);
        }
        case 5: {
            string board[] = {
                "DDDDDDDDDD",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                ".........."
            };
            int __expected = 999999937;
            return do_test(to_vector(board), __expected, __no);
        }
        case 6: {
            string board[] = {
                "..",
                ".."
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FoxAndShogi (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379239096;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
