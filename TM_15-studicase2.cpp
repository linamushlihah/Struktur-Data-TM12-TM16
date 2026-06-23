#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

int main()
{
    cout << "===== IMPLEMENTASI STRUKTUR DATA =====\n\n";

    stack<string> undo;

    undo.push("Tambah A");
    undo.push("Tambah B");

    cout << "Undo : "
         << undo.top()
         << endl;

    undo.pop();

    cout << endl;

    queue<string> pasien;

    pasien.push("Andi");
    pasien.push("Budi");
    pasien.push("Citra");

    cout << "Pasien Dilayani : "
         << pasien.front()
         << endl;

    pasien.pop();

    cout << endl;

    list<string> playlist;

    playlist.push_back("Lagu A");
    playlist.push_back("Lagu B");
    playlist.push_back("Lagu C");

    cout << "Playlist:\n";

    for(string lagu : playlist)
        cout << lagu << endl;

    cout << endl;

    unordered_map<string,string> login;

    login["fajar"] = "123";

    cout << "Hash Table Login:\n";

    cout << login["fajar"]
         << endl;

    cout << endl;

    priority_queue<int> ranking;

    ranking.push(1000);
    ranking.push(800);
    ranking.push(600);

    cout << "Produk Terlaris : "
         << ranking.top()
         << endl;

    return 0;
}