#include "volumecontroller.h"

/**
 * Constructor
 * @brief VolumeController::VolumeController
 */
VolumeController::VolumeController() { }

/**
 * Constructor
 * @brief VolumeController::VolumeController
 * @param p QMediaPlayer instance to control
 */
VolumeController::VolumeController(QMediaPlayer *p) {
    this->p = p;
}

/**
 * Get the current volume
 * @brief VolumeController::getVolume
 * @return Current volume
 */
int VolumeController::getVolume() {
    return this->volume;
}

/**
 * Set the current volume
 * @brief VolumeController::setVolume
 * @param volume Current volume
 */
void VolumeController::setVolume(int volume) {
    this->volume = volume;
    this->p->setVolume(this->volume);
}

/**
 * Get the actual current volume the player is currently at, this includes the volume set by volume transitions.
 * @brief VolumeController::getRealVolume
 * @return Get the actual current volume
 */
int VolumeController::getRealVolume() {
    return this->getVolume();
}

/**
 * Check whether the player is muted or not.
 * @brief VolumeController::isMuted
 * @return True if the player is muted, false otherwise.
 */
bool VolumeController::isMuted() {
    return this->muted;
}

/**
 * Set whether the player is muted
 * @brief VolumeController::setMuted
 * @param muted True to mute the player, false to unmute.
 */
void VolumeController::setMuted(bool muted) {
    this->muted = muted;
    this->p->setMuted(muted);
}
