#include "proamp.h"
#include <QApplication>
#include "core.h"
#include "logger.h"
#include "profiler.h"
#include "mainwindow.h"

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
    //a.setOrganizationDomain("timvisee.com");
    //a.setApplicationDisplayName(ProAmp::APP_NAME);
    a.setWindowIcon(QIcon(":/logo.png"));

    // Initialize the logger
    Logger::init();

    // Starting application, show a status message and start a profiler
    Logger::info("Starting " + ProAmp::APP_NAME + " v" + ProAmp::APP_VERSION_NAME + " (" + QString::number(ProAmp::APP_VERSION_CODE) + ")...");
    Profiler p(true);

    // Start the core
    Core c;
    c.init();

    // Starting application, show a status message and start a profiler
    Logger::info(ProAmp::APP_NAME + " started successfully, took " + p.getTimeProper() + "!");
    Logger::info("Cave Johnson here!");

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
const QString ProAmp::APP_VERSION_NAME = "0.1 Alpha";

/**
 * Constructor
 * @brief ProAmp::ProAmp
 */
ProAmp::ProAmp() { }
