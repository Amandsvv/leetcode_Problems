class Solution {
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto getDayOfY = [&daysInMonth](string date) {
            int month = stoi(date.substr(0,2));
            int day = stoi(date.substr(3,2));

            int dayOfY = day;
            for(int i = 0; i < month - 1; ++i) {
                dayOfY += daysInMonth[i];
            }

            return dayOfY;
        };

        int startAlice = getDayOfY(aA);
        int endAlice = getDayOfY(lA);
        int startBob = getDayOfY(aB);
        int endBob = getDayOfY(lB);

        int overLapStart = max(startAlice, startBob);
        int overLapEnd = min(endAlice, endBob);
        return max(0, overLapEnd - overLapStart + 1);
    }
};