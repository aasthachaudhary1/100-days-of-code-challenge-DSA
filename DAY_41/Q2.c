int leastInterval(char* tasks, int tasksSize, int n) {
    
    int freq[26] = {0};
    
    // Count frequency
    for(int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count tasks with max frequency
    int maxCount = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == maxFreq)
            maxCount++;
    }

    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int result = partCount * partLength + maxCount;

    if(result < tasksSize)
        return tasksSize;

    return result;
}
