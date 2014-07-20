#ifndef VOLUMETRANSITION_H
#define VOLUMETRANSITION_H

#include <QTimer>

namespace Player {
namespace Volume {
class VolumeTransition {
private:
    int start, target;

public:
    /**
     * Constructor
     * @brief VolumeTransition
     */
    VolumeTransition();

    /**
     * Get the volume the transition started with
     * @brief getStartVolume
     * @return Start volume
     */
    int getStartVolume();

    /**
     * Get the target volume for this transition
     * @brief getTargetVolume
     * @return Target volume
     */
    int getTargetVolume();
};
}
}

#endif // VOLUMETRANSITION_H
