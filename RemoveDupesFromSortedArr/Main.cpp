#include<iostream>
#include <vector>
#include <algorithm>

int removeDuplicates(std::vector<int>& nums)
{
    // Create an iterator to hold the new off the end pos
    std::vector<int>::iterator it;

    // Remove all non-unique values
    it = std::unique(nums.begin(), nums.end());

    // Resize the vector to the new size
    nums.resize(std::distance(nums.begin(), it));

    return nums.size();
}

int main()
{
    // TEST CASES
    std::vector<int> case1{ 0,0,0,1,1,2,2,2,3,4,5 };

    int ans = removeDuplicates(case1);

    std::cout << "ans = " << ans << '\n';

	return 0;
}