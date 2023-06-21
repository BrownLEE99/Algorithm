#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
#include <string.h>
#include <vector>
using namespace std;

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	unordered_set <string> s;
	char tmp[11];
	for (int i = 0; i < n; i++) {
		scanf("%s", &tmp);
		string ss = tmp;
		s.insert(ss);
	}
	char str[101];
	for (int i = 0; i < m; i++) {
		scanf("%s", str);
		char* tk;
		tk = strtok(str, ",");
		while (tk != NULL) {
			string ss = tk;
			s.erase(tk);
			tk = strtok(NULL, ",");
		}
		printf("%d\n", s.size());
	}
}