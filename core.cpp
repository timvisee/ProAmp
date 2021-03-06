#include "core.h"
#include <QtCore>
#include <QIcon>
#include "proamp.h"
#include "logger.h"
#include "profiler.h"
#include "musicplayerengine.h"

using Player::Engine::MusicPlayerEngine;
using Util::Log::Logger;
using Util::Profiler::Profiler;

/**
 * Constructor
 * @brief Core::Core
 */
Core::Core() {
    //Core::instance = this;
}

/**
 * Initialize the core
 * @brief Core::init
 * @return True if succeed, false otherwise
 */
bool Core::init() {
    // Initialize the logger if it hasn't been initialized yet
    Logger::init();

    // Starting the core, show a status message and start a profiler
    Logger::debug("Initializing " + ProAmp::APP_NAME + " Core...");
    Profiler p(true);

    // Music player testing
    MusicPlayerEngine& mp = this->getMusicPlayerManager().create();
    mp.setSourceFile("C:/test.mp3");
    mp.getVolumeController().setVolume(50);
    mp.play();

    // Set up the system tray icon
    // TODO: Set tray icon
    this->trayIcon.setIcon(QIcon(ProAmp::APP_SYSTEMTRAY_ICON));
    this->trayIcon.setToolTip(ProAmp::APP_NAME);
    this->trayIcon.setVisible(true);

    // TODO: Core initialization code here...

    // The core has started, show a status message
    Logger::debug(ProAmp::APP_NAME + " Core initialized successfully, took " + p.getTimeProper() + "!");
    return true;
}

/**
 * Get the music player manager instance
 * @brief Core::getMusicPlayerManager
 * @return Music player manager instance
 */
MusicPlayerEngineManager Core::getMusicPlayerManager() {
    return this->pm;
}
