#ifndef OPTIONS_H
#define OPTIONS_H
#include "Utils.h"
#include "DrawText.h"

class Options
{
    public:
        /** \brief Default Constructor
         *
         * It initialises the private data members of the class.
         */
        Options();

        /** \brief Responsible for the display of the options menu.
         *
         * \param RenderWindow&
         * \param ScreenView&
         */
        void getOptions(RenderWindow&, ScreenView&);

    private:
        void clearHighScore(RenderWindow&,ScreenView&);
        void changeSpeed(RenderWindow&,ScreenView&);
        void drawSpeedOptions(RenderWindow&);
        void options(RenderWindow&,ScreenView&);
        void paintBackground();
        void screenConstants(RenderWindow&);
        void speedChanged(RenderWindow&,ScreenView&);

        DrawText display;
        Font font;
        Sprite  background;
        Texture texture;
};

#endif // DISPLAYOPTIONS_H
