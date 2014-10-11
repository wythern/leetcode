#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::vector<int> vIndex;
        std::vector<int> sortedNumbers(numbers);
        std::sort(sortedNumbers.begin(), sortedNumbers.end());
        std::vector<int>::iterator low = sortedNumbers.begin();
        std::vector<int>::iterator up = sortedNumbers.end();
        //low=std::lower_bound(sortedNumbers.begin(), sortedNumbers.end(), target);

        dumpInputVector(sortedNumbers);
        while(low < up &&
              *up + *low != target){
            up = findUpperIndex(low, up, target);
            low = findLowerIndex(low, up, target);
        }

        vIndex.push_back(std::find(numbers.begin(), numbers.end(), *low) - numbers.begin() + 1);
        vIndex.push_back(std::distance(std::find(numbers.rbegin(), numbers.rend(), *up), numbers.rend()));
        if (vIndex[0] > vIndex[1])
            std::swap(vIndex[0], vIndex[1]);

        return vIndex;
    }

private:
    std::vector<int>::iterator findUpperIndex(std::vector<int>::iterator first,
                                              std::vector<int>::iterator last, int target) {
        return std::upper_bound(first, last, target-*first) - 1;
    }

    std::vector<int>::iterator findLowerIndex(std::vector<int>::iterator first,
                                              std::vector<int>::iterator last, int target) {
        return std::lower_bound(first, last, target-*last);        
    }

    void dumpInputVector(vector<int>& numbers){
        for(int i = 0; i < numbers.size(); ++i)
            std::cout << numbers[i] << ",";
        std::cout << std::endl;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    int myInts[] = {0, 2, 3, 0};
    vector<int> numbers(myInts, myInts + sizeof(myInts)/sizeof(int));
    vector<int> indexs;

    indexs = s.twoSum(numbers, 0);
    std::cout << indexs[0] << "," << indexs[1] << std::endl;
}
