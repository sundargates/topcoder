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

class FoxAndGomoku {
    public:
    string win(vector<string> board) {

        int N = sz(board);
        int matrix[N][N][4];
        memset(matrix, 0, sizeof matrix);

        FORN (i, N)
            FORN (j, N)
            {
                if (board[i][j]=='o') {
                    matrix[i][j][0] = (i-1>=0)?matrix[i-1][j][0] + 1 : 1;
                    matrix[i][j][1] = (j-1>=0)?matrix[i][j-1][1] + 1 : 1;
                    matrix[i][j][2] = (i-1>=0) && (j-1>=0)?matrix[i-1][j-1][2] + 1 : 1;
                    matrix[i][j][3] = (i-1>=0) && (j+1<N)?matrix[i-1][j+1][3] + 1 : 1;
                }
                else {
                    matrix[i][j][0] = 0;
                    matrix[i][j][1] = 0;
                    matrix[i][j][2] = 0;
                    matrix[i][j][3] = 0;
                }

            }

        FORN(i,N)
            FORN(j,N)
                FORN(k,4)
                    if(matrix[i][j][k]==5)
                        return "found";

        return "not found";
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FoxAndGomoku *instance = new FoxAndGomoku();
    string __result = instance->win(board);
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
                "....o.",
                "...o..",
                "..o...",
                ".o....",
                "o.....",
                "......"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                "oooo.",
                ".oooo",
                "oooo.",
                ".oooo",
                "....."
            };
            string __expected = "not found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "oooo.",
                ".oooo",
                "oooo.",
                ".oooo",
                "....o"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "o.....",
                ".o....",
                "..o...",
                "...o..",
                "....o.",
                "......"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
                "o....",
                "o.o..",
                "o.o.o",
                "o.o..",
                "o...."
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 5: {
            string board[] = {
                "..........",
                "..........",
                "..oooooo..",
                "..o.......",
                "..o.......",
                "..oooooo..",
                ".......o..",
                ".......o..",
                "..oooooo..",
                ".........."
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 6: {
            string board[] = {
                "..........",
                "..........",
                "..oooo.o..",
                "..o.......",
                "..o.......",
                "..o.oooo..",
                ".......o..",
                ".......o..",
                "..oooo.o..",
                ".........."
            };
            string __expected = "not found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 7: {
            string board[] = {
                "ooooo",
                "ooooo",
                "ooooo",
                "ooooo",
                "ooooo"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 8: {
            string board[] = {
                ".....",
                ".....",
                ".....",
                ".....",
                "....."
            };
            string __expected = "not found";
            return do_test(to_vector(board), __expected, __no);
        }

        // Your custom testcase goes here
        case 9:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FoxAndGomoku (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 9; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379233734;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
