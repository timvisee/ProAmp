#ifndef VOLUMETRANSITION_H
#define VOLUMETRANSITION_H

#include <QTimer>
#include "clock.h"

using Util::Time::Clock;

namespace Player {
namespace Volume {
class VolumeTransition {
private:
    /** Transition starting volume */
    int startVolume;
    /** Transition target volume */
    int targetVolume;
    /** Transition duration */
    int duration;
    /** Clock */
    Clock clock;
    /** Update timer */
    QTimer timer;
    /** Defines whether the transition is started */
    bool started;
    /** Defines whether the transition is paused */
    bool paused;

public:
    /**
     * Constructor
     * @brief VolumeTransition
     */
    VolumeTransition();

    /**
     * Start the volume transition.
     * @brief start
     * @return True if the transition started and wasn't started already.
     */
    bool start();

    /**
     * Stop the transition. The transition must be started in order to stop it. Stopping a transition will reset it's started state.
     * @brief stop
     * @return True if the transition was stopped. False if it couldn't be stopped because it wasn't started.
     */
    bool stop();

    /**
     * Check whether the transition is started. Also returns true if the transition is paused.
     * @brief isStarted
     * @return True if the transition is started, ignores the pause state.
     */
    bool isStarted();

    /**
     * Check whether the transition is active. The transition will be active if it's started and isn't paused.
     * @brief isActive
     * @return True if the transition is active, false if not.
     */
    bool isActive();

    /**
     * Pause the transition.
     * @brief pause
     * @return True if the pause status changed, false if the transition was paused already.
     */
    bool pause();

    /**
     * Resume the paused transition.
     * @brief resume
     * @return True if the pause status changed, false if the transition wasn't paused.
     */
    bool resume();

    /**
     * Check whether the transition is paused. The transition has to be started to return true.
     * @brief isPaused
     * @return True if the transition is paused, false otherwise.
     */
    bool isPaused();

    /**
     * Get the starting volume for this transition.
     * @brief getStartVolume
     * @return Start volume
     */
    int getStartVolume();

    /**
     * Set the starting volume for this transition. It's not recommended to set the starting volume while the transition is started.
     * @brief setStartVolume
     * @param volume Start volume
     */
    void setStartVolume(int volume);

    /**
     * Get the target volume for this transition.
     * @brief getTargetVolume
     * @return Target volume
     */
    int getTargetVolume();

    /**
     * Set the target volume for this transition. It's not recommended to set the target volume while the transition is started.
     * @brief setTargetVolume
     * @param volume Target volume
     */
    void setTargetVolume(int volume);

    /**
     * Get the transition duration in milliseconds.
     * @brief getDuration
     * @return Transition duration in milliseconds.
     */
    int getDuration();

    /**
     * Set the transition duration in milliseconds. It's not recommended to set the duration while the transition is started.
     * @brief setDuration
     * @param duration Transition duration in milliseconds.
     */
    void setDuration(int duration);
};
}
}

#endif // VOLUMETRANSITION_H
