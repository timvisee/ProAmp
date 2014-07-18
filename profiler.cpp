#include "profiler.h"

QTime t;

/**
 * Constructor
 * @brief Profiler::Profiler
 * @param start True to start the timer on construction, false otherwise
 */
Profiler::Profiler(bool start) {
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

void Profiler::restart() {
    this->t.restart();
}

int Profiler::getTime() {
    return this->t.elapsed();
}

QString Profiler::getTimeString() {
    return QString::number(this->getTime());
}

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
