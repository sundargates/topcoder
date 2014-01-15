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
int dirX[] = {-1, 0, 0, 1};
int dirY[] = {0, 1, -1, 0};

class FoxAndGo {
    public:

    bool visited[21][21];

    vector<string> board;
    int N;

    void dfs(int x, int y, vector<ii> &res)
    {        
        if(x<0 || y<0 || x>=N || y>=N)
            return;

        if(board[x][y]!='o')
            return;

        if(visited[x][y])
            return;

        visited[x][y] = true;
        res.pb(mp(x, y));
        FORN(i,4)
            dfs(x+dirX[i],y+dirY[i], res);

        return;

    }
    bool canBeRemoved(vector<ii> component)
    {
        FORN(i, sz(component)) 
        {
            int x = component[i].first;
            int y = component[i].second;
            FORN(j, 4)
            {
                int newx = x+dirX[j];
                int newy = y+dirY[j];
                if(newx <0 || newy<0 || newx>=N || newy>=N)
                    continue;

                if(board[newx][newy]=='.')
                    return false;
            }
        }
        return true;
    }
    int maxKill(vector<string> _board) 
    {
        vector< vector<ii> > components;
        board = _board;
        N = sz(board);
        memset(visited, 0, sizeof visited);

        FORN(i, N)
            FORN(j, N)
                if(!visited[i][j] && board[i][j]=='o')
                {
                    vector<ii> temp;
                    dfs(i, j, temp);
                    components.pb(temp);
                }


        int result = 0;
        FORN(i,N)
            FORN(j,N)
            {
                if(board[i][j]=='.')
                {
                    int tempres = 0;
                    board[i][j] = 'x';
                    FORN(k, sz(components))
                        if(canBeRemoved(components[k]))
                            tempres += sz(components[k]);
                    result = max(result, tempres);
                    board[i][j] = '.';
                }
            }
        return result;
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
    FoxAndGo *instance = new FoxAndGo();
    int __result = instance->maxKill(board);
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
                ".....",
                "..x..",
                ".xox.",
                ".....",
                "....."
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                "ooooo",
                "xxxxo",
                "xxxx.",
                "xxxx.",
                "ooooo"
            };
            int __expected = 6;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                ".xoxo",
                "ooxox",
                "oooxx",
                "xoxox",
                "oxoox"
            };
            int __expected = 13;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                ".......",
                ".......",
                ".......",
                "xxxx...",
                "ooox...",
                "ooox...",
                "ooox..."
            };
            int __expected = 9;
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
                ".......",
                ".xxxxx.",
                ".xooox.",
                ".xo.ox.",
                ".xooox.",
                ".xxxxx.",
                "......."
            };
            int __expected = 8;
            return do_test(to_vector(board), __expected, __no);
        }
        case 5: {
            string board[] = {
                "o.xox.o",
                "..xox..",
                "xxxoxxx",
                "ooo.ooo",
                "xxxoxxx",
                "..xox..",
                "o.xox.o"
            };
            int __expected = 12;
            return do_test(to_vector(board), __expected, __no);
        }
        case 6: {
            string board[] = {
                ".......",
                "..xx...",
                ".xooox.",
                ".oxxox.",
                ".oxxxo.",
                "...oo..",
                "......."
            };
            int __expected = 4;
            return do_test(to_vector(board), __expected, __no);
        }
        case 7: {
            string board[] = {
                ".ox....",
                "xxox...",
                "..xoox.",
                "..xoox.",
                "...xx..",
                ".......",
                "......."
            };
            int __expected = 5;
            return do_test(to_vector(board), __expected, __no);
        }
        case 8: {
            string board[] = {
                "...................",
                "...................",
                "...o..........o....",
                "................x..",
                "...............x...",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "................o..",
                "..x................",
                "...............x...",
                "...................",
                "..................."
            };
            int __expected = 0;
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
    cout << "FoxAndGo (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 9; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379283382;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
