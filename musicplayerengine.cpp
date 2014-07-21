#include "musicplayerengine.h"

using namespace Player::Engine;

/**
 * Constructor
 * @brief MusicPlayer::MusicPlayer
 */
MusicPlayerEngine::MusicPlayerEngine() {
    // Construct the volume controller
    this->vc = VolumeController(&p);
}

/**
 * Play the current music source
 * @brief play
 */
void MusicPlayerEngine::play() {
    this->p.play();
}

/**
 * Set the music source file to play
 * @brief playFile
 * @param file Path to the music source file
 */
void MusicPlayerEngine::setSourceFile(QString filePath) {
    // TODO: Validate the path, make sure the file exists!
    this->p.setMedia(QUrl::fromLocalFile(filePath));
}

/**
 * Pause the current playing music
 * @brief pause
 */
void MusicPlayerEngine::pause() {
    this->p.pause();
}

/**
 * Stop the current playing music
 * @brief stop
 */
void MusicPlayerEngine::stop() {
    this->p.stop();
}

/**
 * Get the volume controller instance
 * @brief MusicPlayer::getVolumeController
 * @return Volume controller instance
 */
VolumeController MusicPlayerEngine::getVolumeController() {
    return this->vc;
}
