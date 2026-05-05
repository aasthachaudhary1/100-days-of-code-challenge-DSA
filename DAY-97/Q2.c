#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0;
        int rooms = 0, maxRooms = 0;
        
        while (i < n) {
            if (start[i] < end[j]) {
                rooms++;          // need new room
                i++;
            } else {
                rooms--;          // room freed
                j++;
            }
            maxRooms = max(maxRooms, rooms);
        }
        
        return maxRooms;
    }
};
