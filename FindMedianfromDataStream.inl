#include "common.h"

class MedianFinder {
public:

	// Adds a number into the data structure.
	void addNum(int num) {
		if (!m_leftHalf.empty() && num < m_leftHalf.top())
			m_leftHalf.push(num);
		else
			m_rightHalf.push(num);

		if (m_leftHalf.size() > m_rightHalf.size()){
			m_rightHalf.push(m_leftHalf.top());
			m_leftHalf.pop();
		} else if (m_rightHalf.size() > m_leftHalf.size() + 1){
			m_leftHalf.push(m_rightHalf.top());
			m_rightHalf.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (m_leftHalf.size() == m_rightHalf.size())
			return (m_leftHalf.top() + m_rightHalf.top()) / 2.0f;
		else
			return m_rightHalf.top();
	}

private:
	std::priority_queue<int, std::vector<int>, std::less<int>> m_leftHalf;
	std::priority_queue<int, std::vector<int>, std::greater<int>> m_rightHalf;
};


int main(int argc, char** argv){
	MedianFinder s;
	s.addNum(2);
	s.addNum(3);
	s.addNum(4);
	cout << s.findMedian() << endl;
	s.addNum(5);
	cout << s.findMedian() << endl;
	return 0;
}
