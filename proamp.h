#ifndef PROAMP_H
#define PROAMP_H

#include <QtCore>

class ProAmp {
public:
    /** Application name */
    static const QString APP_NAME;
    /** Application version code */
    static const int APP_VERSION_CODE;
    /** Application version name */
    static const QString APP_VERSION_NAME;
    /** Application icon path */
    static const QString APP_ICON;
    /** Application white icon path */
    static const QString APP_ICON_WHITE;
    /** Application system tray icon path */
    static const QString APP_SYSTEMTRAY_ICON;

    /**
     * Constructor
     * @brief ProAmp::ProAmp
     */
    ProAmp();
};

#endif // PROAMP_H
