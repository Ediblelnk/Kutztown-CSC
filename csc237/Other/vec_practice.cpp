#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vv;

  for(int i = 0; i < 50; i++) {
    vv.push_back(i);
  }

  vv[0] = -1;

  for(int i = 0; i < 50; i++) {
    cout << vv[i];
  }

  cout << endl;

}