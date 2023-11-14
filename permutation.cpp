//
// Created by 12574 on 2023/11/14.
//
#include <iostream>
#include <algorithm>
#include <vector>

//std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
//    std::vector<std::vector<int>> result;
//    std::sort(nums.begin(), nums.end());  // 首先对数组进行排序，确保相同元素相邻
//
//    do {
//        result.push_back(nums);
//    } while (std::next_permutation(nums.begin(), nums.end()));
//
//    return result;
//}
//
//int main() {
//    std::vector<int> nums = {1, 3, 2};
//    std::vector<std::vector<int>> permutations = permuteUnique(nums);
//
//    // 输出结果数组
//    for (const auto& permutation : permutations) {
//        for (int num : permutation) {
//            std::cout << num << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}
void printVector(std::vector<int> &v){
    for(auto &i:v){
        std::cout << i <<" ";

    }
    std::cout << std::endl;
}

void permuteUniqueHelper(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        // 如果当前元素与前面的元素相同，跳过，避免重复排列
        if (i > start && nums[i] == nums[start]) {
            continue;
        }

        // 交换元素，生成新的排列
        std::swap(nums[start], nums[i]);
        printVector(nums);
        // 递归调用，生成下一部分排列
        permuteUniqueHelper(nums, start + 1, result);

        // 恢复原始状态，用于下一次交换
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());  // 首先对数组进行排序，确保相同元素相邻
    permuteUniqueHelper(nums, 0, result);
    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3,4};
    std::vector<std::vector<int>> permutations = permuteUnique(nums);
    std::cout << "results"<<std::endl;
    // 输出结果数组
    for (const auto& permutation : permutations) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
