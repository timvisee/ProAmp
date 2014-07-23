#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "musicplayerengine.h"

using Player::Engine::MusicPlayerEngine;

class MusicPlayer {
private:
    MusicPlayerEngine *engine;

public:
    MusicPlayer();
};

#endif // MUSICPLAYER_H
