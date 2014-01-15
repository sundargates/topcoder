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
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

class ConvertibleStrings {
    public:

    string A, B;
    int solve(map<char, char> char_map)
    {
        int res = 0;
        FORN(i,A.length())
            if(A[i]!=char_map[B[i]])
                res ++;

        return res;
    }
    bool taken[9];
    int permute(int index, map<char, char> &char_map)
    {
        if(index == 9)
            return solve(char_map);

        int result = INT_MAX;
        FORN(i, 9)
            if(!taken[i])
            {
                taken[i] = true;
                char_map[(char)(index+'A')] = (char)(i + 'A');
                result = min(result, permute(index+1, char_map));
                taken[i] = false;
            }

        return result;
    }
    int leastRemovals(string _A, string _B) {

        A = _A;
        B = _B;

        memset(taken, 0, sizeof taken);
        map<char, char> temp;
        return permute(0, temp);

        // return 0;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string A, string B, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ConvertibleStrings *instance = new ConvertibleStrings();
    int __result = instance->leastRemovals(A, B);
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
            string A = "DD";
            string B = "FF";
            int __expected = 0;
            return do_test(A, B, __expected, __no);
        }
        case 1: {
            string A = "AAAA";
            string B = "ABCD";
            int __expected = 3;
            return do_test(A, B, __expected, __no);
        }
        case 2: {
            string A = "AAIAIA";
            string B = "BCDBEE";
            int __expected = 3;
            return do_test(A, B, __expected, __no);
        }
        case 3: {
            string A = "ABACDCECDCDAAABBFBEHBDFDDHHD";
            string B = "GBGCDCECDCHAAIBBFHEBBDFHHHHE";
            int __expected = 9;
            return do_test(A, B, __expected, __no);
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
    cout << "ConvertibleStrings (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379380435;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
