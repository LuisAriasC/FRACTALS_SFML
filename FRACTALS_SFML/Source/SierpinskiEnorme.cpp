#include "../Header/SierpinskiEnorme.h"



SierpinskiEnorme::SierpinskiEnorme(){}
SierpinskiEnorme::~SierpinskiEnorme(){}

void SierpinskiEnorme::Render(sf::RenderWindow& window) //OBTIENE UN RENDERWINDOW
{   /*ESTA FUNCIÓN OBTIENE LOS PARÁMETROS PARA ENCONTRAR LAS DIMENSIONES DE LOS PUNTOS
     DEL PENTÁGONO DENTRO DEL BOUNDING BOX
     */
    sf::Vector2f bottomRightPoint = sf::Vector2f(m_boundingBox.getPosition().x + m_boundingBox.getSize().x, m_boundingBox.getPosition().y + m_boundingBox.getSize().y);
    //bottomRightPoint es el punto bajo del bounding box
    
    sf::Vector2f topLeftPoint = sf::Vector2f(m_boundingBox.getPosition());
    //bottomLeftPoint es el punto alto del bounding box (0,0)
    
    sf::Vector2f center = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, (bottomRightPoint.y + topLeftPoint.y)/2);
    //centro del pentágono
    
    sf::Vector2f p1 = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, topLeftPoint.y);
    
    double act_radius = 90.00 ;
    double aument_radius = 360.00 / 12 ;
    
    double angle_radians = act_radius * (M_PI/180) ;
    double increment_radians = aument_radius * (M_PI/180) ;
    
    double radius = p1.y + center.y ;
    
    drawSierpinskiEnorme(p1, center, radius, angle_radians, increment_radians, -1, window);
}

