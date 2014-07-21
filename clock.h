#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QTime>

namespace Util {
namespace Time {
class Clock : public QObject {
    Q_OBJECT

private:
    /** Timer */
    QTime timer;
    /** Time elapsed */
    int elapsed;
    /** Time offset */
    int offset;
    /** Defines whether the clock is started */
    bool started;
    /** Defines whether the clock is paused */
    bool paused;

public:
    /**
     * Constructor
     * @brief Clock
     */
    Clock();

    /**
     * Constructor
     * @brief Clock
     * @param start True to imediately start the clock after construction
     */
    Clock(bool start);

    /**
     * Start the clock. Resumes the clock if it's paused.
     * @brief start
     * @return True if the clock wasn't started. Returns false if the clock is being resumed.
     */
    bool start();

    /**
     * Reset and start the clock again.
     * @brief restart
     * @return Elapsed time in milliseconds before the reset.
     */
    int restart();

    /**
     * Reset the clock.
     * @brief reset
     * @return The elapsed time in milliseconds at the moment the clock was reset.
     */
    int reset();

    /**
     * Check whether the clock is started. This ignores the pause state.
     * @brief isStarted
     * @return True if the clock is started.
     */
    bool isStarted();

    /**
     * Check whether the clock is active. The clock is active if it's started and isn't paused.
     * @brief isActive
     * @return True if the clock is active, false otherwise.
     */
    bool isActive();

    /**
     * Pause the clock. The clock has to be active
     * @brief pause
     * @return True if the clock has been paused because it was active. False otherwise.
     */
    bool pause();

    /**
     * Resume the paused clock. The clock has to be started but paused.
     * @brief resume
     * @return True if the clock has been resumed because it was paused. False otherwise.
     */
    bool resume();

    /**
     * Toggle the current pause state of the clock. The clock has to be started.
     * @brief Clock::togglePause
     * @return True if the pause state was toggled, false if the state couldn't be toggled because the clock wasn't started.
     */
    bool togglePause();

    /**
     * Check whether the clock started but paused.
     * @brief isPaused
     * @return True if the clock is started but paused, false otherwise.
     */
    bool isPaused();

    /**
     * Get the elapsed time in milliseconds. Returns 0 if the clock isn't started.
     * @brief getTime
     * @return Elapsed time in milliseconds.
     */
    int getTime();

    /**
     * Get the clock offset in milliseconds. This offset is applied to the elapsed time of the clock.
     * @brief getOffset
     * @return Clock offset in milliseconds.
     */
    int getOffset();

    /**
     * Set the clock offset in milliseconds. This offset is applied to the elapsed time of the clock.
     * @brief setOffset
     * @param offset Clock offset in milliseconds.
     */
    void setOffset(int offset);

signals:
    /**
     * Triggered when the clock is reset
     * @brief onReset
     */
    void onReset();
};
}
}

#endif // CLOCK_H
