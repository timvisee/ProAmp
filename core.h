#ifndef CORE_H
#define CORE_H

#include <QVector>
#include "musicplayermanager.h"

using Player::MusicPlayerManager;

class Core {
private:
    MusicPlayerManager pm;

public:
    /**
     * Constructor
     * @brief Core
     */
    Core::Core();

    /**
     * Initialize the core
     * @brief Core::init
     * @return True if succeed, false otherwise
     */
    bool init();

    /**
     * Get the music player manager instance
     * @brief getMusicPlayerManager
     * @return Music player manager instance
     */
    MusicPlayerManager getMusicPlayerManager();
};

#endif // CORE_H
