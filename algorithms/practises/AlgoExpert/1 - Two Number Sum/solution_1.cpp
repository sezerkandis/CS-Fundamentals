#include <vector>

// time complexity level : O(n^2)
// space complexity level : O(1)

std::vector<int> twoNumberSum(std::vector<int> array, int targetSum) {
  // Write your code here.
	std::vector<int> result;
	for (int i = 0; i < array.size(); i++) {
		for (int j = i + 1; j< array.size(); j++) {
			if (array.at(i) + array.at(j) == targetSum) {
				return std::vector<int> {array.at(i), array.at(j)};
			}
		}
	}	
  return result;
}
