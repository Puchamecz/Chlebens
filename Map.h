#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Images.h"

//GLint universal_field_verticies [24] = {-16, -16, 0,  16, -16, 0,  16, 16, 0,  -16, 16, 0,  -16, -16, 32,  16, -16, 32,  16, 16, 32,  -16, 16, 32};

GLint universal_field_verticies [72] = {-16, -16, 0,  16, -16, 0,  16, 16, 0,  -16, 16, 0,
                                        -16, -16, 32,  16, -16, 32,  16, -16, 32,  -16, -16, 32,
                                        16, -16, 0,  16, 16, 0,  16, 16, 32,  16, -16, 32,
                                        16, 16, 0,  -16, 16, 0,  -16, 16, 32,  16, 16, 32,
                                        -16, 16, 0,  -16, -16, 0,  -16, -16, 32,  -16, 16, 32,
                                        -16, -16, 32,  -16, 16, 32,  16, 16, 32,  16, -16, 32};
GLubyte universal_field_verticies_indicies [24] = {0, 1, 2, 3,  0, 1, 5, 4,  1, 2, 6, 5,  2, 3, 7, 6,  3, 0, 4, 7,  4, 7, 6, 5};
GLint universal_field_texture_coordinates_verticies [48] = {32, 96,  64, 96,  64, 128,  32, 128,
                                                            32, 64,  64, 64,  64, 96,  32, 96,
                                                            64, 32,  96, 32,  96, 64,  64, 64,
                                                            32, 0,  64, 0,  64, 32,  32, 32,
                                                            0, 32,  32, 32,  32, 64,  0, 64,
                                                            32, 32,  64, 32,  64, 64,  32, 64};

class MapField
{
    public:
        char main_type;
        char secondary_type;
        sf::Vector3i position;
        GLint model_verticies [72];
        MapField (int c_x, int c_y, int c_main_type, int c_secondary_type, int c_height)
        {
            main_type = c_main_type;
            secondary_type = c_secondary_type;
            position = sf::Vector3i (c_x, c_y, c_height);
            for (int i = 0; i < 24; i++)
            {
                model_verticies [3 * i] = universal_field_verticies [3 * i] + position.x * 32;
                model_verticies [3 * i + 1] = universal_field_verticies [3 * i + 1] + position.y * 32;
                if (i <= 11) model_verticies [3 * i + 2] = universal_field_verticies [3 * i + 2];
                else model_verticies [3 * i + 2] = universal_field_verticies [3 * i + 2] + position.z * 32;
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
    for (int i = 0; i < map_surface.capacity (); i++) map_surface.push_back (new MapField (i % map_width, (i - i % map_width) / map_width, map_file.get (), map_file.get (), map_file.get ()));
    map_file.close ();
    map_file.open (map_objects_file_path.c_str ());
    map_file.close ();
}

#endif // MAP_H_INCLUDED
