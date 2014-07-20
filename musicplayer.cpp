#include "musicplayer.h"

using namespace Player;

/**
 * Constructor
 * @brief MusicPlayer::MusicPlayer
 */
MusicPlayer::MusicPlayer() {
    // Construct the volume controller
    this->vc = VolumeController(&p);
}

/**
 * Play the current music source
 * @brief play
 */
void MusicPlayer::play() {
    this->p.play();
}

/**
 * Set the music source file to play
 * @brief playFile
 * @param file Path to the music source file
 */
void MusicPlayer::setSourceFile(QString filePath) {
    // TODO: Validate the path, make sure the file exists!
    this->p.setMedia(QUrl::fromLocalFile(filePath));
}

/**
 * Pause the current playing music
 * @brief pause
 */
void MusicPlayer::pause() {
    this->p.pause();
}

/**
 * Stop the current playing music
 * @brief stop
 */
void MusicPlayer::stop() {
    this->p.stop();
}

VolumeController MusicPlayer::getVolumeController() {
    return this->vc;
}
