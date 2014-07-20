#include "aboutdialog.h"
#include <QDesktopServices>
#include "proamp.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint), ui(new Ui::AboutDialog) {
    ui->setupUi(this);

    // Set the dialog title
    this->setWindowTitle("About " + ProAmp::APP_NAME);

    this->setFixedSize(this->size());

    this->ui->aboutInfo->setText(
            "<b>" + ProAmp::APP_NAME + "</b><br>" +
            "Version " + ProAmp::APP_VERSION_NAME + " " +
            "<span style=\"color: gray;\">(Code: " + QString::number(ProAmp::APP_VERSION_CODE) + ")</span><br>" +
            "<br>" +
            "Developed by Tim Visée<br>" +
            "<a href=\"http://timvisee.com/\">http://timvisee.com/</a><br>" +
            "<br>" +
            "Copyright © 2014 " + ProAmp::APP_NAME + ". All Rights Reserved."
            );
}

AboutDialog::~AboutDialog() {
    delete ui;
}

void AboutDialog::on_aboutInfo_linkActivated(const QString &link) {
    QDesktopServices::openUrl(link);
}
