#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Images.h"

class MapField
{
    public:
        char main_type;
        char secondary_type;
        sf::Vector2i position;
        sf::Sprite main_sprite;
        sf::Sprite* secondary_sprite;
        MapField (int c_x, int c_y, int c_main_type, int c_secondary_type)
        {
            main_type = c_main_type;
            secondary_type = c_secondary_type;
            position = sf::Vector2i (c_x, c_y);
            main_sprite.setTexture (texture_bank [main_type]);
            main_sprite.setOrigin (16, 16);
            main_sprite.setPosition (position.x * 32, position.y * 32);
            if (secondary_type != 0)
            {
                secondary_sprite = new sf::Sprite (texture_bank [secondary_type]);
                secondary_sprite->setOrigin (16, 16);
                secondary_sprite->setPosition (position.x, position.y);
            }
        }
};

std::vector <MapField*> map_surface;
int map_width;
int map_height;

class MapObject
{
    public:
        sf::Vector2i position;
        sf::Sprite sprite;
        MapObject (int c_x, int c_y, int image_index)
        {
            position = sf::Vector2i (c_x, c_y);
            sprite.setTexture (image_bank [image_index]);
            sprite.setPosition (position.x, position.y);
        }
};

std::vector <MapObject*> map_surface_objects;

void Map_Load (std::string map_surface_file_path, std::string map_objects_file_path)
{
    std::ifstream map_file (map_surface_file_path.c_str ());
    char map_file_data;
    map_width = map_file.get () * 512 + map_file.get ();
    map_height = map_file.get () * 512 + map_file.get ();
    map_surface.reserve (map_width * map_height);
    for (int i = 0; i < map_surface.capacity (); i++) map_surface.push_back (new MapField (i % map_width, (i - i % map_width) / map_width, map_file.get (), map_file.get ()));
    map_file.close ();
    map_file.open (map_objects_file_path.c_str ());
    map_file.close ();
}

#endif // MAP_H_INCLUDED
