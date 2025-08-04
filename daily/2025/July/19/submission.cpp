#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  string label;
  unordered_map<string, Node *> mp;
  bool last;

  Node(const string &label, const bool last) : label(label), last(last) {}
};

class Solution {
private:
  Node *root = new Node("/", false);
  vector<string> ret;

  void add_folder_conditionally(string &f) {
    const uint8_t n = static_cast<uint8_t>(f.size());
    string part = "";
    Node *curr = root;
    for (uint8_t i = 1; i < n; i++) {
      if (f[i] != '/') {
        part += f[i];
      }

      if (f[i] == '/' || i == n - 1) {
        if (curr->mp.find(part) == curr->mp.end()) {
          curr->mp[part] = new Node(part, false);
        }

        if (curr->mp[part]->last) {
          return;
        }

        curr = curr->mp[part];
      }
    }

    curr->last = true;
    ret.push_back(f);
  }

public:
  vector<string> removeSubfolders(vector<string> &folders) {
    sort(folders.begin(), folders.end());
    for (string &f : folders) {
      add_folder_conditionally(f);
    }

    return ret;
  }
};