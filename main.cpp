//#include <iostream> //dfs
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//vector<vector<int>> bd;
//vector<int> moleCnt;
//int dy[4] = {0, 1, 0, -1};
//int dx[4] = {1, 0, -1, 0};
//
//bool safe(int y, int x)
//{
//    return 0 <= y && y < n && 0 <= x && x < n;
//}
//
//void print()
//{
//    cout << endl;
//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < n; j++)
//        {
//            cout.width(2);
//            cout.fill('0');
//            cout << fixed << bd[i][j] << " ";
//
//            //printf("%02d ", bd[i][j]);
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//void dfs(int y, int x, int no)
//{
//    moleCnt[no]++;
//    bd[y][x] = no+11;
//
//    for(int i = 0; i < 4; i++)
//    {
//        int yy = y + dy[i];
//        int xx = x + dx[i];
//
//        if(safe(yy, xx) && bd[yy][xx] == 1)
//        {
//            dfs(yy, xx, no);
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;
//    bd.resize(n);
//    for(auto& v : bd) v.resize(n);
//
//    int no = 0;
//    for(int y = 0; y < n; y++)
//    {
//        for(int x = 0; x < n; x++)
//        {
//            cin >> bd[y][x];
//        }
//    }
//
//    for(int y = 0; y < n; y++)
//    {
//        for(int x = 0; x < n; x++)
//        {
//            if(bd[y][x] == 1)
//            {
//                moleCnt.push_back(0);
//                dfs(y, x, no++);
//            }
//        }
//    }
//
//    print();
//
//
//    cout << no << endl;
//    sort(moleCnt.begin(), moleCnt.end(), greater<int>());
//
//    for(int i = 0; i < no; i++) cout << moleCnt[i] << endl;
//}

#include <iostream> //bfs
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> bd;
vector<int> moleCnt;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool safe(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}

void print()
{
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout.width(2);
            cout.fill('0');
            cout << fixed << bd[i][j] << " ";

            //printf("%02d ", bd[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(int y, int x, int no)
{
    queue<pair<int, int>> q;

    bd[y][x] = no+11;
    q.push({y, x});

    while(q.size())
    {
        auto p = q.front();
        y = p.first;
        x = p.second;
        q.pop();

        moleCnt[no]++;

        for(int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if(safe(yy, xx) && bd[yy][xx] == 1)
            {
                bd[yy][xx] = no+11;
                q.push({yy, xx});
            }
        }
    }
}

int main()
{
    cin >> n;
    bd.resize(n);
    for(auto& v : bd) v.resize(n);

    int no = 0;
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            cin >> bd[y][x];
        }
    }

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            if(bd[y][x] == 1)
            {
                moleCnt.push_back(0);
                bfs(y, x, no++);
            }
        }
    }

    print();


    cout << no << endl;
    sort(moleCnt.begin(), moleCnt.end(), greater<int>());

    for(int i = 0; i < no; i++) cout << moleCnt[i] << endl;
}
