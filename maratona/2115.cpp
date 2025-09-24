#include <iostream>
#include <map>

using namespace std;

int main() {

  int n;
  while (scanf("%d", &n) != EOF) {
    multimap<int, int> tasks;
    for (int i = 0; i < n; i++) {
      int d, p;
      scanf("%d %d", &d, &p);
      tasks.insert({d, p});
    }

    int hora = 0;
    for (auto task : tasks) {
      if (hora < task.first)
        hora = task.first;

      hora += task.second;
    }

    printf("%d\n", hora);
  }

  return 0;
}
