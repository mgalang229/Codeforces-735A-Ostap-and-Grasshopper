#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int id = 0;
	// find the index of the grasshopper
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G') {
			id = i;
		}
	}
	string tmp1 = s;
	string tmp2 = s;
	// if the grasshopper encounters a '#', break the loop
	// mark the jump locations of the grasshopper to the right
	for (int i = id; i < n; i += k) {
		if (s[i] == '#') {
			break;
		} 
		tmp1[i] = 'G';
	}
	// mark the jump locations of the grasshopper to the left
	for (int i = id; i >= 0; i -= k) {
		if (s[i] == '#') {
			break;
		} 
		tmp2[i] = 'G';
	}
	bool can_jump = false;
	// check if the grasshopper and the target have the same index
	for (int i = 0; i < n; i++) {
		if ((tmp1[i] == 'G' && s[i] == 'T') || (tmp2[i] == 'G' && s[i] == 'T')) {
			can_jump = true;
		}
	}
	cout << (can_jump ? "YES" : "NO") << '\n';
	return 0;	
}
