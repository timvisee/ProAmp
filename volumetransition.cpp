#include "volumetransition.h"

using namespace Player::Volume;

/**
 * Constructor
 * @brief VolumeTransition::VolumeTransition
 */
VolumeTransition::VolumeTransition() {
    // TODO: Set the timer interval
    this->timer.setInterval(10);
}

/**
 * Start the volume transition. The transition will be resumed if it's paused.
 * @brief VolumeTransition::start
 * @return True if the transition started and wasn't started already.
 */
bool VolumeTransition::start() {
    // Make sure the transition isn't started already
    if(this->isStarted()) {
        // Unpause the transition if it was paused, return false
        this->resume();
        return false;
    }

    // Start the clock and the timer
    this->clock.restart();
    this->timer.start();

    // Reset the started and paused state, return true
    this->started = true;
    this->paused = false;
    return true;
}

/**
 * Stop the transition. The transition must be started in order to stop it. Stopping a transition will reset it's started state.
 * @brief VolumeTransition::stop
 * @return True if the transition was stopped. False if it couldn't be stopped because it wasn't started.
 */
bool VolumeTransition::stop() {
    // Make sure the transition is started
    if(!this->isStarted())
        return false;

    // Stop the clock and update timer
    this->clock.reset();
    this->timer.stop();

    // Reset the started and paused state, return true
    this->started = false;
    this->paused = false;
    return true;
}

/**
 * Check whether the transition is started. Also returns true if the transition is paused.
 * @brief VolumeTransition::isStarted
 * @return True if the transition is started, ignores the pause state.
 */
bool VolumeTransition::isStarted() {
    return this->started;
}

/**
 * Check whether the transition is active. The transition will be active if it's started and isn't paused.
 * @brief VolumeTransition::isActive
 * @return True if the transition is active, false if not.
 */
bool VolumeTransition::isActive() {
    return this->isStarted() && !this->isPaused();
}

/**
 * Pause the transition.
 * @brief VolumeTransition::pause
 * @return True if the pause status changed, false if the transition was paused already.
 */
bool VolumeTransition::pause() {
    // Make sure the transition isn't paused already
    if(this->isPaused())
        return false;

    // Pause the clock, stop the update timer
    this->clock.pause();
    this->timer.stop();

    // Update the state, return true
    this->paused = true;
    return true;
}

/**
 * Resume the paused transition.
 * @brief VolumeTransition::resume
 * @return True if the pause status changed, false if the transition wasn't paused.
 */
bool VolumeTransition::resume() {
    // Make sure the transition is paused
    if(!this->isPaused())
        return false;

    // Resume the clock and start the update timer
    this->clock.resume();
    this->timer.start();

    // Update the state, return true
    this->paused = false;
    return true;
}

/**
 * Check whether the transition is paused. The transition has to be started to return true.
 * @brief VolumeTransition::isPaused
 * @return True if the transition is paused, false otherwise.
 */
bool VolumeTransition::isPaused() {
    return this->paused;
}

/**
 * Get the starting volume for this transition.
 * @brief VolumeTransition::getStartVolume
 * @return Start volume
 */
int VolumeTransition::getStartVolume() {
    return this->startVolume;
}

/**
 * Set the starting volume for this transition. It's not recommended to set the starting volume while the transition is started.
 * @brief VolumeTransition::setStartVolume
 * @param volume Start volume
 */
void VolumeTransition::setStartVolume(int volume) {
    this->startVolume = volume;
}

/**
 * Get the target volume for this transition.
 * @brief VolumeTransition::getTargetVolume
 * @return Target volume
 */
int VolumeTransition::getTargetVolume() {
    return this->targetVolume;
}

/**
 * Set the target volume for this transition. It's not recommended to set the target volume while the transition is started.
 * @brief VolumeTransition::setTargetVolume
 * @param volume Target volume
 */
void VolumeTransition::setTargetVolume(int volume) {
    this->targetVolume = volume;
}

/**
 * Get the transition duration in milliseconds.
 * @brief VolumeTransition::getDuration
 * @return Transition duration in milliseconds.
 */
int VolumeTransition::getDuration() {
    return this->duration;
}

/**
 * Set the transition duration in milliseconds. It's not recommended to set the duration while the transition is started.
 * @brief VolumeTransition::setDuration
 * @param duration Transition duration in milliseconds.
 */
void VolumeTransition::setDuration(int duration) {
    this->duration = duration;
}
