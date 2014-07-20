#include "profiler.h"

using namespace Util::Profiler;

QTime t;

/**
 * Constructor
 * @brief Profiler::Profiler
 * @param start True to start the timer on construction, false otherwise
 */
Util::Profiler::Profiler::Profiler(bool start) {
    // Check whether we should start the timer
    if(start)
        this->start();
}

/**
 * Start the profiler
 * @brief Profiler::start
 */
void Profiler::start() {
    this->t.start();
}

/**
 * Restart the profiler
 * @brief restart
 */
void Profiler::restart() {
    this->t.restart();
}

/**
 * Get the profiler time in milliseconds
 * @brief getTime
 * @return Profiler time in milliseconds
 */
int Profiler::getTime() {
    return this->t.elapsed();
}

/**
 * Get the profiler time in milliseconds as a string
 * @brief Profiler::getTimeString
 * @return Profiler time in milliseconds as a string
 */
QString Profiler::getTimeString() {
    return QString::number(this->getTime());
}

/**
 * Get the profiler time.
 * @brief Profiler::getTimeProper
 * @return
 */
QString Profiler::getTimeProper() {
    int d = this->getTime();

    // Invalid timings
    if(d < 0)
        return "? ms";

    // Timings shorter than one millisecond
    else if(d == 0)
        return "<1 ms";

    // Other timings less then one second
    else if(d < 1000)
        return QString::number(d) + " ms";

    // Other timinigs
    else
        return QString::number((int) (d / 1000)) + " s";
}
