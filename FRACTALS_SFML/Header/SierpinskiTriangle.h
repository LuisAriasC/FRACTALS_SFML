#ifndef SIERPINSKITRIANGLE_H
#define SIERPINSKITRIANGLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "renderer.h"


class SierpinskiTriangle
{
public:
    SierpinskiTriangle();
    ~SierpinskiTriangle();
    void setNumberOfIterations(int newNumberOfIterations);
    int getNumberOfIterations() const;
    
    void setBoundingBox(float x1, float y1, float x2, float y2);
    sf::RectangleShape getBoundingBox() const;
    
    void setColor(const sf::Color& newColor);
    sf::Color getColor() const;
    
    /*
     *  Recursively calls itself for the top, left and right subtriangle and draws the final iteration
     */
    void drawSierpinskiTriangle(const sf::Vector2f &top, const sf::Vector2f &left, const sf::Vector2f &right,
                                int iteration, sf::RenderWindow &window);
    
    void Render(sf::RenderWindow& window);
    
private:
    sf::RectangleShape m_boundingBox;
    int m_numberOfIterations;
    sf::Color m_color;
};
#endif
