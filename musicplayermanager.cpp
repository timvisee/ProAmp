#include "musicplayermanager.h"

/**
 * Constructor
 * @brief MusicPlayerManager::MusicPlayerManager
 */
MusicPlayerManager::MusicPlayerManager() { }

/**
 * Create and manage a new music player instance.
 * @brief MusicPlayerManager::create
 * @return Music player instance that was created.
 */
MusicPlayer& MusicPlayerManager::create() {
    // Create and return a new music player instance
    this->players.append(new MusicPlayer());
    return *this->players.last();
}

/**
 * Start managing a music player instance.
 * @brief MusicPlayerManager::add
 * @param p Music player instance to manage.
 * @return True if succeed, false if failed because the player was being managed already.
 */
bool MusicPlayerManager::manage(MusicPlayer *const &p) {
    // Make sure this music player instance isn't managed already
    if(this->players.contains(p))
        return false;

    // Add the music player instance, return true
    this->players << p;
    return true;
}

/**
 * Check whether a music player instance is being managed.
 * @brief MusicPlayerManager::isManaged
 * @param p The music player instance to check for.
 * @return True if the music player instance is being managed, false if not.
 */
bool MusicPlayerManager::isManaged(MusicPlayer *const &p) {
    return this->players.contains(p);
}

/**
 * Stop managing a music player by it's instance
 * @brief MusicPlayerManager::remove
 * @param p Music player instance to stop managing. False will be returned if the music player instance isn´t being managed.
 * @return True if succeed, false if failed.
 */
bool MusicPlayerManager::unmanage(MusicPlayer *const &p) {
    // Get the index of the instance to remove
    int i = this->players.indexOf(p);

    // Make sure the instance exists, if not, return false
    if(i < 0)
        return false;

    // Remove the instance, return true
    this->players.remove(i);
    return true;
}

/**
 * Stop managing a music player by it's index
 * @brief MusicPlayerManager::removeIndex
 * @param i Index of the music player to remove. If the index is out of bound false will be returned.
 * @return True if succeed, false if failed.
 */
bool MusicPlayerManager::unmanageIndex(int i) {
    // Make sure the index is in bound
    if(i < 0 || i >= this->players.size())
        return false;

    // Remove the player, return true
    this->players.removeAt(i);
    return true;
}
