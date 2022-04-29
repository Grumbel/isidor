// Isidor
// Copyright (C) 2002 Ingo Ruhnke <grumbel@gmail.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <iostream>
#include <ClanLib/display.h>

#include "datadir.hpp"
#include "isowall_layer.hpp"

IsowallLayer::IsowallLayer(std::string filename)
  : horz(isidor::g_datadir + "/images/htile1.png"),
    vert(isidor::g_datadir + "/images/wtile1.png")
{
  std::cout << "Filename: " << filename << std::endl;
  CL_PNGProvider buffer(filename);
  buffer.lock();

  width  = buffer.get_width();
  height = buffer.get_height();

  tilemap.resize(width * height);

  for(int y = 0; y < height; ++y)
    for(int x = 0; x < width; ++x)
      tilemap[width * y + x] = static_cast<unsigned char*>(buffer.get_data())[width * y + x];

  std::cout << "Tilewall: " << width << "x" << height << std::endl;
  buffer.unlock();
}

void
IsowallLayer::draw()
{
  for(int i = 0; i < height; ++i)
  {
    for(int j = 0; j < width; ++j)
    {
      int x = 32*(j/2-i);
      int y = 16*(j/2+i);

      if (tilemap[width * i + j])
      {
        if (true)
        {
          float dist = sqrt((i - height/2)*(i - height/2)
                            + (j - width/2)*(j - width/2));
          //dist += lheight;
          dist /= 12.0f;
          if (dist > 1.0f)
            dist = 1.0f;

          horz.set_color(1.0f-dist,
                         1.0f-dist,
                         1.0f-dist,
                         1.0f);
          vert.set_color(1.0f-dist,
                         1.0f-dist,
                         1.0f-dist,
                         1.0f);
        }

        if (j % 2)
          horz.draw(x + 320 + 32, y - horz.get_height() + 100 - 16);
        else if (i < height-1)
          vert.draw(x + 320, y - horz.get_height() + 100 - 16);
      }

      //std::cout << tilemap[width * i + j] << " ";
    }
    //std::cout << std::endl;
  }
}

/* EOF */
