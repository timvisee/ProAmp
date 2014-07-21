#include "core.h"
#include <QtCore>
#include "proamp.h"
#include "logger.h"
#include "profiler.h"
#include "musicplayer.h"

using Player::MusicPlayer;
using Util::Log::Logger;
using Util::Profiler::Profiler;

/**
 * Constructor
 * @brief Core::Core
 */
Core::Core() { }

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
    MusicPlayer& mp = this->getMusicPlayerManager().create();
    mp.setSourceFile("C:/test.mp3");
    mp.getVolumeController().setVolume(100);
    mp.play();

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
MusicPlayerManager Core::getMusicPlayerManager() {
    return this->pm;
}
