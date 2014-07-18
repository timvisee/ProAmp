#include "mainwindow.h"
#include "proamp.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialize
    this->init();
}

/**
 * Initialize the window
 * @brief MainWindow::init
 * @return True if succeed, false if failed
 */
bool MainWindow::init() {
    // Set the window title
    this->setWindowTitle(ProAmp::APP_NAME + " v" + ProAmp::APP_VERSION_NAME);

    // Everything seems to be fine, return true
    return true;
}

MainWindow::~MainWindow() {
    delete ui;
}
