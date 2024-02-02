#include <bits/stdc++.h>
using namespace std;

int n;
int a[12];
int op[12];
int cmd[4];
long long mx = -1000000000;
long long mn = 1000000000;

// k��° �����ڸ� ����
void dfs(int k) {

	if (k == n-1) {
		long long tmp = a[0];
		for (int i = 0; i < n-1; i++) {
			// cout << op[i] << ' ';
			if (op[i] == 0) { // ���ϱ��̸�
				tmp += a[i+1];
			}
			else if (op[i] == 1) {
				tmp -= a[i+1];
			}
			else if (op[i] == 2) {
				tmp *= a[i+1];
			}
			else if (op[i] == 3) {
				tmp /= a[i+1];
			}
		}
		// cout << '\n';
		mx = max<long long>(mx, tmp);
		mn = min<long long>(mn, tmp);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cmd[i] <= 0)	continue;
		op[k] = i;
		cmd[i]--;
		dfs(k + 1);
		cmd[i]++;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cmd[i];
	}
	dfs(0);
	cout << mx << '\n';
	cout << mn << '\n';
}