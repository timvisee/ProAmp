#include "stopwatch.h"

using namespace Util::Time;

/**
 * Constructor
 * @brief Stopwatch::Stopwatch
 */
Stopwatch::Stopwatch() : Clock() {
    // Create all signal slot connections
    connect(this, SIGNAL(onReset()), this, SLOT(resetSplits()));
}

/**
 * Constructor
 * @brief Stopwatch::Stopwatch
 * @param start True to imediately start the stopwatch after construction.
 */
Stopwatch::Stopwatch(bool start) : Clock(start) {
    // Create all signal slot connections
    connect(this, SIGNAL(onReset()), this, SLOT(resetSplits()));
}

/**
 * Split the current time. The stopwatch has to be started in order to split the time.
 * The clock on the stopwatch will continue, the split time will be stored.
 * @brief Stopwatch::split
 * @return The time in milliseconds elapsed after the last split.
 */
int Stopwatch::split() {
    // Make sure the stopwatch is started
    if(!this->isStarted())
        return 0;

    // Store the current split time to return later on
    int t = this->getSplitTime();

    // Split the time
    this->splits << this->getTime();

    // Return the current split time
    return t;
}

/**
 * Get the count of splits made
 * @brief Stopwatch::getSplitCount
 * @return Count of splits made
 */
int Stopwatch::getSplitCount() {
    return this->splits.size();
}

/**
 * Get the elapsed time in milliseconds after the last split.
 * @brief Stopwatch::getSplitTime
 * @return Elapsed time in milliseconds after the last split.
 */
int Stopwatch::getSplitTime() {
    return this->getSplitTime(this->getSplitCount());
}

/**
 * Get a vector list of all split times.
 * @brief Stopwatch::getSplits
 * @return Vector list of all split times.
 */
QVector<int> Stopwatch::getSplits() {
    return this->splits;
}

/**
 * Get the elapsed time in milliseconds for a specific split by it's index.
 * @brief Stopwatch::getSplitTime
 * @param index
 * @return Elasped time in milliseconds for a specific split by it's index.
 * A value one greater than the maximum index will return the elapsed time for the current split.
 * An invalid index will return -1.
 */
int Stopwatch::getSplitTime(int index) {
    // Make sure the index is in-bound
    if(index < 0 || index > this->getSplitCount())
        return -1;

    // Get the split time
    int t = 0;
    if(this->getSplitCount() == index)
        t = this->getTime();

    // Get the split offset
    int offset = 0;
    if(index > 0)
        offset = this->splits[index - 1];

    // Return the time difference
    return t - offset;
}

/**
 * Reset all splits.
 * @brief Stopwatch::resetSplits
 * @return Count of reset splits.
 */
int Stopwatch::resetSplits() {
    // Get the current count of splits
    int c = this->splits.size();

    // Reset all splits, return the count of reset splits
    this->splits.clear();
    return c;
}
