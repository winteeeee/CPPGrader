#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;
namespace fs = filesystem;

int main() {
    vector<string> sources;

    for (const fs::directory_entry &entry : fs::recursive_directory_iterator(fs::current_path())) {
        if (entry.is_directory() && !sources.empty()) {
            // 컴파일 및 실행
            for (const string &source: sources) {
                cout << source << endl;
            }
            cout << "================" << endl;
            sources.clear();
        } else {
            string filename = entry.path().filename().string();
            if (filename.find(".cpp") != string::npos) {
                sources.push_back(filename);
            }
        }
    }

    // 컴파일 및 실행
    for (const string &source: sources) {
        cout << source << endl;
    }
    cout << "================" << endl;
    sources.clear();

    return 0;
}
