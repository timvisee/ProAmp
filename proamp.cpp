#include "proamp.h"
#include <QApplication>
#include <QFile>
#include "core.h"
#include "logger.h"
#include "profiler.h"
#include "mainwindow.h"

using Util::Log::Logger;
using Util::Profiler::Profiler;

/**
 * Main method. Called when application starts.
 * @brief main
 * @param argc Argument count
 * @param argv Arguments
 * @return Exit code
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setApplicationName(ProAmp::APP_NAME);
    a.setOrganizationName(ProAmp::APP_NAME);
    a.setApplicationVersion(ProAmp::APP_VERSION_NAME);
    //a.setOrganizationDomain("timvisee.com");
    //a.setApplicationDisplayName(ProAmp::APP_NAME);
    a.setWindowIcon(QIcon(ProAmp::APP_ICON));

    // Initialize the logger
    Logger::init();

    // Starting application, show a status message and start a profiler
    Logger::info("Starting " + ProAmp::APP_NAME + " v" + ProAmp::APP_VERSION_NAME + " (" + QString::number(ProAmp::APP_VERSION_CODE) + ")...");
    Profiler p(true);

    // Start the core
    Core c;
    c.init();

    // Starting application, show a status message and start a profiler
    Logger::info(ProAmp::APP_NAME + " started successfully, took " + p.getTimeProper() + "! Cave Johnson here!");

    // Show the main window
    MainWindow w;
    w.show();

    return a.exec();
}

/** Application name */
const QString ProAmp::APP_NAME = "ProAmp";
/** Application version code */
const int ProAmp::APP_VERSION_CODE = 1;
/** Application version name */
const QString ProAmp::APP_VERSION_NAME = "0.1 Pre Alpha";
/** Application icon path */
const QString ProAmp::APP_ICON = "C:/Users/Tim/Documents/Qt Projects/ProAmp/icon.png";
/** Application white icon path */
const QString ProAmp::APP_ICON_WHITE = "C:/Users/Tim/Documents/Qt Projects/ProAmp/icon_white.png";
/** Application system tray icon path */
const QString ProAmp::APP_SYSTEMTRAY_ICON = "C:/Users/Tim/Documents/Qt Projects/ProAmp/icon_mono_white_16.png";

/**
 * Constructor
 * @brief ProAmp::ProAmp
 */
ProAmp::ProAmp() { }
