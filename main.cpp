#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using std::vector;
using std::deque;

class solution {
  public:
    vector<int> sortTransformedArray(const vector<int> & nums, int a, int b, int c) {
        int mid = int(-b/(2*a));
        auto it = std::lower_bound(nums.begin(), nums.end(), mid);
        size_t mid_idx = std::distance(nums.begin(), it);
        
        deque<int> small, large;
        for (size_t i = 0; i < mid_idx; ++i)
            small.push_back(compute(nums[i], a, b, c));
        for (size_t i = mid_idx; i < nums.size(); ++i)
            large.push_back(compute(nums[i], a, b, c));

        vector<int> result;
        if (a > 0) {
            while (!small.empty() && !large.empty()) {
                if (small.back() < large.front()) {
                    result.push_back(small.back());
                    small.pop_back();
                }
                else {
                    result.push_back(large.front());
                    large.pop_front();
                }
            }

            while (!large.empty()) {
                result.push_back(large.front());
                large.pop_front();
            }

            while (!small.empty()) {
                result.push_back(small.back());
                small.pop_back();
            }
        }
        else if (a < 0) {
            while (!small.empty() && !large.empty()) {
                if (small.front() < large.back()) {
                    result.push_back(small.front());
                    small.pop_front();
                }
                else {
                    result.push_back(large.back());
                    large.pop_back();
                }
            }

            while (!small.empty()) {
                result.push_back(small.front());
                small.pop_front();
            }

            while (!large.empty()) {
                result.push_back(large.back());
                large.pop_back();
            }
        }
        else {
            if (b < 0) {
                while (!large.empty()) {
                    result.push_back(large.back());
                    large.pop_back();
                }
                while (!small.empty()) {
                    result.push_back(small.back());
                    small.pop_back();
                }
            }
            else {
                while (!small.empty()) {
                    result.push_back(small.front());
                    small.pop_front();
                }
                while (!large.empty()) {
                    result.push_back(large.front());
                    large.pop_front();
                }
            }
        }

        return result;
    }

  private:
    int compute(int x, int a, int b, int c) {
        return a*x*x+b*x+c;
    }
};

int main() {
    vector<int> nums{-4,-2,2,4};
    // int a = 1, b = 3, c = 5;
    int a = -1, b = 3, c = 5;
    
    solution soln;
    vector<int> sorted = soln.sortTransformedArray(nums, a, b, c);
    std::cout << "The sorted result is:\n";
    std::for_each(sorted.begin(), sorted.end(),
                  [](int i){
                      std::cout << i << " ";
                  });
    std::cout << std::endl;
}