void SierpinskiEnorme::drawSierpinskiEnorme(const sf::Vector2f &reference_point,
                                              const sf::Vector2f &centro,
                                              double radius,
                                              double ang_actual,
                                              double incremento_ang,
                                              int iteration, sf::RenderWindow &window){
    if(m_numberOfIterations == 0)
    {
        
        sf::Color color = sf::Color(reference_point.y/m_boundingBox.getSize().y*255, 0, window.getSize().x/m_boundingBox.getSize().x*255);
        
        sf::ConvexShape convex;
        convex.setPointCount(12);
        convex.setPoint(0,reference_point);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point1 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -radius * sin(ang_actual) + centro.y);
        convex.setPoint(1,point1);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point2 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(2,point2);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point3 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(3,point3);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point4 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(4,point4);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point5 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(5,point5);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point6 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(6,point6);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point7 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(7,point7);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point8 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(8,point8);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point9 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(9,point9);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point10 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(10,point10);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point11 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(11,point11);
        
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
        //radius_2 = radius - (radius * (0.01));
        //radius_2 = radius - (radius * (1/3.42));
        radius_2 = radius - (radius * (0.25));
        sf::Vector2f center0 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, - radius_2*sin(ang_actual) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center1 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center2 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center3 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center4 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center5 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center6 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center7 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center8 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center9 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center10 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center11 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual = 90.00 * (M_PI/180);
        //double radius_3 = radius * (0.49);
        //double radius_3 = radius * (1/3.42);
        double radius_3 = radius * (0.25);
        
        sf::ConvexShape convex0,convex1, convex2, convex3, convex4, convex5, convex6, convex7, convex8, convex9, convex10, convex11;
        convex0.setPointCount(12);
        convex1.setPointCount(12);
        convex2.setPointCount(12);
        convex3.setPointCount(12);
        convex4.setPointCount(12);
        convex5.setPointCount(12);
        convex6.setPointCount(12);
        convex7.setPointCount(12);
        convex8.setPointCount(12);
        convex9.setPointCount(12);
        convex10.setPointCount(12);
        convex11.setPointCount(12);

        //PUNTOS SUPERIORES
        const sf::Vector2f point0_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(0, point0_0);
        const sf::Vector2f point0_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(0, point0_1);
        const sf::Vector2f point0_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(0, point0_2);
        const sf::Vector2f point0_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(0, point0_3);
        const sf::Vector2f point0_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(0, point0_4);
        const sf::Vector2f point0_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(0, point0_5);
        const sf::Vector2f point0_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(0, point0_6);
        const sf::Vector2f point0_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(0, point0_7);
        const sf::Vector2f point0_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(0, point0_8);
        const sf::Vector2f point0_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex6.setPoint(0, point0_9);
        const sf::Vector2f point0_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(0, point0_10);
        const sf::Vector2f point0_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(0, point0_11);

        
        ang_actual += incremento_ang;
        const sf::Vector2f point1_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(1, point1_0);
        const sf::Vector2f point1_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x, -radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(1, point1_1);
        const sf::Vector2f point1_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(1, point1_2);
        const sf::Vector2f point1_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(1, point1_3);
        const sf::Vector2f point1_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(1, point1_4);
        const sf::Vector2f point1_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(1, point1_5);
        const sf::Vector2f point1_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(1, point1_6);
        const sf::Vector2f point1_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(1, point1_7);
        const sf::Vector2f point1_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(1, point1_8);
        const sf::Vector2f point1_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(1, point1_9);
        const sf::Vector2f point1_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(1, point1_10);
        const sf::Vector2f point1_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(1, point1_11);
         
         
        ang_actual += incremento_ang;
        const sf::Vector2f point2_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(2, point2_0);
        const sf::Vector2f point2_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(2, point2_1);
        const sf::Vector2f point2_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(2, point2_2);
        const sf::Vector2f point2_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(2, point2_3);
        const sf::Vector2f point2_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(2, point2_4);
        const sf::Vector2f point2_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(2, point2_5);
        const sf::Vector2f point2_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(2, point2_6);
        const sf::Vector2f point2_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(2, point2_7);
        const sf::Vector2f point2_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(2, point2_8);
        const sf::Vector2f point2_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(2, point2_9);
        const sf::Vector2f point2_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(2, point2_10);
        const sf::Vector2f point2_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(2, point2_11);
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point3_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(3, point3_0);
        const sf::Vector2f point3_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(3, point3_1);
        const sf::Vector2f point3_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(3, point3_2);
        const sf::Vector2f point3_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(3, point3_3);
        const sf::Vector2f point3_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(3, point3_4);
        const sf::Vector2f point3_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(3, point3_5);
        const sf::Vector2f point3_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(3, point3_6);
        const sf::Vector2f point3_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(3, point3_7);
        const sf::Vector2f point3_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(3, point3_8);
        const sf::Vector2f point3_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(3, point3_9);
        const sf::Vector2f point3_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(3, point3_10);
        const sf::Vector2f point3_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(3, point3_11);
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point4_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(4, point4_0);
        const sf::Vector2f point4_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(4, point4_1);
        const sf::Vector2f point4_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(4, point4_2);
        const sf::Vector2f point4_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(4, point4_3);
        const sf::Vector2f point4_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(4, point4_4);
        const sf::Vector2f point4_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(4, point4_5);
        const sf::Vector2f point4_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(4, point4_6);
        const sf::Vector2f point4_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(4, point4_7);
        const sf::Vector2f point4_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(4, point4_8);
        const sf::Vector2f point4_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(4, point4_9);
        const sf::Vector2f point4_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(4, point4_10);
        const sf::Vector2f point4_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(4, point4_11);
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point5_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(5, point5_0);
        const sf::Vector2f point5_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(5, point5_1);
        const sf::Vector2f point5_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(5, point5_2);
        const sf::Vector2f point5_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(5, point5_3);
        const sf::Vector2f point5_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(5, point5_4);
        const sf::Vector2f point5_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(5, point5_5);
        const sf::Vector2f point5_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(5, point5_6);
        const sf::Vector2f point5_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(5, point5_7);
        const sf::Vector2f point5_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(5, point5_8);
        const sf::Vector2f point5_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(5, point5_9);
        const sf::Vector2f point5_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(5, point5_10);
        const sf::Vector2f point5_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(5, point5_11);
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point6_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(6, point6_0);
        const sf::Vector2f point6_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(6, point6_1);
        const sf::Vector2f point6_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(6, point6_2);
        const sf::Vector2f point6_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(6, point6_3);
        const sf::Vector2f point6_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(6, point6_4);
        const sf::Vector2f point6_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(6, point6_5);
        const sf::Vector2f point6_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(6, point6_6);
        const sf::Vector2f point6_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(6, point6_7);
        const sf::Vector2f point6_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(6, point6_8);
        const sf::Vector2f point6_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(6, point6_9);
        const sf::Vector2f point6_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(6, point6_10);
        const sf::Vector2f point6_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
         convex11.setPoint(6, point6_11);
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point7_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(7, point7_0);
        const sf::Vector2f point7_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(7, point7_1);
        const sf::Vector2f point7_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(7, point7_2);
        const sf::Vector2f point7_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(7, point7_3);
        const sf::Vector2f point7_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(7, point7_4);
        const sf::Vector2f point7_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(7, point7_5);
        const sf::Vector2f point7_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(7, point7_6);
        const sf::Vector2f point7_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(7, point7_7);
        const sf::Vector2f point7_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(7, point7_8);
        const sf::Vector2f point7_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(7, point7_9);
        const sf::Vector2f point7_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(7, point7_10);
        const sf::Vector2f point7_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(7, point7_11);
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point8_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(8, point8_0);
        const sf::Vector2f point8_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(8, point8_1);
        const sf::Vector2f point8_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(8, point8_2);
        const sf::Vector2f point8_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(8, point8_3);
        const sf::Vector2f point8_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(8, point8_4);
        const sf::Vector2f point8_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(8, point8_5);
        const sf::Vector2f point8_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(8, point8_6);
        const sf::Vector2f point8_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(8, point8_7);
        const sf::Vector2f point8_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(8, point8_8);
        const sf::Vector2f point8_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(8, point8_9);
        const sf::Vector2f point8_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(8, point8_10);
        const sf::Vector2f point8_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(8, point8_11);
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point9_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(9, point9_0);
        const sf::Vector2f point9_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(9, point9_1);
        const sf::Vector2f point9_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(9, point9_2);
        const sf::Vector2f point9_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(9, point9_3);
        const sf::Vector2f point9_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(9, point9_4);
        const sf::Vector2f point9_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(9, point9_5);
        const sf::Vector2f point9_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(9, point9_6);
        const sf::Vector2f point9_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(9, point9_7);
        const sf::Vector2f point9_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(9, point9_8);
        const sf::Vector2f point9_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(9, point9_9);
        const sf::Vector2f point9_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(9, point9_10);
        const sf::Vector2f point9_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(9, point9_11);

        
        ang_actual += incremento_ang;
        const sf::Vector2f point10_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(10, point10_0);
        const sf::Vector2f point10_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(10, point10_1);
        const sf::Vector2f point10_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(10, point10_2);
        const sf::Vector2f point10_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(10, point10_3);
        const sf::Vector2f point10_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(10, point10_4);
        const sf::Vector2f point10_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(10, point10_5);
        const sf::Vector2f point10_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(10, point10_6);
        const sf::Vector2f point10_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(10, point10_7);
        const sf::Vector2f point10_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(10, point10_8);
        const sf::Vector2f point10_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(10, point10_9);
        const sf::Vector2f point10_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(10, point10_10);
        const sf::Vector2f point10_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(10, point10_11);
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point11_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(11, point11_0);
        const sf::Vector2f point11_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(11, point11_1);
        const sf::Vector2f point11_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(11, point11_2);
        const sf::Vector2f point11_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(11, point11_3);
        const sf::Vector2f point11_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(11, point11_4);
        const sf::Vector2f point11_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(11, point11_5);
        const sf::Vector2f point11_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(11, point11_6);
        const sf::Vector2f point11_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(11, point11_7);
        const sf::Vector2f point11_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(11, point11_8);
        const sf::Vector2f point11_9 = sf::Vector2f(radius_3*cos(ang_actual) + center9.x,-(radius_3*sin(ang_actual)) + center9.y);
        convex9.setPoint(11, point11_9);
        const sf::Vector2f point11_10 = sf::Vector2f(radius_3*cos(ang_actual) + center10.x,-(radius_3*sin(ang_actual)) + center10.y);
        convex10.setPoint(11, point11_10);
        const sf::Vector2f point11_11 = sf::Vector2f(radius_3*cos(ang_actual) + center11.x,-(radius_3*sin(ang_actual)) + center11.y);
        convex11.setPoint(11, point11_11);
        
        if(iteration == m_numberOfIterations-2)
        {
            window.draw(convex0);
            window.draw(convex1);
            window.draw(convex2);
            window.draw(convex3);
            window.draw(convex4);
            window.draw(convex5);
            window.draw(convex6);
            window.draw(convex7);
            window.draw(convex8);
            //window.draw(convex9);
            window.draw(convex10);
            window.draw(convex11);
        }
        else
        {
            ang_actual = 90.00 * (M_PI/180);
            drawSierpinskiEnorme(point0_0, center0, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_1, center1, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_2, center2, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_3, center3, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_4, center4, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_5, center5, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_6, center6, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_7, center7, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_8, center8, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_9, center9, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_10, center10, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawSierpinskiEnorme(point0_11, center11, radius_3, ang_actual, incremento_ang, iteration+1, window);
        }
    }
    
}

