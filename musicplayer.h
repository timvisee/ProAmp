#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QtMultimedia>
#include <QtMultimedia/QMediaPlayer>

class MusicPlayer {
private:
    QMediaPlayer p;

public:
    /**
     * Constructor
     * @brief MusicPlayer::MusicPlayer
     */
    MusicPlayer();

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
};

#endif // MUSICPLAYER_H
