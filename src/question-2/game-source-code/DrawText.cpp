#include "DrawText.h"
#include <iostream>
#include <sstream>

using namespace std;

DrawText::DrawText()
{
    font.loadFromFile("resources/transformers_movie.ttf");
    color = Color::White;
}

void DrawText::setTextColor(Color newColor)
{
    color = newColor;
}
void DrawText::setFont(string newFont)
{
    font.loadFromFile(newFont);
}

void DrawText::displayText(string text, int textSize, Vector2f position, RenderWindow &window)
{
    Text textToBeDisplayed(text, font , textSize);
    textToBeDisplayed.setStyle(Text::Regular);
    textToBeDisplayed.setPosition(position);
    textToBeDisplayed.
    setFillColor(color);
    window.draw(textToBeDisplayed);
}
