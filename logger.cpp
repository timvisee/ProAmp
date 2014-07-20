#include "logger.h"

// Define variables
/** Defines whether the logger is initialized or not */
bool Logger::_init = false;
/** Defines whether message types should be prefixed on log messages */
bool Logger::showPrefix = true;
/** Info message prefix */
QString Logger::infoPrefix = "[INFO] ";
/** Warning message prefix */
QString Logger::warningPrefix = "[WARNING] ";
/** Error message prefix */
QString Logger::errorPrefix = "[ERROR] ";
/** Debug message prefix */
QString Logger::debugPrefix = "[DEBUG] ";

/**
 * Initialize the logger. Required before usage.
 * @brief Logger::init
 * @return True if succeed, false if failed.
 * Also returns true if initialization was cancelled because the logger was initialized already.
 */
bool Logger::init() {
    // Don't allow to initialize more than once
    if(Logger::isInit())
        return true;

    // TODO: Logger initialization code here...
    // Everything seems to be fine, set the init variable and return true
    Logger::_init = true;
    return true;
}

/**
 * Check whether the logger is initialized.
 * @brief Logger::isInit
 * @return True if the logger is initialized, false if not.
 */
bool Logger::isInit() {
    return Logger::_init;
}

/**
 * Log a message. This message will be printed directly without any processing such as adding a timestamp.
 * @brief Logger::log
 * @param msg Message to log
 */
void Logger::log(QString msg) {
    // TODO: Remove the automatically added quotes on strings using qDebug()
    // TODO: Use cout << ""?
    qDebug() << msg;
}

/**
 * Log a message with a specified prefix. This message will be printed directly without any processing such as adding a timestamp, except for the specified prefix.
 * @brief Logger::log
 * @param prefix Prefix to prefix the message with
 * @param msg Message to log
 */
void Logger::log(QString prefix, QString msg) {
    Logger::log(prefix + msg);
}

/**
 * Log an info message.
 * @brief Logger::info
 * @param msg Info message to log
 */
void Logger::info(QString msg) {
    // Check whether the prefix should be shown
    if(Logger::showPrefix)
        Logger::log(infoPrefix, msg);
    else
        Logger::log(msg);
}

/**
 * Log a warning message.
 * @brief Logger::warning
 * @param msg Warning message to log
 */
void Logger::warning(QString msg) {
    // Check whether the prefix should be shown
    if(Logger::showPrefix)
        Logger::log(warningPrefix, msg);
    else
        Logger::log(msg);
}

/**
 * Log an error message.
 * @brief Logger::error
 * @param msg Error message to log
 */
void Logger::error(QString msg) {
    // Check whether the prefix should be shown
    if(Logger::showPrefix)
        Logger::log(errorPrefix, msg);
    else
        Logger::log(msg);
}

/**
 * Log a debug message.
 * @brief Logger::debug
 * @param msg Debug message to log
 */
void Logger::debug(QString msg) {
    // Check whether the prefix should be shown
    if(Logger::showPrefix)
        Logger::log(debugPrefix, msg);
    else
        Logger::log(msg);
}

/**
 * Check whether prefixes are enabled. If so, all logged messages will be prefixed with their proper message-kind prefix.
 * @brief Logger::isPrefixEnabled
 * @return True if prefixes are enabled, false otherwise.
 */
bool Logger::isPrefixEnabled() {
    return Logger::showPrefix;
}

/**
 * Set whether prefixes are enabled. If so, all logged messages will be prefixed with their proper message-kind prefix.
 * @brief Logger::setPrefixEnabled
 * @param showPrefix True to enable prefixes, false to disable.
 */
void Logger::setPrefixEnabled(bool showPrefix) {
    Logger::showPrefix = showPrefix;
}

/**
 * Get the info message prefix.
 * @brief Logger::getInfoPrefix
 * @return Info message prefix.
 */
QString Logger::getInfoPrefix() {
    return Logger::infoPrefix;
}

/**
 * Set the info message prefix.
 * @brief setInfoPrefix
 * @param prefix Info message prefix.
 */
void Logger::setInfoPrefix(QString prefix) {
    Logger::infoPrefix = prefix;
}

/**
 * Get the warning message prefix.
 * @brief Logger::getWarningPrefix
 * @return Warning message prefix.
 */
QString Logger::getWarningPrefix() {
    return Logger::warningPrefix;
}

/**
 * Set the warning message prefix.
 * @brief setWarningPrefix
 * @param prefix Warning message prefix.
 */
void Logger::setWarningPrefix(QString prefix) {
    Logger::warningPrefix = prefix;
}

/**
 * Get the error message prefix.
 * @brief Logger::getErrorPrefix
 * @return Error message prefix.
 */
QString Logger::getErrorPrefix() {
    return Logger::errorPrefix;
}

/**
 * Set the error message prefix.
 * @brief setErrorPrefix
 * @param prefix Error message prefix.
 */
void Logger::setErrorPrefix(QString prefix) {
    Logger::errorPrefix = prefix;
}

/**
 * Get the debug message prefix.
 * @brief Logger::getDebugPrefix
 * @return Debug message prefix.
 */
QString Logger::getDebugPrefix() {
    return Logger::debugPrefix;
}

/**
 * Set the debug message prefix.
 * @brief setDebugPrefix
 * @param prefix Debug message prefix.
 */
void Logger::setDebugPrefix(QString prefix) {
    Logger::debugPrefix = prefix;
}
