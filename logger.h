#ifndef LOGGER_H
#define LOGGER_H

#include <QtCore>

class Logger {
private:
    /** Defines whether the logger is initialized or not */
    static bool _init;
    /** Defines whether message types should be prefixed on log messages */
    static bool showPrefix;
    /** Info message prefix */
    static QString infoPrefix;
    /** Warning message prefix */
    static QString warningPrefix;
    /** Error message prefix */
    static QString errorPrefix;
    /** Debug message prefix */
    static QString debugPrefix;

    /**
     * Log a message. This message will be printed directly without any processing such as adding a timestamp.
     * @brief Logger::log
     * @param msg Message to log
     */
    static void log(QString msg);

    /**
     * Log a message with a specified prefix. This message will be printed directly without any processing such as adding a timestamp, except for the specified prefix.
     * @brief Logger::log
     * @param prefix Prefix to prefix the message with
     * @param msg Message to log
     */
    static void log(QString prefix, QString msg);

public:
    /**
     * Initialize the logger. Required before usage.
     * @brief Logger::init
     * @return True if succeed, false if failed.
     * Also returns true if initialization was cancelled because the logger was initialized already.
     */
    static bool init();

    /**
     * Check whether the logger is initialized.
     * @brief Logger::isInit
     * @return True if the logger is initialized, false if not.
     */
    static bool isInit();

    /**
     * Log an info message.
     * @brief Logger::info
     * @param msg Info message to log
     */
    static void info(QString msg);

    /**
     * Log a warning message.
     * @brief Logger::warning
     * @param msg Warning message to log
     */
    static void warning(QString msg);

    /**
     * Log an error message.
     * @brief Logger::error
     * @param msg Error message to log
     */
    static void error(QString msg);

    /**
     * Log a debug message.
     * @brief Logger::debug
     * @param msg Debug message to log
     */
    static void debug(QString msg);

    /**
     * Check whether prefixes are enabled. If so, all logged messages will be prefixed with their proper message-kind prefix.
     * @brief Logger::isPrefixEnabled
     * @return True if prefixes are enabled, false otherwise.
     */
    static bool isPrefixEnabled();

    /**
     * Set whether prefixes are enabled. If so, all logged messages will be prefixed with their proper message-kind prefix.
     * @brief Logger::setPrefixEnabled
     * @param showPrefix True to enable prefixes, false to disable.
     */
    static void setPrefixEnabled(bool showPrefix);

    /**
     * Get the info message prefix.
     * @brief Logger::getInfoPrefix
     * @return Info message prefix.
     */
    static QString getInfoPrefix();

    /**
     * Set the info message prefix.
     * @brief setInfoPrefix
     * @param prefix Info message prefix.
     */
    static void setInfoPrefix(QString prefix);

    /**
     * Get the warning message prefix.
     * @brief Logger::getWarningPrefix
     * @return Warning message prefix.
     */
    static QString getWarningPrefix();

    /**
     * Set the warning message prefix.
     * @brief setWarningPrefix
     * @param prefix Warning message prefix.
     */
    static void setWarningPrefix(QString prefix);

    /**
     * Get the error message prefix.
     * @brief Logger::getErrorPrefix
     * @return Error message prefix.
     */
    static QString getErrorPrefix();

    /**
     * Set the error message prefix.
     * @brief setErrorPrefix
     * @param prefix Error message prefix.
     */
    static void setErrorPrefix(QString prefix);

    /**
     * Get the debug message prefix.
     * @brief Logger::getDebugPrefix
     * @return Debug message prefix.
     */
    static QString getDebugPrefix();

    /**
     * Set the debug message prefix.
     * @brief setDebugPrefix
     * @param prefix Debug message prefix.
     */
    static void setDebugPrefix(QString prefix);
};

#endif // LOGGER_H
