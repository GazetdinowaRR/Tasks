
#include <iostream>
#include <vector>
#include <algorithm>

int minMoves(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int median = nums[nums.size() / 2];
    int moves = 0;

    for (int num : nums) {
        moves += std::abs(num - median);
    }

    return moves;
}

int main() {
    std::vector<int> nums;
    int num;

    std::cout << "Enter space-separated integers. Press Ctrl+D (or Ctrl+Z on Windows) when done:" << std::endl;
    while (std::cin >> num) {
        nums.push_back(num);
    }

    int moves = minMoves(nums);

    std::cout << "Min moves: " << moves << std::endl;

    return 0;
}