#include <iostream>
#include <vector>
#include <string>

std::pair<std::vector<int>, std::vector<int>> Manaker(std::string s) {
	std::vector<int> resOdd(s.size(), 1);
	std::vector<int> resEven(s.size(), 0);
	for (int i = 1; i < s.size(); ++i) {
		while (i - resOdd[i] >= 0 && i + resOdd[i] < s.size() && s[i - resOdd[i]] == s[i + resOdd[i]])
			++resOdd[i];

		while (i - resEven[i] >= 0 && i + resEven[i] < s.size() && s[i - resEven[i]-1] == s[i + resEven[i]])
			++resEven[i];
	}
	std::pair<std::vector<int>, std::vector<int>> res(resOdd, resEven);
	return res;
}
int main() {
	std::pair<std::vector<int>, std::vector<int>> res = Manaker("cbaabc");
	for (auto i : res.first) {
		std::cout << res.first[i] <<" ";
	}
	std::cout << std::endl;
	for (auto i : res.second) {
		std::cout << res.second[i] << " ";
	}
}