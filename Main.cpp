#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Map.h"

sf::RenderWindow window (sf::VideoMode (800, 600), "Chlebens");
sf::Event event;

int main ()
{
    Images_Load ();
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromImage (image_bank [0]);
    sprite.setTexture (texture);
    //Map_Load ("Maps/1.txt");
    while (window.isOpen ())
    {
        while (window.pollEvent (event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close ();
                    break;
                default:
                    break;
            }
        }
        window.clear (sf::Color::Black);
        window.draw (sprite);
        for (int i = 0; i < map_surface.size (); i++) window.draw (map_surface [i]->sprite);
        for (int i = 0; i < map_surface_objects.size (); i++) window.draw (map_surface_objects [i]->sprite);
        window.display ();
    }
    return 0;
}
