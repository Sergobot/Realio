/**
 * This file is part of Realio.
 * Realio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2015 Sergey Popov <sergobot@vivaldi.net>
**/

#ifndef RWINDOW_H
#define RWINDOW_H

//C++
#include <iostream>
#include <string>
#include <vector>
//SDL2
#include <SDL2/SDL.h>
//Realio
#include "RWidget.h"

namespace Realio {
class RWindow
{
public:
    explicit RWindow(const std::string & title);
    ~RWindow();

    /**
     * @brief shows the window.
     * @param void.
     * @return void.
     */
    void show();

    /**
     * @brief closes the window.
     * @param void.
     * @return void.
     */
    void close();

    /**
     * @brief hides the window.
     * @param void.
     * @return void.
     */
    void hide();

    /**
     * @brief sets the window's title to a new one.
     * @param reference to a user's std::string.
     * @return void.
     */
    void setTitle(const std::string & title);

    /**
     * @brief returns the window's title.
     * @param void.
     * @return current title, placed in std::string.
     */
    std::string getTitle();

    /**
     * @brief adds a widget to the window.
     * @param pointer to an RWidget object.
     * @return void.
     */
    void addWidget(RWidget *wgt);

    /**
     * @brief updates the window's content.
     * @param void.
     * @return void.
     */
    void update();

    /**
     * @brief returns true if the window should quit.
     * @param void.
     * @return true, if the window should quit. false, if not.
     */
    bool shouldQuit();

    /**
     * @brief sets key callback function.
     * @param pointer to a function.
     * @return void.
     */
    void setKeyCallback(void (*func)(SDL_Event e));

private:
    std::string m_title;
    SDL_Window *m_window;
    SDL_Surface *m_surface;
    SDL_GLContext m_context;

    std::vector<RWidget*> m_widgets;
    std::vector<int> m_IDs;

    bool quit;
    // Window's width and height
    int m_width;
    int m_height;

    void (*callback)(SDL_Event e);

    /**
     * @brief initializes SDL.
     * @param void.
     * @return true, if SDL is initialized. false, if not.
     */
    bool initializeSDL();
};
}

#endif // RWINDOW_H
