#ifndef CORE_H
#define CORE_H

#include <QVector>
#include <QSystemTrayIcon>
#include "musicplayerenginemanager.h"

using Player::Engine::MusicPlayerEngineManager;

class Core {
private:
    MusicPlayerEngineManager pm;
    QSystemTrayIcon trayIcon;

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
    MusicPlayerEngineManager getMusicPlayerManager();
};

#endif // CORE_H
