#ifndef PROFILER_H
#define PROFILER_H

#include "clock.h"

using Util::Time::Clock;

namespace Util {
namespace Profiler {
class Profiler {
private:
    Clock clock;

public:
    /**
     * Constructor
     * @brief Profiler::Profiler
     * @param start True to start the timer on construction, false otherwise
     */
    Profiler(bool start);

    /**
     * Start the profiler
     * @brief Profiler::start
     */
    void start();

    /**
     * Restart the profiler
     * @brief restart
     */
    void restart();

    /**
     * Get the profiler time in milliseconds
     * @brief getTime
     * @return Profiler time in milliseconds
     */
    int getTime();

    /**
     * Get the profiler time in milliseconds as a string
     * @brief Profiler::getTimeString
     * @return Profiler time in milliseconds as a string
     */
    QString getTimeString();

    /**
     * Get the profiler time in proper human-readable format. The function determines whether to use milliseconds or seconds.
     * A time identifier is included.
     * @brief getTimeProper
     * @return Profiler time in proper human-readable format.
     */
    QString getTimeProper();
};
}
}

#endif // PROFILER_H
