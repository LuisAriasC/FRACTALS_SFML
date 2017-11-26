#include "../Header/SierpinskiTriangle.h"



SierpinskiTriangle::SierpinskiTriangle(){}
SierpinskiTriangle::~SierpinskiTriangle(){}

void SierpinskiTriangle::Render(sf::RenderWindow& window) //OBTIENE UN RENDERWINDOW
{   /*ESTA FUNCIÓN OBTIENE LOS PARÁMETROS PARA ENCONTRAR LAS DIMENSIONES DE LOS PUNTOS
     DEL TRIÁNGULO DENTRO DEL BOUNDING BOX
    */
    sf::Vector2f bottomRightPoint = sf::Vector2f(m_boundingBox.getPosition().x + m_boundingBox.getSize().x, m_boundingBox.getPosition().y + m_boundingBox.getSize().y);
    //bottomRightPoint es el punto bajo del bounding box
    
    sf::Vector2f topLeftPoint = sf::Vector2f(m_boundingBox.getPosition());
    //bottomLeftPoint es el punto aldo del bounding box
    
    sf::Vector2f top = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, topLeftPoint.y);
    //top es la sumatoria de los puntos x de top y bottom entre dos y y es top left point (Hasta arriba)
    
    sf::Vector2f left = sf::Vector2f(topLeftPoint.x, bottomRightPoint.y);
    //left es top x (hasta la izquierda del m_boundingBox) y hasta abajo (y maxima de la ventana)
    sf::Vector2f right = sf::Vector2f(bottomRightPoint.x, bottomRightPoint.y);
    //left es bottom x (hasta la derecha del m_boundingBox) y hasta abajo (y maxima de la ventana)
    drawSierpinskiTriangle(top, left, right, -1, window);
}


void SierpinskiTriangle::drawSierpinskiTriangle(const sf::Vector2f &top,
                                                const sf::Vector2f &left,
                                                const sf::Vector2f &right,
                                                int iteration, sf::RenderWindow &window)
{
    //ESTA FUNCIÓN RECIBE 4 PARÁMETROS, EL VECTOR TOP DEL TRIANGULO PREVIAMENTE CALCULADO
    //EL IZQUIERDO DE ABAJO Y EL DERECHO DE ABAJO, EL NÚMERO DE LA ITERACIÓN
    //Y LA VENTANA EN DONDE SE VA A RENDEREAR
    if(m_numberOfIterations == 0)
    {
        std::cout << "INICIANDO EL TRIÁNGULO" << std::endl;
        sf::Color color = sf::Color(top.y/m_boundingBox.getSize().y*255, 0, right.x/m_boundingBox.getSize().x*255);
        drawTriangle(top, left, right, color, window);
        return;
    }
    else if(iteration == m_numberOfIterations-1){
        return;
    }
    else
    {
        //SI LA ITERACIÓN ES MAYOR A 1 SE SACAN PUNTOS MEDIOS
        
        sf::Vector2f midLeft = sf::Vector2f((left.x + top.x)/2.0, (left.y+top.y)/2.0);
        sf::Vector2f midRight = sf::Vector2f((right.x + top.x)/2.0, (right.y + top.y)/2.0);
        sf::Vector2f midBottom = sf::Vector2f((left.x+right.x)/2.0, (left.y+right.y)/2.0);
        
        if(iteration == m_numberOfIterations-2)
        {
            
            //SACA OTROS 3 PUNTOS PARA GENERAR OTROS 3 TRIÁNGULOS CON LOS ANTERIORMENTE REFERENCIADOS
            
            sf::Color color = sf::Color(top.y/m_boundingBox.getSize().y*255, 0, midRight.x/m_boundingBox.getSize().x*255);
            drawTriangle(top, midLeft, midRight, color, window);
            
            color = sf::Color(midLeft.y/m_boundingBox.getSize().y*255, 0, midRight.x/m_boundingBox.getSize().x*255);
            drawTriangle(midLeft, left, midBottom, color, window);
            
            color = sf::Color(midRight.y/m_boundingBox.getSize().y*255, 0, midRight.x/m_boundingBox.getSize().x*255);
            
            drawTriangle(midRight, midBottom, right, color, window);
        }
        else
        {
            /*Aquí el valor de m_numberOfIterations es mayor que iteraton por 3 uidades, por lo
             que llama a pintar mas iteraciones con la referencia de los puntos de los tres
             triángulos anteriores
            */
            drawSierpinskiTriangle(top, midLeft, midRight, iteration+1, window);
            drawSierpinskiTriangle(midLeft, left, midBottom, iteration+1, window);
            drawSierpinskiTriangle(midRight, midBottom, right, iteration+1, window);
        }
    }
}

// Getters/Setters

void SierpinskiTriangle::setNumberOfIterations(int newNumberOfIterations)
{
    m_numberOfIterations = newNumberOfIterations; //DA EL NÚMERO DE ITERACIONES
}

int SierpinskiTriangle::getNumberOfIterations() const
{
    return m_numberOfIterations; //OBTIENE EL NÚMERO DE ITERACIONES ***** BUSCAR DONDE SE USA
}

void SierpinskiTriangle::setBoundingBox(float x1, float y1, float x2, float y2)
{   //x1 y1 son los puntos de la esquina superior izquierda y x2 y2 de la esquina inferior derecha
    
    m_boundingBox = sf::RectangleShape();           //CONSTRUCTOR m_boundingBox
    m_boundingBox.setPosition(sf::Vector2f(x1, y1));//PONE LA POSICIÓN DEL bounding box
    m_boundingBox.setSize(sf::Vector2f(x2 - x1, y2 - y1)); //DEFINE EL TAMAÑO DEL BOUNDING BOX
}



sf::RectangleShape SierpinskiTriangle::getBoundingBox() const
{
    return m_boundingBox;                   //REGRESA EL BOUNDING BOX
}

void SierpinskiTriangle::setColor(const sf::Color& newColor) //DA EL COLOR PRINCIPAL ** VER SI SE USA OTRA VEZ
{
    m_color = sf::Color(newColor);
}

sf::Color SierpinskiTriangle::getColor() const //OBTIENE EL COLOR *** VER DONDE SE USA
{
    return m_color;
}
