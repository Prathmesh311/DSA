class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
       
        int daysWithoutMeeting = 0;
        daysWithoutMeeting += meetings[0][0] - 1;

        int currEnd = meetings[0][0];

         for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            if (start > currEnd + 1) {
                daysWithoutMeeting += start - currEnd - 1;
            }

            currEnd = max(currEnd, end);
        }


        if (currEnd < days) {
            daysWithoutMeeting += days - currEnd;
        }

        return daysWithoutMeeting;
    }
};
