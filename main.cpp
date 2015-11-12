#define __RUNNING_ZONE__ 1
#define __AC_ZONE__ 0
#define __NOT_AC_ZONE__ 0

#if __NOT_AC_ZONE__
#include "Palindrome_Partitioning.cpp" // NOT AC
#endif

#if __AC_ZONE__
#include "Sum Root to Leaf Numbers.cpp"
#include "Surrounded_Regions.cpp" // AC
#include "binary-tree-right-side-view.cpp" 
#include "CloneGraph.cpp" //AC
#include "canCompleteCircuit.cpp"
#include "copyRandomList.cpp"
#include "reorderList.cpp"
#include "listTraversal.cpp"
#include "evalRPN.cpp"
#include "reverseWords.cpp"
#include "findMin.cpp"
#include "minStack.cpp"
#include "getIntersectionNode.cpp"
#include "minStack.cpp"
#include "findPeakElement.cpp" //REFINE
#include "LargestNumber.cpp" //REFINE
#include "ExcelTitle.cpp"
#include "fraction2decimal.cpp"
#include "versionCompare.cpp"
#include "numberOfIsland.inl"
#include "RepeatedDNASequences.inl"
#include "maxProductSubarray.inl"
#include "minimunSizeSubArray.inl"
#include "binaryPath.inl"
#include "word_ladder.cpp"
#include "Trie.inl"
#include "search_rotated_array.cpp"
#include "RotateImage.inl"
#include "SubstringwithConcatenationofAllWords.inl"
#include "mergeIntervals.inl"
#include "TextJustification.cpp"
#include "SingleNumber.cpp"
#include "traversal_binary_tree.cpp"
#include "MoveZeros.inl"
#include "MissingNumber.inl"
#include "PerfectSquares.inl"
#include "SudokuSolver.inl"
#include "Candy.inl" // back-n-forth method, learn from others.
#include "LargestRectangleinHistogram.inl" // NOT AC, should have less O(n^2) solution. AC-ed, learn from others.
#include "cycleLinkedList.cpp" // AC, but not very optimized.
#include "trailingZeroes.cpp" // learn from others, using number theory: N = Pi(pi ^ qi) while p is prime number factor, and q is the index number.
#include "InterleavingString.inl" //DP vs BF
#include "wordBreak.inl"
#include "CourseSchedule.inl"
#include "wordPattern.inl"
#include "ProductOfArrayExceptSelf.inl" // NOT AC!!! no O(N) solution was found. Learn from others.
#include "Longest_Increasing_Subsequence.inl"
#include "GameofLife.inl"
#include "combination_sum.cpp"
#include "kthLargestElement.inl" // partition has so many issues!
#include "removeInvalidParentheses.inl" //DFS!
#include "ScrambleString.inl" // DO you have brain?? why can't you solve this??? WHYYYYYYY???
#include "SlidingWindow.inl" // pasting method, learn a index operation from web.
#include "Search2DMatrix.inl"
#include "TheSkylineProblem.inl"
#include "NumberofDigitOne.inl" // learn from others.
#include "lowestCommonAncestor.inl"
#include "DungeonGame.cpp" // NOT AC!!!
#endif

#if __RUNNING_ZONE__
//#include "sqrtInt.cpp" // NOT AC! precis issue.
//#include "SampleCode.cpp" // All sample code.
//#include "minWindow.inl" // NOT AC, your level is too low!!!!!
//#include "RegularExpression.cpp" // NOT AC
//#include "sum3.cpp" // 4Sum NOT AC!
//#include "SingleNumber.cpp" //NOT AC, findDuplicate();
//#include "traversal_binary_tree.cpp"
//#include "ShortestPalindrome.inl"
//#include "DistinctSubsequences.inl" // NOT AC

#endif

#ifdef CODE_BEGINS_HERE
int main(int argc, char** argv){
	Solution s;
	return 0;
}
#endif
