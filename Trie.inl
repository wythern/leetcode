#include "common.h"


class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() : m_bStringEnd(false) {

	}

	~TrieNode(){
		unordered_map<char, TrieNode*>::iterator it = m_SubNodeMap.begin();
		for (; it != m_SubNodeMap.end(); ++it)
		{
			delete it->second;
		}
		m_SubNodeMap.clear();
	}

	TrieNode* getSubNode(char ch){
		unordered_map<char, TrieNode*>::iterator it = m_SubNodeMap.find(ch);
		if (it != m_SubNodeMap.end())
			return it->second;
		else
			return NULL;
	}

	TrieNode* addSubNode(char ch){
		TrieNode* pNode = new TrieNode;
		m_SubNodeMap[ch] = pNode;
		return pNode;
	}

	bool hasSubNode(){
		return !m_SubNodeMap.empty();
	}

	void stringEnd(){
		m_bStringEnd = true;
	}

	bool isStringEnd(){
		return m_bStringEnd;
	}

private:
	unordered_map<char, TrieNode*> m_SubNodeMap;
	bool m_bStringEnd;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		int i = 0;
		TrieNode* node = root;
		while (i < word.size())
		{
			TrieNode* pSubNode = node->getSubNode(word[i]);
			if (pSubNode != NULL)
				node = pSubNode;
			else
				break;
			++i;
		}

		while (i < word.size()){
			TrieNode* pSubNode = node->addSubNode(word[i]);
			++i;
			node = pSubNode;
		}

		node->stringEnd();
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		int i = 0;
		TrieNode* node = root;
		while (i < word.size())
		{
			TrieNode* pSubNode = node->getSubNode(word[i]);
			if (pSubNode == NULL)
				return false;
			node = pSubNode;
			++i;
		}

		return node->isStringEnd();
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		int i = 0;
		TrieNode* node = root;
		while (i < prefix.size())
		{
			TrieNode* pSubNode = node->getSubNode(prefix[i]);
			if (pSubNode == NULL)
				return false;
			node = pSubNode;
			++i;
		}

		return node->hasSubNode();
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(int argc, char** argv){
	Trie trie;
	trie.insert("somestring1");
	trie.insert("somestring2");
	trie.insert("somestring3");
	trie.insert("some1");
	trie.insert("some2");
	trie.insert("some3");
	trie.insert("home1");
	trie.insert("some3");
	trie.insert("home2");
	trie.insert("home3");
	cout << trie.search("home") << endl;
	cout << trie.startsWith("somes") << endl;
	return 0;
}