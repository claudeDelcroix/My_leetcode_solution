int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int total = 0;
    for (int i = 0; i + 1 < timeSeriesSize; i++) {
        int delta = timeSeries[i + 1] - timeSeries[i];
        total += (delta < duration ? delta : duration);
    }
    if (timeSeriesSize > 0) {
        total += duration;
    }
    return total;
}
