#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	char ch[] = {'1', '2', '3'};
	vector<char> v(n + 1, '0');

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int un = (v[a] == '0') + (v[b] == '0') + (v[c] == '0');
		// cout << v[a] << v[b] << v[c] << ' ';
		if (un == 3) {
			v[a] = '1';
			v[b] = '2';
			v[c] = '3';
		}
		else if (un == 2) {
			int f = 0;
			if (v[a] != '0') { f = v[a] - '0'; v[b] = ch[f++ % 3]; v[c] = ch[f % 3]; }
			else if (v[b] != '0') { f = v[b] - '0'; v[a] = ch[f++ % 3]; v[c] = ch[f % 3]; }
			else if (v[c] != '0') { f = v[c] - '0'; v[a] = ch[f++ % 3]; v[b] = ch[f % 3]; }
		}
		else if (un == 1) {
			if (v[a] == '0') v[a] = ((v[b] - '1' + v[c] - '1') % 3) + '1';
			else if (v[b] == '0') v[b] = ((v[a] - '1' + v[c] - '1') % 3) + '1';
			else if (v[c] == '0') v[c] = ((v[b] - '1' + v[a] - '1') % 3) + '1';
		}
		// cout << v[a] << v[b] << v[c] << ' ' << un << '\n';
	}

	for (int i = 1; i <= n; i++) cout << v[i] << ' ';
}
