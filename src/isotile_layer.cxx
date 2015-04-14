//  $Id$
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <iostream>
#include <ClanLib/display.h>
#include <ClanLib/core.h>
#include "isotile_layer.hxx"

IsotileLayer::IsotileLayer(std::string filename)
{
  std::cout << "Filename: " << filename << std::endl;
  CL_PNGProvider buffer(filename);
  buffer.lock();

  tiles.push_back(CL_Surface("tile.png"));
  tiles.push_back(CL_Surface("tile.png"));
  tiles.push_back(CL_Surface("tile1.png"));
  tiles.push_back(CL_Surface("tile2.png"));
  tiles.push_back(CL_Surface("tile3.png"));
  tiles.push_back(CL_Surface("tile4.png"));
  tiles.push_back(CL_Surface("tile5.png"));
  tiles.push_back(CL_Surface("tile5.png"));
      
  width  = buffer.get_width();
  height = buffer.get_height();
  
  tilemap.resize(width * height);

  for(int y = 0; y < height; ++y)
    for(int x = 0; x < width; ++x)
      tilemap[width * y + x] = static_cast<unsigned char*>(buffer.get_data())[width * y + x];

  std::cout << "Tilemap: " << width << "x" << height << std::endl;
  buffer.unlock();
}

int
IsotileLayer::get_width()
{
}

int
IsotileLayer::get_height()
{
}

void
IsotileLayer::draw(int lheight)
{
  for(int i = 0; i < height; ++i)
    {
      for(int j = 0; j < width; ++j)
        {
          int x = 32*(j-i);
          int y = 16*(j+i);
          
          if (tilemap[width * i + j])
            {
              CL_Surface& surf = tiles[tilemap[width * i + j]];

              if (0)
                {
              float dist = sqrt((i - height/2)*(i - height/2)
                                + (j - width/2)*(j - width/2));
              dist += lheight;
              dist /= 16.0f;
              if (dist > 1.0f)
                dist = 1.0f;

              surf.set_color(1.0f-dist,
                             1.0f-dist,
                             1.0f-dist,
                             1.0f/(4.0f-lheight));
                }
              surf.draw(x + 320, y - surf.get_height() - lheight*24  + 100);
            }
          
          //std::cout << tilemap[width * i + j] << " ";
        }
      //std::cout << std::endl;
    }
}

/* EOF */
