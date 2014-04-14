#ifndef IMAGES_H_INCLUDED
#define IMAGES_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <fstream>

std::vector <sf::Texture> texture_bank;
std::vector <sf::Texture> image_bank;

void Images_Load ()
{
    std::ifstream images_list ("Img/Images_List.txt");
    std::string images_list_line;
    bool vector_switch = true;
    sf::Texture texture;
    while (!images_list.eof ())
    {
        getline (images_list, images_list_line);
        if (vector_switch && images_list_line == "----------------") vector_switch = false;
        if (vector_switch)
        {
            texture_bank.push_back (texture);
            texture_bank [texture_bank.size () - 1].loadFromFile ("Img/" + images_list_line + ".png");
        }
        else
        {
            image_bank.push_back (texture);
            image_bank [image_bank.size () - 1].loadFromFile ("Img/" + images_list_line + ".png");
        }
    }
    images_list.close ();
}

#endif // IMAGES_H_INCLUDED
