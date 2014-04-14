#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Map.h"
#include "Races.h"

sf::RenderWindow window (sf::VideoMode (800, 600), "Chlebens");
sf::Event event;
GLfloat colors [] = {1, 1, 1,  0, 0, 1,  1, 1, 0,  0, 1, 0,  1, 0, 0,  1, 0, 1,  0, 0, 0,  0, 1, 1};

int main ()
{
    glEnable (GL_TEXTURE_2D);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (90, 1.0f, 0, -64*32);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    glTranslatef (0, 0, -10*32);
    Images_Load ();
    Map_Load ("Maps/1.txt", "Maps/11.txt");
    while (window.isOpen ())
    {
        while (window.pollEvent (event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close ();
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Add:
                            glTranslatef (0, 0, 32);
                            break;
                        case sf::Keyboard::Subtract:
                            glTranslatef (0, 0, -32);
                            break;
                        case sf::Keyboard::Up:
                            glTranslatef (0, -32, 0);
                            break;
                        case sf::Keyboard::Down:
                            glTranslatef (0, 32, 0);
                            break;
                        case sf::Keyboard::Left:
                            glTranslatef (32, 0, 0);
                            break;
                        case sf::Keyboard::Right:
                            glTranslatef (-32, 0, 0);
                            break;
                        case sf::Keyboard::O:
                            glRotatef (10, 1, 0, 0);
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnableClientState (GL_VERTEX_ARRAY);
        glEnableClientState (GL_TEXTURE_COORD_ARRAY);
        for (int i = 0; i < map_surface.size (); i++)
        {
            sf::Texture::bind (&texture_bank [map_surface [i]->main_type]);
            glTexCoordPointer (2, GL_INT, 0, universal_field_texture_coordinates_verticies);
            glVertexPointer (3, GL_INT, 0, map_surface [i]->model_verticies);
            glDrawArrays (GL_QUADS, 0, 24);
        }
        glDisableClientState (GL_VERTEX_ARRAY);
        glDisableClientState (GL_TEXTURE_COORD_ARRAY);
        //for (int i = 0; i < map_surface_objects.size (); i++) window.draw (map_surface_objects [i]->sprite);
        window.display ();
    }
    return 0;
}
