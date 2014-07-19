#ifndef CORE_H
#define CORE_H

#include "musicplayer.h"

class Core {
private:
    MusicPlayer player;

public:
    /**
     * Constructor
     * @brief Core
     */
    Core();

    /**
     * Initialize the core
     * @brief Core::init
     * @return True if succeed, false otherwise
     */
    bool init();
};

#endif // CORE_H
