#include "mainwindow.h"
#include "proamp.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"

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

    // Set the title of the file menu
    this->ui->menuFile->setTitle(ProAmp::APP_NAME);

    // Everything seems to be fine, return true
    return true;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionAbout_triggered() {
    AboutDialog w(this);

    w.setModal(true);
    w.exec();
}

void MainWindow::on_actionExit_triggered() {
    this->close();
}
