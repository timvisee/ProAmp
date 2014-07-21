#ifndef MUSICPLAYERENGINEMANAGER_H
#define MUSICPLAYERENGINEMANAGER_H

#include <QVector>
#include "musicplayerengine.h"

namespace Player {
namespace Engine {
class MusicPlayerEngineManager {
private:
    QVector<MusicPlayerEngine*> players;

public:
    /**
     * Constructor
     * @brief MusicPlayerManager
     */
    MusicPlayerEngineManager();

    /**
     * Create and manage a new music player instance.
     * @brief create
     * @return Music player instance that was created.
     */
    MusicPlayerEngine& create();

    /**
     * Start managing a music player instance.
     * @brief add
     * @param p Music player instance to manage.
     * @return True if succeed, false if failed because the player was being managed already.
     */
    bool manage(MusicPlayerEngine *const &p);

    /**
     * Check whether a music player instance is being managed.
     * @brief isManaged
     * @param p The music player instance to check for.
     * @return True if the music player instance is being managed, false if not.
     */
    bool isManaged(MusicPlayerEngine *const &p);

    /**
     * Stop managing a music player by it's instance
     * @brief remove
     * @param p Music player instance to stop managing. False will be returned if the music player instance isn´t being managed.
     * @return True if succeed, false if failed.
     */
    bool unmanage(MusicPlayerEngine *const &p);

    /**
     * Stop managing a music player by it's index
     * @brief removeIndex
     * @param i Index of the music player to remove. If the index is out of bound false will be returned.
     * @return True if succeed, false if failed.
     */
    bool unmanageIndex(int i);
};
}
}

#endif // MUSICPLAYERENGINEMANAGER_H
