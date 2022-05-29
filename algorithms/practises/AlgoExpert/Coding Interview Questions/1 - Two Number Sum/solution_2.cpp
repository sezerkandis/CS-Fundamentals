#include <vector>
#include <unordered_set>

// time complexity level : O(n)
// space complexity level : O(n)

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	std::vector<int> result;
	std::unordered_set<int> uniqueArray;
	for (int i = 0; i < array.size(); i++) {
		int searcingItem = targetSum - array.at(i);
		if (uniqueArray.find(searcingItem) == uniqueArray.end()) {			
			uniqueArray.insert(array.at(i));
			continue;
		}
		return std::vector<int> {array.at(i), searcingItem};
	}	
  return result;
}
