#include <bits/stdc++.h>
using namespace std;

string postorder(string preorder, string inorder) {
  if (preorder.empty() || inorder.empty()) {
    return "";
  }

  char root = preorder[0];
  int index = inorder.find(root);
  string left = postorder(preorder.substr(1, index), inorder.substr(0, index));
  string right =
      postorder(preorder.substr(index + 1), inorder.substr(index + 1));

  return left + right + root;
}

int main() {

  string inorder, preorder;
  while (cin >> preorder >> inorder) {
    string x = postorder(preorder, inorder);
    cout << x << "\n";
  }

  return 0;
}
