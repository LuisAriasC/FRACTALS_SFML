#include "../Header/SierpinskiMedioCuadro.h"


SierpinskiMedioCuadro::SierpinskiMedioCuadro(){}
SierpinskiMedioCuadro::~SierpinskiMedioCuadro(){}

void SierpinskiMedioCuadro::Render(sf::RenderWindow& window)
{
    sf::Vector2f bottomRightPoint = sf::Vector2f(m_boundingBox.getPosition().x + m_boundingBox.getSize().x, m_boundingBox.getPosition().y + m_boundingBox.getSize().y);
    
    sf::Vector2f topLeftPoint = sf::Vector2f(m_boundingBox.getPosition());
    
    sf::Vector2f center = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, (bottomRightPoint.y + topLeftPoint.y)/2);
    
    sf::Vector2f p1 = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, topLeftPoint.y);
    
    double act_radius = 90.00 ;
    double aument_radius = 360 / 3 ;
    
    double angle_radians = act_radius * (M_PI/180) ;
    double increment_radians = aument_radius * (M_PI/180) ;
    
    double radius = p1.y + center.y ;
    
    drawSierpinskiMedioCuadro(p1, center, radius, angle_radians, increment_radians, -1, window);
}

void SierpinskiMedioCuadro::drawSierpinskiMedioCuadro(const sf::Vector2f &reference_point,
                                            const sf::Vector2f &centro,
                                            double radius,
                                            double ang_actual,
                                            double incremento_ang,
                                            int iteration, sf::RenderWindow &window){
    if(m_numberOfIterations == 0)
    {
        
        sf::Color color = sf::Color(reference_point.y/m_boundingBox.getSize().y*255, 0, window.getSize().x/m_boundingBox.getSize().x*255);
        
        sf::ConvexShape convex;
        convex.setPointCount(3);
        convex.setPoint(0,reference_point);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point1 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -radius * sin(ang_actual) + centro.y);
        convex.setPoint(1,point1);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point2 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(2,point2);
        
        window.draw(convex);
        return;
    }
    else if(iteration == m_numberOfIterations-1){
        return;
    }
    else
    {
        ang_actual = 90.00 * (M_PI/180);
        double radius_2;
        radius_2 = radius - (radius * (0.5));
        //radius_2 = radius - (radius * (0.35));
        
        sf::Vector2f center0 = sf::Vector2f(centro.x + radius_2*cos(ang_actual), centro.y - radius_2*sin(ang_actual));
        
        ang_actual += incremento_ang;
        sf::Vector2f center1 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center2 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center3 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual = 90.00 * (M_PI/180);
        double radius_3 = radius * 0.5;
        //double radius_3 = radius * 0.65;

        
        sf::ConvexShape convex0,convex1, convex2;
        convex0.setPointCount(3);
        convex1.setPointCount(3);
        convex2.setPointCount(3);
        
        //PUNTOS SUPERIORES
        const sf::Vector2f point0_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,center0.y - radius_3*sin(ang_actual));
        convex0.setPoint(0, point0_0);
        
        const sf::Vector2f point0_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(0, point0_1);
        const sf::Vector2f point0_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(0, point0_2);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point1_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,center0.y - radius_3*sin(ang_actual));
        convex0.setPoint(1, point1_0);
        const sf::Vector2f point1_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x, -radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(1, point1_1);
        const sf::Vector2f point1_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(1, point1_2);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point2_0 = sf::Vector2f(center0.x + radius_3*cos(ang_actual), -radius_3*sin(ang_actual) + center0.y);
        convex0.setPoint(2, point2_0);
        const sf::Vector2f point2_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(2, point2_1);
        const sf::Vector2f point2_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(2, point2_2);
        
        if(iteration == m_numberOfIterations-2)
        {
            window.draw(convex0);
            window.draw(convex1);
            window.draw(convex2);
        }
        else
        {
            ang_actual = 90.00 * (M_PI/180);
            drawSierpinskiMedioCuadro(point0_0, center0, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiMedioCuadro(point0_1, center1, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiMedioCuadro(point0_2, center2, radius_3, ang_actual, incremento_ang, iteration+1, window);
        }
    }
    
}

// Getters/Setters

void SierpinskiMedioCuadro::setNumberOfIterations(int newNumberOfIterations)
{
    m_numberOfIterations = newNumberOfIterations;
}

int SierpinskiMedioCuadro::getNumberOfIterations() const
{
    return m_numberOfIterations;
}

void SierpinskiMedioCuadro::setBoundingBox(float x1, float y1, float x2, float y2)
{
    
    m_boundingBox = sf::RectangleShape();
    m_boundingBox.setPosition(sf::Vector2f(x1, y1));
    m_boundingBox.setSize(sf::Vector2f(x2 - x1, y2 - y1));
}



sf::RectangleShape SierpinskiMedioCuadro::getBoundingBox() const
{
    return m_boundingBox;
}

void SierpinskiMedioCuadro::setColor(const sf::Color& newColor)
{
    m_color = sf::Color(newColor);
}

sf::Color SierpinskiMedioCuadro::getColor() const
{
    return m_color;
}

