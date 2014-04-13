#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Map.h"
#include "Races.h"

sf::RenderWindow window (sf::VideoMode (800, 600), "Chlebens");
sf::Event event;

int main ()
{
    Images_Load ();
    Map_Load ("Maps/1.txt", "Maps/11.txt");
    sf::Sprite sprite (texture_bank [0]);
    sprite.setPosition (12, 12);
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
        for (int i = 0; i < map_surface.size (); i++) window.draw (map_surface [i]->main_sprite);
        for (int i = 0; i < map_surface_objects.size (); i++) window.draw (map_surface_objects [i]->sprite);
        window.display ();
    }
    return 0;
}
