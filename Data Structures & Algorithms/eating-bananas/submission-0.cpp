class Solution {
public:
    int check(vector<int>& piles, int k){
        int ans = 0;
        for(int pile: piles) ans += (pile/k) + (bool)(pile%k);

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l <= r){
            int mid = (l + (r-l)/2);
            int time = check(piles, mid);
            if(time <= h){
                k = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return k;
    }
};
