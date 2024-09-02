#include <iostream>
#include <string>

struct Trie {
	Trie* childLetter[26];
	bool EndOfWord;

	Trie() {
		EndOfWord = false;
		for (int i = 0; i < 26; i++) {
			childLetter[i] = NULL;
		}
	}

};


Trie* AddToTrie(Trie* root, std::string word) {
	if (word == "") {
		root->EndOfWord = true;
		root = new(Trie);
		return root;
	}
	std::string F = word.substr(0, 1);
	std::string Tail = word.substr(1, word.size() - 1);
	char f = F[0];
	root->childLetter[f - 'a'] = new(Trie);
	return AddToTrie(root->childLetter[f - 'a'], Tail);
}


Trie* insert(Trie* root, std::string word) {
	if (word == "") {
		root->EndOfWord = true;
		return root;
	}
	std::string F = word.substr(0, 1);
	std::string Tail = word.substr(1, word.size() - 1);
	char f = F[0];

	if (root->childLetter[f - 'a'] == NULL) {
		AddToTrie(root, word);
	}
	else {
		insert(root->childLetter[f - 'a'], Tail);
	}
}

bool search(Trie* root, std::string word) {
	if (word == "") {
		return root->EndOfWord;
	}
	std::string F = word.substr(0, 1);
	std::string Tail = word.substr(1, word.size() - 1);
	char f = F[0];

	if (root->childLetter[f - 'a'] == NULL) {
		return false;
	}
	else {
		return search(root->childLetter[f - 'a'], Tail);
	}
}
void tmain() {
	std::string word = "bol";
	std::string wor = "ballen";
	Trie* a = new(Trie);

	insert(a, word);
	insert(a, wor);
	std::cout << search(a, "bo");
}