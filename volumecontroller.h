#ifndef VOLUMECONTROLLER_H
#define VOLUMECONTROLLER_H

#include <QtMultimedia>
#include <QtMultimedia/QMediaPlayer>

#include "logger.h"

namespace Player {
namespace Volume {
class VolumeController {
private:
    QMediaPlayer *p;
    int volume;
    bool muted;

public:
    /**
     * Constructor
     * @brief VolumeController
     */
    VolumeController();

    /**
     * Constructor
     * @brief VolumeController
     * @param p QMediaPlayer instance to control
     */
    VolumeController(QMediaPlayer *p);

    /**
     * Get the current volume
     * @brief getVolume
     * @return Current volume
     */
    int getVolume();

    /**
     * Set the current volume
     * @brief setVolume
     * @param volume Current volume
     */
    void setVolume(int volume);

    /**
     * Get the actual current volume the player is currently at, this includes the volume set by volume animations.
     * @brief getRealVolume
     * @return Get the actual current volume
     */
    int getRealVolume();

    /**
     * Check whether the player is muted or not.
     * @brief isMuted
     * @return True if the player is muted, false otherwise.
     */
    bool isMuted();

    /**
     * Set whether the player is muted
     * @brief setMuted
     * @param muted True to mute the player, false to unmute.
     */
    void setMuted(bool muted);
};
}
}

#endif // VOLUMECONTROLLER_H
