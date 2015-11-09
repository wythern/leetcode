#include "common.h"

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty())
			return vector<Interval>();

		std::sort(intervals.begin(), intervals.end(), FunctionLT());

		vector<Interval> vMergedInvl;
		vector<Interval>::iterator itInterval = intervals.begin();
		int mark = itInterval->end;
		Interval prevInvl(*itInterval);
		++itInterval;
		while (itInterval != intervals.end())
		{
			if (mark >= itInterval->end){
				++itInterval;
				continue;
			}

			if (mark < itInterval->start){
				vMergedInvl.push_back(Interval(prevInvl.start, prevInvl.end));
				mark = itInterval->end;
				prevInvl = *itInterval;
				++itInterval;
				continue;
			}

			if (mark >= itInterval->start && mark < itInterval->end){
				while (mark < itInterval->end) ++mark;
				//vMergedInvl.push_back(Interval(prevInvl.start, mark));
				prevInvl.end = mark;
				++itInterval;
			}
		}

		vMergedInvl.push_back(prevInvl);

		return vMergedInvl;
	}

	class FunctionLT{
	public:
		const bool operator () (const Interval& lhs, const Interval& rhs){
			return lhs.start < rhs.start;
		}
	};


	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> insIntervals(intervals);
		vector<Interval>::iterator itInterval = insIntervals.begin();
		while (itInterval != insIntervals.end())
		{
			if (itInterval->start > newInterval.start)
				break;
			++itInterval;
		}
		insIntervals.insert(itInterval, newInterval);

		vector<Interval> vMergedInvl;
		itInterval = insIntervals.begin();
		int mark = itInterval->end;
		Interval prevInvl(*itInterval);
		++itInterval;
		while (itInterval != insIntervals.end())
		{
			if (mark >= itInterval->end){
				++itInterval;
				continue;
			}

			if (mark < itInterval->start){
				vMergedInvl.push_back(Interval(prevInvl.start, prevInvl.end));
				mark = itInterval->end;
				prevInvl = *itInterval;
				++itInterval;
				continue;
			}

			if (mark >= itInterval->start && mark < itInterval->end){
				while (mark < itInterval->end) ++mark;
				//vMergedInvl.push_back(Interval(prevInvl.start, mark));
				prevInvl.end = mark;
				++itInterval;
			}
		}

		vMergedInvl.push_back(prevInvl);
		return vMergedInvl;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[][2] = {
		{ 10, 14 },
		{ 15, 16 },
		{ 17, 23 },
		{ 30, 50 },
		{ 51, 60 },
		{ 61, 62 } };

	vector<Interval> vInvl;
	for (size_t i = 0; i < sizeof(A)/sizeof(A[2]); i++)
	{
		vInvl.push_back(Interval(A[i][0], A[i][1]));
	}

	Interval newIvl(59, 61);
	//vInvl = s.merge(vInvl);
	for (size_t i = 0; i < vInvl.size(); i++)
	{
		cout << "[" << vInvl[i].start << ", " << vInvl[i].end << "]" << endl;
	}
	cout << "[-----------------------------------------------------]" << endl;
	vInvl = s.insert(vInvl, newIvl);
	for (size_t i = 0; i < vInvl.size(); i++)
	{
		cout << "[" << vInvl[i].start << ", " << vInvl[i].end << "]" << endl;
	}

	return 0;

}


