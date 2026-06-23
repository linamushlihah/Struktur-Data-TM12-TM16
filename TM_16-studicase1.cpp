#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void dijkstra(vector<vector<pair<int,int>>> &graph,
              int start,
              vector<int> &dist)
{
    int n = graph.size();

    dist.assign(n, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;

        pq.pop();

        if(d > dist[u])
            continue;

        for(auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;

                pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    cout << "===== SMART CAMPUS SYSTEM =====\n\n";

    unordered_map<string,string> akun;

    akun["5025241001"] = "12345";

    string nim,password;

    cout << "Login\n";
    cout << "NIM : ";
    cin >> nim;

    cout << "Password : ";
    cin >> password;

    if(akun[nim] == password)
        cout << "Login Berhasil\n\n";
    else
    {
        cout << "Login Gagal\n";
        return 0;
    }

    list<string> aktivitas;

    aktivitas.push_back("Login");
    aktivitas.push_back("Isi KRS");
    aktivitas.push_back("Konsultasi");

    cout << "Riwayat Aktivitas:\n";

    for(string x : aktivitas)
        cout << "- " << x << endl;

    cout << endl;

    queue<string> konsultasi;

    konsultasi.push("Andi");
    konsultasi.push("Budi");
    konsultasi.push("Citra");

    cout << "Antrian Konsultasi:\n";

    while(!konsultasi.empty())
    {
        cout << konsultasi.front() << endl;
        konsultasi.pop();
    }

    cout << endl;

    stack<string> krs;

    krs.push("IF101");
    krs.push("IF102");
    krs.push("IF103");

    cout << "Undo Mata Kuliah : "
         << krs.top()
         << endl;

    krs.pop();

    cout << endl;

    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > layanan;

    layanan.push({3,"Andi"});
    layanan.push({1,"Budi"});
    layanan.push({2,"Citra"});

    cout << "Prioritas Layanan:\n";

    while(!layanan.empty())
    {
        cout << layanan.top().second << endl;
        layanan.pop();
    }

    cout << endl;

    vector<vector<pair<int,int>>> graph(4);

    graph[0].push_back({1,5});
    graph[1].push_back({0,5});

    graph[1].push_back({2,3});
    graph[2].push_back({1,3});

    graph[2].push_back({3,2});
    graph[3].push_back({2,2});

    vector<int> dist;

    dijkstra(graph,0,dist);

    cout << "Jarak Gerbang ke Gedung Tujuan : "
         << dist[3]
         << " meter\n";

    return 0;
}
