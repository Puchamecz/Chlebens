#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SFML/Graphics.hpp>

class MapField
{
    sf::Vector3i position;
    sf::Texture texture;
    sf::Sprite sprite;
    MapField (int c_x, int c_y, int c_z,)
    {

    }
};

std::vector <MapField> surface;

class MapObject
{
    sf::Vector3f position;
    sf::Texture image;
    sf::Sprite sprite;
    MapObject (int c_x, int c_y, int c_z,)
    {

    }
};

#endif // MAP_H_INCLUDED
