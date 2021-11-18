#include "Menu.h"

Menu::Menu()
{
    font.loadFromFile("resources/ARLRDBD.TTF");
    texture.loadFromFile("resources/earth.png");
    paintBackground();
}
void Menu::paintBackground()
{
    background.setTexture(texture);
    background.setColor(Color(255, 255, 255, 200));
    background.setPosition(0,0);
}
void Menu::drawMenuOptions(RenderWindow &window)
{
        display.setTextColor(Color::Yellow);
        display.displayText("MENU", 50, Vector2f(200,20), window);
        display.setTextColor(Color::Red);
        display.displayText("START GAME", 30, Vector2f(200,100), window);
        display.displayText("OPTIONS", 30, Vector2f(200,150), window);
        display.displayText("HELP", 30, Vector2f(200,200), window);
}
void Menu::getMenu(RenderWindow& window, ScreenView &screenView)
{
    Text arrow(">", font , 30);
    arrow.setStyle(Text::Regular);
    arrow.setPosition(150,100);
    arrow.setFillColor(Color::White);
    while (window.isOpen() && screenView == MENU)
    {
        window.clear(Color::Black);
        window.draw(background);
        color = Color::Red;
        drawMenuOptions(window);
        color = Color::White;
        window.draw(arrow);
        window.display();
        Event gamemenu;
        while (window.pollEvent(gamemenu))
        {
            Vector2f arrowPos = arrow.getPosition();

            if (gamemenu.type == Event::KeyPressed)
            {
                if (gamemenu.key.code == Keyboard::Escape)window.close();
                if (gamemenu.key.code == Keyboard::Return)
                {
                    if(arrowPos.y == 100) screenView = GAME;
                    if(arrowPos.y == 150) screenView = OPTIONS;
                    if(arrowPos.y == 200) screenView = HELP;
                }
                if (gamemenu.key.code == Keyboard::Up)
                {
                    if(arrowPos.y!=100)arrow.setPosition(arrowPos.x,arrowPos.y-50);
                }
                if (gamemenu.key.code == Keyboard::Down)
                {
                    if(arrowPos.y!=200)arrow.setPosition(arrowPos.x,arrowPos.y+50);
                }
            }
        }
    }
}
