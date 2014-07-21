#ifndef MUSICPLAYERENGINE_H
#define MUSICPLAYERENGINE_H

#include <QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include "volumecontroller.h"

using Player::Volume::VolumeController;

namespace Player {
namespace Engine {
class MusicPlayerEngine {
private:
    QMediaPlayer p;
    VolumeController vc;

private slots:
    void update();

public:
    /**
     * Constructor
     * @brief MusicPlayer::MusicPlayer
     */
    MusicPlayerEngine();

    /**
     * Play the current music source
     * @brief play
     */
    void play();

    /**
     * Set the music source file to play
     * @brief playFile
     * @param file Path to the music source file
     */
    void setSourceFile(QString file);

    /**
     * Pause the current playing music
     * @brief pause
     */
    void pause();

    /**
     * Stop the current playing music
     * @brief stop
     */
    void stop();

    /**
     * Get the volume controller instance
     * @brief getVolumeController
     * @return Volume controller instance
     */
    VolumeController getVolumeController();
};
}
}

#endif // MUSICPLAYERENGINE_H
