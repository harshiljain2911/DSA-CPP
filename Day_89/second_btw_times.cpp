class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {

        int h1, m1, s1;
        int h2, m2, s2;
        
        sscanf(startTime.c_str(), "%d:%d:%d", &h1, &m1, &s1);
        sscanf(endTime.c_str(), "%d:%d:%d", &h2, &m2, &s2);

        return (((h2-h1)*60*60)+(m2-m1)*60+(s2-s1));
    }
};
