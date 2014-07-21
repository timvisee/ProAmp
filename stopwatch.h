#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QVector>
#include "clock.h"

using Util::Time::Clock;

namespace Util {
namespace Time {
class Stopwatch : public Clock {
private:
    /** Vector list holding all split times */
    QVector<int> splits;

public:
    /**
     * Constructor
     * @brief Stopwatch
     */
    Stopwatch();

    /**
     * Constructor
     * @brief Stopwatch
     * @param start True to imediately start the stopwatch after construction.
     */
    Stopwatch(bool start);

    /**
     * Split the current time. The stopwatch has to be started in order to split the time.
     * The clock on the stopwatch will continue, the split time will be stored.
     * @brief split
     * @return The time in milliseconds elapsed after the last split.
     */
    int split();

    /**
     * Get the count of splits made
     * @brief getSplitCount
     * @return Count of splits made
     */
    int getSplitCount();

    /**
     * Get the elapsed time in milliseconds after the last split.
     * @brief getSplitTime
     * @return Elapsed time in milliseconds after the last split.
     */
    int getSplitTime();

    /**
     * Get a vector list of all split times.
     * @brief getSplits
     * @return Vector list of all split times.
     */
    QVector<int> getSplits();

    /**
     * Get the elapsed time in milliseconds for a specific split by it's index.
     * @brief getSplitTime
     * @param index
     * @return Elasped time in milliseconds for a specific split by it's index.
     * A value one greater than the maximum index will return the elapsed time for the current split.
     * An invalid index will return -1.
     */
    int getSplitTime(int index);

public slots:
    /**
     * Reset all splits.
     * @brief resetSplits
     * @return Count of reset splits.
     */
    int resetSplits();
};
}
}

#endif // STOPWATCH_H
