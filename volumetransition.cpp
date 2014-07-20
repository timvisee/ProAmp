#include "volumetransition.h"

using namespace Player::Volume;

/**
 * Constructor
 * @brief VolumeTransition::VolumeTransition
 */
VolumeTransition::VolumeTransition() { }

/**
 * Get the volume the transition started with
 * @brief VolumeTransition::getStartVolume
 * @return Start volume
 */
int VolumeTransition::getStartVolume() {
    return this->start;
}

/**
 * Get the target volume for this transition
 * @brief VolumeTransition::getTargetVolume
 * @return Target volume
 */
int VolumeTransition::getTargetVolume() {
    return this->target;
}
