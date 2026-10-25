class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        unordered_map<char,int> freq;

        for(char &ch : t) freq[ch]++;

        int i = 0, j=0;
        int required_cnt = t.length();
        int min_start = 0;
        int minWindow = INT_MAX;

        while(j<n){
            char ch_j = s[j];

            if(freq[ch_j]>0) required_cnt--;

            freq[ch_j]--;

            //shriking the window
            while(required_cnt==0){

                if(minWindow>j-i+1){
                    minWindow = j-i+1;
                    min_start = i;
                }

                char ch_i = s[i];
                freq[ch_i]++;

                if(freq[ch_i]>0) required_cnt++;

                i++;
            }

            j++;
        }

        return minWindow == INT_MAX ? "" : s.substr(min_start,minWindow);

    }
};
