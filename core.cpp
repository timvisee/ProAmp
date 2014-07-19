#include "core.h"
#include <QtCore>
#include "proamp.h"
#include "logger.h"
#include "profiler.h"

MusicPlayer player;

/**
 * Constructor
 * @brief Core
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
    Logger::info("Starting " + ProAmp::APP_NAME + " Core...");
    Profiler p(true);

    // Music player test
    player.setSourceFile("C:\\test.wav");
    player.play();

    // TODO: Core initialization code here...

    // The core has started, show a status message
    Logger::info(ProAmp::APP_NAME + " Core started successfully, took " + p.getTimeProper() + "!");
    return true;
}
