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

// Alt
int altRemoveDuplicates(std::vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    // Create var to point to slow runner
    int i = 0;

    // Create loop starting at 2nd index pos to loop over entire vector
    for (int j = 1; j < nums.size(); ++j)
    {
        // Keep looping until we find values that don't match
        if (nums[j] != nums[i])
        {
            // Move the slow runner to the next index and swap out the
            // value at slow runner pos with the value that is NOT a duplicate
            ++i;
            nums[i] = nums[j];
        }
    }

    // Resize the nums vector to REMOVE the duplicates
    // as the problem states duplicates must be REMOVED
    // Without this they are simply pushed to the back
    nums.resize(i + 1);

    return nums.size();
}

int main()
{
    // TEST CASES
    std::vector<int> case1{ 0,0,0,1,1,2,2,2,3,4,5 };

    //int ans = removeDuplicates(case1);
    int ans = altRemoveDuplicates(case1);

    std::cout << "ans = " << ans << '\n';

	return 0;
}