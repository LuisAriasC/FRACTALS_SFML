#ifndef SIERPISNKIHEPTAGON_H
#define SIERPISNKIHEPTAGON_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "renderer.h"

class SierpinskiHeptagon
{
public:
    SierpinskiHeptagon();
    ~SierpinskiHeptagon();
    void setNumberOfIterations(int newNumberOfIterations);
    int getNumberOfIterations() const;

    void setBoundingBox(float x1, float y1, float x2, float y2);
    sf::RectangleShape getBoundingBox() const;
    
    void setColor(const sf::Color& newColor);
    sf::Color getColor() const;
    
    void drawSierpinskiHeptagon(const sf::Vector2f &reference_point,
                               const sf::Vector2f &centro,
                               double radius,
                               double ang_actual,
                               double incremento_ang,
                               int iteration, sf::RenderWindow &window);

    void Render(sf::RenderWindow& window);
    
private:
    sf::RectangleShape m_boundingBox;
    int m_numberOfIterations;
    sf::Color m_color;
};

#endif /* SirepinskiHeptagon_h */
