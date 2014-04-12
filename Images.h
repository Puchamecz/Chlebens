#ifndef IMAGES_H_INCLUDED
#define IMAGES_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>

std::vector <sf::Image> texture_bank;
std::vector <sf::Image> image_bank;
std::ofstream dx ("dx.txt");

void Images_Load ()
{
    std::ifstream images_list ("Img/Images_List.txt");
    std::string images_list_line;
    bool vector_switch = true;
    sf::Image image;
    while (!images_list.eof ())
    {
        dx<<"Chleb";
        dx.close ();
        getline (images_list, images_list_line);
        if (vector_switch && images_list_line == "----------------") vector_switch = false;
        if (vector_switch)
        {
            texture_bank.push_back (image);
            texture_bank [texture_bank.size () - 1].loadFromFile ("Img/" + images_list_line + ".png");
        }
        else
        {
            image_bank.push_back (image);
            image_bank [image_bank.size () - 1].loadFromFile ("Img/" + images_list_line + ".png");
        }
    }
}

#endif // IMAGES_H_INCLUDED
