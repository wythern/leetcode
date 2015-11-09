#include "common.h"

#if 0
void do_sth(TreeNode* root){
	return;
}

void traversal_preorder(TreeNode* root){
	if (root == NULL)
		return;

	traversal_preorder(root->left);
	do_sth(root);
	traversal_preorder(root->right);
}

int main(int argc, char** argv){
	int A[] = { 1, 2, 3, 4, 5, 6, 7 };
	TreeNode node(A, sizeof(A) / sizeof(int));
	traversal_preorder(&node);
	return 0;
}
#endif

#if 1
// C++ program to find length of the shortest chain
// transformation from source to target
using namespace std;

// To check if strings differ by exactly one character
bool isadjacent(string& a, string& b)
{
	int count = 0;  // to store count of differences
	int n = a.length();

	// Iterate through all characters and return false
	// if there are more than one mismatching characters
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) count++;
		if (count > 1) return false;
	}
	return count == 1 ? true : false;
}

// A queue item to store word and minimum chain length
// to reach the word.
struct QItem
{
	string word;
	int len;
};

// Returns length of shortest chain to reach 'target' from 'start'
// using minimum number of adjacent moves.  D is dictionary
int shortestChainLen(string& start, string& target, set<string> &D)
{
	// Create a queue for BFS and insert 'start' as source vertex
	queue<QItem> Q;
	QItem item = { start, 1 };  // Chain length for start word is 1
	Q.push(item);

	set<string> nextD(D);
	// While queue is not empty
	while (!Q.empty())
	{
		// Take the front word
		QItem curr = Q.front();
		Q.pop();

		// Go through all words of dictionary
		for (decltype(nextD.begin()) it = nextD.begin(); it != nextD.end(); ++it)
		{
			// Process a dictionary word if it is adjacent to current
			// word (or vertex) of BFS
			string temp = *it;
			if (isadjacent(curr.word, temp))
			{
				// Add the dictionary word to Q
				item.word = temp;
				item.len = curr.len + 1;
				Q.push(item);

				// Remove from dictionary so that this word is not
				// processed again.  This is like marking visited
				D.erase(temp);

				// If we reached target
				if (temp == target)
					return item.len;
				// If we reached the end of dict-path
				if (isadjacent(target, temp))
					return item.len + 1;
			}
		}

		nextD = D;
	}
	return 0;
}

// Driver program
int main()
{
	// make dictionary
	set<string> D;
	D.insert("poon");
	D.insert("plee");
	D.insert("same");
	D.insert("poie");
	D.insert("plie");
	D.insert("poin");

	string start = "toon";
	string target = "plea";
	cout << "Length of shortest chain is: "
		<< shortestChainLen(start, target, D);
	return 0;
}
#endif