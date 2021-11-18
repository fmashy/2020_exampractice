#ifndef GAME_H
#define GAME_H
#include "Utils.h"
#include "DrawText.h"
#include "DrawObjects.h"

class Game
{
public:
    /** \brief Default Constructor
     *
     * Initialises the win condition to false, the score to zero.
     * It also sets the number of lives for the player to 3 and
     * paints the background.
     */
    Game();
    /** \brief Displays the main loop of the game onto the window.
     *
     * \param RenderWindow&
     * \param ScreenView&
     */
    void getGame(RenderWindow&, ScreenView&);

private:
    void endOfGame(RenderWindow&, ScreenView&);
    void getGameObjects();
    void paintBackground();
    void pollforUserInput(RenderWindow& window);
    void saveHighScore();
    void screenConstants(RenderWindow&);
    void startGame(RenderWindow&, ScreenView&);
    string getHighScore();

    bool win;
    int numOfLives,score;
    string highScore;
    string convertToString(int Num);
    Sprite  background;
    Texture texture;
    BulletList bullets;
    DrawText display;
    DrawObjects drawObjects;
    Galaxip galaxip;
    GameBase gamelogic;
    VecOfGalaxians galaxians;
    VecOfGalaxians galaxians2;
    VecOfGalaxians flagShipEscorts;
    VecOfGalaxians flagShips;
};

#endif // GAME_H
