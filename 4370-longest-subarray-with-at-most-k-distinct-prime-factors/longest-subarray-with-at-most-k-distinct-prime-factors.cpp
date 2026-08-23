class Solution {
public:

    vector<int> primeFactors(int n) {
        vector<int> factors;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);

                while (n % i == 0)
                    n /= i;
            }
        }

        if (n > 1)
            factors.push_back(n);

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int left = 0;
        int ans = 0;

        map<int, int> freq;
        int distinct = 0;

        for (int right = 0; right < n; right++) {

            vector<int> factors = primeFactors(nums[right]);

            // Add factors of nums[right]
            for (int p : factors) {
                if (freq[p] == 0)
                    distinct++;

                freq[p]++;
            }

            // Too many distinct prime factors
            while (distinct > k) {

                vector<int> leftFactors = primeFactors(nums[left]);

                for (int p : leftFactors) {
                    freq[p]--;

                    if (freq[p] == 0)
                        distinct--;
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};