// Getters/Setters

void SierpinskiEnorme::setNumberOfIterations(int newNumberOfIterations)
{
    m_numberOfIterations = newNumberOfIterations; //DA EL NÚMERO DE ITERACIONES
}

int SierpinskiEnorme::getNumberOfIterations() const
{
    return m_numberOfIterations; //OBTIENE EL NÚMERO DE ITERACIONES ***** BUSCAR DONDE SE USA
}

void SierpinskiEnorme::setBoundingBox(float x1, float y1, float x2, float y2)
{   //x1 y1 son los puntos de la esquina superior izquierda y x2 y2 de la esquina inferior derecha
    
    m_boundingBox = sf::RectangleShape();           //CONSTRUCTOR m_boundingBox
    m_boundingBox.setPosition(sf::Vector2f(x1, y1));//PONE LA POSICIÓN DEL bounding box
    m_boundingBox.setSize(sf::Vector2f(x2 - x1, y2 - y1)); //DEFINE EL TAMAÑO DEL BOUNDING BOX
}



sf::RectangleShape SierpinskiEnorme::getBoundingBox() const
{
    return m_boundingBox;                   //REGRESA EL BOUNDING BOX
}

void SierpinskiEnorme::setColor(const sf::Color& newColor) //DA EL COLOR PRINCIPAL ** VER SI SE USA OTRA VEZ
{
    m_color = sf::Color(newColor);
}

sf::Color SierpinskiEnorme::getColor() const //OBTIENE EL COLOR *** VER DONDE SE USA
{
    return m_color;
}

