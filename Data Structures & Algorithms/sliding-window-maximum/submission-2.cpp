class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> result;

        for(int i=0; i<n; i++){
            //remove the max elements from front which are out of window size
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            //maintaining the dq in descending order
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

            dq.push_back(i);

            if(i>=k-1) result.push_back(nums[dq.front()]); //only when the window size is greater or equal to k front will have the max element

        }

        return result;

    }
};
