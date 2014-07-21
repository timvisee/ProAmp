#include "clock.h"

using namespace Util::Time;

/**
 * Constructor
 * @brief Clock::Clock
 */
Clock::Clock() {
    // Reset the elapsed time and offset
    this->elapsed = 0;
    this->offset = 0;

    // Reset the clock
    this->reset();
}

/**
 * Constructor
 * @brief Clock::Clock
 * @param start True to imediately start the clock after construction
 */
Clock::Clock(bool start) {
    // Reset the clock
    this->reset();

    // Start the clock if set
    if(start)
        this->start();
}

/**
 * Start the clock. Resumes the clock if it's paused.
 * @brief Clock::start
 * @return True if the clock wasn't started. Returns false if the clock is being resumed.
 */
bool Clock::start() {
    // Make sure the clock wasn't started already
    if(this->isStarted()) {
        // Unpause the clock if it's paused
        this->resume();
        return false;
    }

    // Reset the clock
    this->reset();

    // Set the started, return true
    this->started = true;
    return true;
}

/**
 * Reset and start the clock again.
 * @brief Clock::restart
 * @return Elapsed time in milliseconds before the reset.
 */
int Clock::restart() {
    // Reset the clock
    int t = this->reset();

    // Start the clock again, and return the elapsed time
    this->start();
    return t;
}

/**
 * Reset the clock.
 * @brief Clock::reset
 * @return The elapsed time in milliseconds at the moment the clock was reset.
 */
int Clock::reset() {
    // Store the elapsed time before the reset
    int t = this->getTime();

    // Reset the timer, the elapsed time variable and the started and paused state
    this->timer.restart();
    this->elapsed = 0;
    this->started = false;
    this->paused = false;

    // Return the elapsed time before the reset
    return t;
}

/**
 * Check whether the clock is started. This ignores the pause state.
 * @brief Clock::isStarted
 * @return True if the clock is started.
 */
bool Clock::isStarted() {
    return this->started;
}

/**
 * Check whether the clock is active. The clock is active if it's started and isn't paused.
 * @brief Clock::isActive
 * @return True if the clock is active, false otherwise.
 */
bool Clock::isActive() {
    return this->isStarted() && !this->isPaused();
}

/**
 * Pause the clock. The clock has to be active
 * @brief Clock::pause
 * @return True if the clock has been paused because it was active. False otherwise.
 */
bool Clock::pause() {
    // Make sure the clock is active
    if(!this->isActive())
        return false;

    // Add the elapsed time on the timer to the current elapsed time variable
    this->elapsed += this->timer.elapsed();

    // Reset the timer
    this->timer.restart();

    // Set the paused state, return true
    this->paused = true;
    return true;
}

/**
 * Resume the paused clock. The clock has to be started but paused.
 * @brief Clock::resume
 * @return True if the clock has been resumed because it was paused. False otherwise.
 */
bool Clock::resume() {
    // Make sure the clock is started but paused
    if(!this->isStarted() || !this->isPaused())
        return false;

    // Restart the timer
    this->timer.restart();

    // Set the paused state, return true
    this->paused = false;
    return true;
}

/**
 * Toggle the current pause state of the clock. The clock has to be started.
 * @brief Clock::togglePause
 * @return True if the pause state was toggled, false if the state couldn't be toggled because the clock wasn't started.
 */
bool Clock::togglePause() {
    // Make sure the clock is started
    if(!this->isStarted())
        return false;

    // Toggle the paused state, return true
    if(this->isPaused())
        this->resume();
    else
        this->pause();
    return true;
}

/**
 * Check whether the clock started but paused.
 * @brief Clock::isPaused
 * @return True if the clock is started but paused, false otherwise.
 */
bool Clock::isPaused() {
    // Make sure the clock is started
    if(!this->isStarted())
        return false;

    // Return the paused state
    return this->paused;
}

/**
 * Get the elapsed time in milliseconds. Returns 0 if the clock isn't started.
 * @brief Clock::getTime
 * @return Elapsed time in milliseconds.
 */
int Clock::getTime() {
    // Make sure the clock started
    if(!this->isStarted())
        return 0;

    // Check whether the clock is currently paused, if so, don't include the current timer time
    if(this->isPaused())
        return this->elapsed + this->offset;
    else
        return this->elapsed + this->timer.elapsed() + this->offset;
}

/**
 * Get the clock offset in milliseconds. This offset is applied to the elapsed time of the clock.
 * @brief Clock::getOffset
 * @return Clock offset in milliseconds.
 */
int Clock::getOffset() {
    return this->offset;
}

/**
 * Set the clock offset in milliseconds. This offset is applied to the elapsed time of the clock.
 * @brief Clock::setOffset
 * @param offset Clock offset in milliseconds.
 */
void Clock::setOffset(int offset) {
    this->offset = offset;
}
