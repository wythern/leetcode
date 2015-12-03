#include "common.h"

class NumArray {
public:
	NumArray(vector<int> &nums) {
		m_nums = nums;
		m_tree = vector<int>(nums.size() + 1, 0);
		buildBIT();
	}

	void update(int pos, int val) {
		if (pos < m_nums.size())
			updateBIT(pos, val);
	}

	int sumRange(int i, int j) {
		return getSum(j + 1) - getSum(i);
	}
private:
	void buildBIT(){
		m_tree[0] = 0;
		for (size_t i = 1; i <= m_nums.size(); i++)
		{
			int idx = i - (i & (-i));
			while (idx < i)
			{
				m_tree[i] += m_nums[idx];
				++idx;
			}
		}
	}

	void updateBIT(int pos, int val){
		int idx = pos + 1;
		int diff = val - m_nums[pos];
		m_nums[pos] = val;
		while (idx < m_tree.size())
		{
			m_tree[idx] += diff;
			idx += (idx & -idx);
		}
	}

	int getSum(int pos){
		int idx = pos;
		int sum = 0;
		if (idx == 0){
			return m_tree[idx];
		}

		while (idx > 0 && idx < m_tree.size()){
			sum += m_tree[idx];
			//idx &= idx - 1;
			idx -= (idx & -idx);
		}
		return sum;
	}
private:
	vector<int> m_tree;
	vector<int> m_nums;
};


class NumArray_BAD {
public:
	NumArray_BAD(vector<int> &nums) {
		m_nums = nums;
		m_sums = vector<int>(nums.size() + 1, 0);
		for (int i = 1; i <= nums.size(); ++i){
			m_sums[i] += m_sums[i - 1] + m_nums[i - 1];
		}
	}

	void update(int i, int val) {
		m_updates[i] = val;
		return;
	}

	int sumRange(int i, int j) {
		for (map<int, int>::iterator it = m_updates.begin(); it != m_updates.end(); ++it)
		{
			if (it->first >= i && it->first <= j){
				updateImpl(it->first, it->second);
				m_updates.erase(it);
			}
		}
		return m_sums[j + 1] - m_sums[i];
	}
private:
	void updateImpl(int i, int val){
		m_nums[i] = val;
		for (int j = i + 1; j <= m_nums.size(); ++j){
			m_sums[j] += m_sums[j - 1] + m_nums[j - 1];
		}
	}

private:
	vector<int> m_sums;
	vector<int> m_nums;
	map<int, int> m_updates;
};

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		m_bInvalid = true;
		if (!matrix.empty()){
			m_matrixSum = matrix;
			m_bInvalid = false;
			calculateMatrixSum();
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (m_bInvalid)
			return 0;

		return m_matrixSum[row2][col2] - ((col1 - 1 >= 0) ? m_matrixSum[row2][col1 - 1] : 0) -
			((row1 - 1 >= 0) ? m_matrixSum[row1 - 1][col2] : 0) + ((row1 - 1 >= 0 && col1 - 1 >= 0) ? m_matrixSum[row1 - 1][col1 - 1] : 0);
	}

private:
	void calculateMatrixSum(){
		for (int i = 0; i < m_matrixSum.size(); i++)
		{
			for (int j = 0; j < m_matrixSum[0].size(); j++)
			{
				m_matrixSum[i][j] += ((i - 1 >= 0) ? m_matrixSum[i - 1][j] : 0) + ((j - 1 >= 0) ? m_matrixSum[i][j - 1] : 0) -
					((i - 1 >= 0 && j - 1 >= 0) ? m_matrixSum[i - 1][j - 1] : 0);
			}
		}
	}

private:
	vector<vector<int>> m_matrixSum;
	bool m_bInvalid;
};

int main(int argc, char** argv){
	vector<int> vA;
	NumArray numArray(vA);
	cout << numArray.sumRange(0, 2) << endl;
	numArray.update(0, 2);
	cout << numArray.sumRange(0, 2) << endl;
	return 0;
}
