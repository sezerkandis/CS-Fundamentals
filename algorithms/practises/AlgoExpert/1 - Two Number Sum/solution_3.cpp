#include <vector>

// time complexity level : O(nLog(n))
// space complexity level : O(1)

std::vector<int> twoNumberSum(std::vector<int> array, int targetSum) {
  // Write your code here.
	std::sort(array.begin(), array.end());
	int leftIndex = 0, rightIndex = array.size() - 1;
	while (leftIndex < rightIndex) {
		int potentionalSum = array[leftIndex] + array[rightIndex];
		if (potentionalSum == targetSum) {
			return std::vector<int> { array[leftIndex], array[rightIndex]};
		}
		else if (potentionalSum > targetSum) {
			rightIndex--;
		}
		else if (potentionalSum < targetSum) {
			leftIndex++;
		}
	}	
  return {};
}
