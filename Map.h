#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Images.h"

class MapField
{
    public:
        sf::Vector3i position;
        sf::Texture texture;
        sf::Sprite sprite;
        MapField (int c_x, int c_y, int c_z, int texture_index)
        {
            position = sf::Vector3i (c_x, c_y, c_z);
            texture.loadFromImage (image_bank [texture_index]);
            texture.setSmooth (true);
            sprite.setTexture (texture);
            sprite.setOrigin (12.5, 12.5);
        }
};

std::vector <MapField*> map_surface;

class MapObject
{
    public:
        sf::Vector3i position;
        sf::Texture image;
        sf::Sprite sprite;
        MapObject (int c_x, int c_y, int c_z, int image_index)
        {
            position = sf::Vector3i (c_x, c_y, c_z);
            image.loadFromImage (image_bank [image_index]);
            image.setSmooth (true);
            sprite.setTexture (image);
            sprite.setOrigin (12.5, 12.5);
        }
};

std::vector <MapObject*> map_surface_objects;

void Map_Load (std::string map_file_path)
{
    std::ifstream map_file (map_file_path.c_str ());
    std::string map_file_line;
    int map_file_data [4];
    bool vector_switch = true;
    while (!map_file.eof ())
    {
        getline (map_file, map_file_line);
        if (vector_switch && map_file_line == "----------------") vector_switch = false;
        for (int i = 0; i < 4; i++) map_file_data [i] = atoi (map_file_line.substr (i * 4, 4).c_str ());
        if (vector_switch) map_surface.push_back (new MapField (map_file_data [0], map_file_data [01], map_file_data [2], map_file_data [3]));
        else map_surface_objects.push_back (new MapObject (map_file_data [0], map_file_data [01], map_file_data [2], map_file_data [3]));
    }
    map_file.close ();
}

#endif // MAP_H_INCLUDED
