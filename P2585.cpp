#include <bits/stdc++.h>
using namespace std;

struct Color {
    int gmin, gmax;
};

class Node {
    public:
    Node *left, *right;
    int idx;

    Color red, blue, green;

    Node(Node *l, Node *r, int i) : left(l), right(r), idx(i) { };

    int getGmax() {
        return max(red.gmax, max(green.gmax, blue.gmax));
    }

    int getGmin() {
        return min(red.gmin, min(green.gmin, blue.gmin));
    }
};

int main() {
    int cnt = 0;

    string s = "1122002010";
    cin >> s;


    function<pair<Node*, int>(int)> parse = [&](int l) {
        int num = s[l] - '0';

        Node *u = new Node(nullptr, nullptr, cnt++);
        int r;

        if (num == 0) {
            r = l + 1;
        } else if (num == 1) {
            auto ret = parse(l + 1);
            u->left = ret.first;
            r = ret.second;
        } else {
            auto ret = parse(l + 1);
            u->left = ret.first;
            auto rret = parse(ret.second);
            u->right = rret.first;
            r = rret.second;
        }

        return pair<Node*, int>(u, r);
    };

    Node *root = parse(0).first;

    // queue<Node*> q;
    // q.push(root);
    // while (!q.empty()) {
    //     auto u = q.front();
    //     q.pop();
    //     if (u == nullptr) continue;
    //     cout << u->idx << endl;
    //     q.push(u->left);
    //     q.push(u->right);
    // }

    function<void(Node*)> dfs = [&](Node *root) {
        if (root == nullptr) return;

        auto left = root->left, right = root->right;

        // boundary
        if (left == nullptr && right == nullptr) {
            root->red.gmax = root->red.gmin = 0;
            root->blue.gmax = root->blue.gmin = 0;
            root->green.gmax = root->green.gmin = 1;
            return;
        }
        
        dfs(left);
        dfs(right);
        
        if (left != nullptr && right != nullptr) {
            root->green.gmin = min(left->red.gmin + right->blue.gmin, left->blue.gmin + right->red.gmin) + 1;
            root->green.gmax = max(left->red.gmax + right->blue.gmax, left->blue.gmax + right->red.gmax) + 1;

            root->blue.gmin = min(left->red.gmin + right->green.gmin, left->green.gmin + right->red.gmin);
            root->blue.gmax = max(left->red.gmax + right->green.gmax, left->green.gmax + right->red.gmax);

            root->red.gmin = min(left->blue.gmin + right->green.gmin, left->green.gmin + right->blue.gmin);
            root->red.gmax = max(left->blue.gmax + right->green.gmax, left->green.gmax + right->blue.gmax);
        } else {
            Node *ptr = (left != nullptr) ? left : right;

            root->green.gmin = min(ptr->red.gmin, ptr->blue.gmin) + 1;
            root->green.gmax = max(ptr->red.gmax, ptr->blue.gmax) + 1;

            root->blue.gmin = min(ptr->red.gmin, ptr->green.gmin);
            root->blue.gmax = max(ptr->red.gmax, ptr->green.gmax);

            root->red.gmin = min(ptr->blue.gmin, ptr->green.gmin);
            root->red.gmax = max(ptr->blue.gmax, ptr->green.gmax);
        }
    };

    dfs(root);

    cout << root->getGmax() << " " << root->getGmin() << endl;

    return 0;
}
/*



*/