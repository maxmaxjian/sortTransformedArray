#include <iostream>
#include <vector>

using std::vector;

class solution {
  public:
    vector<int> sortTransformedArray(const vector<int> & nums, int a, int b, int c) {
        vector<int> unsorted;
        for (auto n : nums)
            unsorted.push_back(compute(n, a, b, c));

        int mid = int(-b/(2*a));
        size_t idx = 0;
        auto it = std::lower_bound(nums.begin(), nums.end(), mid);
        size_t mid_idx = std::distance(nums.begin(), it);

        vector<int> result(nums.size());
        
    }

  private:
    int compute(int x, int a, int b, int c) {
        return a*x*x+b*x+c;
    }
};

int main() {
    vector<int> nums{-4,-2,2,4};
    int a = , b = , c = ;
    solution soln;
    
}
