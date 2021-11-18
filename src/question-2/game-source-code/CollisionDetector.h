#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include <vector>
#include <memory>
#include "BulletsController.h"
#include "GalaxianController.h"
#include "Galaxip.h"
#include "Configuration.h"

using namespace std;

class CollisionDetector
{
public:
    /** \brief Default Constructor
     *
     * It initialises private data members of the class
     */
    CollisionDetector();

    /** \brief Checks when collisions occur between various game objects.
     *
     * \param VecOfGalaxians& galaxians Galaxians in the fourth and fifth rows from the top
     * \param VecOfGalaxians& galaxians2 Galaxians in the third row from the top
     * \param VecOfGalaxians& flagShipEscorts Flagship escorts (in the second row from the top)
     * \param VecOfGalaxians& flagShips Flagships (top row)
     * \param BulletList& bullets All game bullets (Galaxian and Galaxip)
     * \param Galaxip& galaxip The player's ship
     */
    void checkCollisions(VecOfGalaxians& galaxians,VecOfGalaxians& galaxians2,VecOfGalaxians& flagShipEscorts,VecOfGalaxians& flagShips, BulletList& bullets, Galaxip& galaxip);

    /** \brief Checks whether the game is over or still in progress.
     *
     * \return bool
     *
     */
    bool isGameOver()
    {
        return _gameOver == true;
    };

    /** \brief Returns the current score of the player.
     *
     * \return int
     *
     */
    int  getScore()
    {
        return score;
    };

private:
    /** \brief Detects collisions between a Galaxian and a bullet.
    *
    *   \param Pointer to a galaxian object
    *   \param Pointer to a bullet
    *   \return Returns true if a collision has occurred and returns false otherwise
    */
    bool hasCollided(shared_ptr<Galaxian> galaxian, BulletPtr bullet);

    /** \brief Detects collisions between a Galaxian and a galaxip.
    *
    *   \param Pointer to a galaxian object
    *   \param Galaxip object
    *   \return Returns true if a collision has occured and returns false otherwise
    */
    bool hasCollided(shared_ptr<Galaxian> galaxian, Galaxip galaxip);

    /** \brief Detects collisions between a Galaxip and a bullet.
    *
    *   \param Pointer to a galaxip
    *   \param Pointer to a bullet
    *  \return Returns true if a collision has occurred and returns false otherwise.
    */
    bool hasCollided(Galaxip galaxip, BulletPtr bullet);

    /** \brief Detects collisions between a Galaxian bullet
    *           and a Galaxip bullet.
    *
    *   \param Pointer to a galaxian bullet
    *   \param Pointer to a galaxip bullet
    *   \return Returns true if a collision has occurred and returns false otherwise.
    */
    bool hasCollided(BulletPtr galaxianBullet, BulletPtr galaxipBullet);

    /** \brief Increments the score after a collision between a galaxian and a
     *          bullet has occurred and sets the states of both the bullet and the galaxian to DEAD
     *
     * \param  Vector of galaxians
     * \param  List of bullets
     * \param  Integer representing the points the score is incremented by.
     */
    void checkGalaxianAndBullet(VecOfGalaxians& galaxians,BulletList& bullets, int points);

     /** \brief After a collision between a galaxian and a galaxip it sets the
     *           states of both the galaxian and galaxip to DEAD and ends the game.
     *
     * \param  Vector of galaxians
     * \param  Galaxip object
     */
    void checkGalaxianAndGalaxip(VecOfGalaxians& galaxians, Galaxip& galaxip);

    /** \brief After a collision between a galaxip and a bullet it sets the
     *           states of both the galaxip and the bullet to DEAD and ends the game.
     *
     * \param  Galaxip object
     * \param  List of bullets
     */
    void checkGalaxipAndBullet(Galaxip& galaxip, BulletList& bullets);

    /** \brief After a collision between a galaxip bullet and a galaxian bullet it sets the
     *           states of both bullets to DEAD and increments the user score.
     *
     * \param  List of bullets
     * \param  Integer representing the points the score is incremented by.
     */
    void checkGalaxipBulletAndGalaxianBullet(BulletList& bullets, int points);

    int score;
    bool _gameOver;
};

#endif // COLLISIONDETECTOR_H
