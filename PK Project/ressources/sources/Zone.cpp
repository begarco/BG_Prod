/*
    PK Project
    Copyright (C) 2013  BG Prod

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Contact me : bgprod@outlook.com
*/

#include "Zone.h"


using namespace std;


Zone::Zone()
{
    m_case = new Case*[8];
    m_images = NULL;
    m_in = NULL;
    for(int i = 0 ; i < 8 ; i++)
    {
        m_case[i] = new Case[16];
    }
    m_position.x = 10*RESIZE;
    m_position.y = 550*RESIZE;
    m_position.w = 1440*RESIZE;
    m_position.h = 520*RESIZE;
}

Zone::~Zone()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        delete [] m_case[i];
    }
    delete [] m_case;
}

void Zone::init(SDL_Surface ** p_images, Input * p_in)
{
    m_images = p_images;
    m_in = p_in;
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 16 ; j++)
        {
            m_case[i][j].init(p_images, p_in);
            m_case[i][j].setPosition(j*90*RESIZE + m_position.x, i*65*RESIZE + m_position.y);
        }
    }
}

void Zone::afficher()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 16 ; j++)
        {
            m_case[i][j].afficher();
        }
    }
}

void Zone::setPosition(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
}

