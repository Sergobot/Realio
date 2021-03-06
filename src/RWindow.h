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

//Realio
#include "RPixmap.h"
//C++
#include <iostream>
#include <string>
#include <vector>
//SDL2
#include <SDL2/SDL.h>

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
     * @brief returns window's width.
     * @param void.
     * @return widget's width.
     */
    int getWidth();

    /**
     * @brief returns window's height.
     * @param void.
     * @return widget's height.
     */
    int getHeight();

    /**
     * @brief sets the window's title to a new one.
     * @param reference to a user's std::string.
     * @return void.
     */
    void setTitle(const std::string & title);

    /**
     * @brief loads image to use it as cursor later.
     * @param path to a cursor image and type of the setting cursor.
     * @return void.
     */
    void setCursor(const char* filename, const Uint32 type);

    /**
     * @brief sets cursor to an image.
     * @param type of the cursor.
     * @return void.
     */
    void setCurrentCursor(const Uint32 type);

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
     * @brief deletes widget with the ID.
     * @param widget's ID.
     * @return void.
     */
    void deleteWidget(unsigned ID);

    /**
     * @brief updates the window's content.
     * @param void.
     * @return void.
     */
    virtual void update();

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

    SDL_Cursor *m_systemCursors[5];
    RPixmap *m_customCursors[4];
    Uint32 m_cursorType;

    std::vector<RWidget*> m_widgets;
    std::vector<unsigned> m_IDs;

    bool quit, m_shown;
    // Window's width and height
    int m_width, m_height;

    void (*callback)(SDL_Event e);

    /**
     * @brief initializes SDL.
     * @param void.
     * @return true, if SDL is initialized. false, if not.
     */
    bool initializeSDL();

    /**
     * @brief renders the cursor.
     * @param void.
     * @return void.
     */
    void drawCursor();
};

//Cursor types
typedef enum
{
    CURSOR_ARROW        = 0x00000001,         //Arrow cursor
    CURSOR_IBEAM        = 0x00000002,         //I-beam cursor
    CURSOR_WAIT         = 0x00000004,         //Wait cursor
    CURSOR_NO           = 0x00000008,         //No cursor
    CURSOR_HAND         = 0x00000010,         //Hand cursor
} RWindowCursorType;
}

#endif // RWINDOW_H
