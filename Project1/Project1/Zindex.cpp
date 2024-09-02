#include <iostream>
#include <string>
#include <vector>

std::vector<int> ZIndex(std::string s) {
	int n = s.size();
	std::vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (i > r) {
			l = i;
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];
			r = l + z[i] - 1;
		}
		else {
			z[i] = std::min(r - i + 1, z[i - l]);
		}
	}
	return z;
}


void ttmain() {
	std::string a = "aaaabaa";
	std::vector<int> arr = ZIndex(a);
	for (int i = 0; i < a.size(); i++) {
		std::cout<<arr[i]<<" ";
	}
}