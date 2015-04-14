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

#ifndef HEADER_ISOWALL_LAYER_HXX
#define HEADER_ISOWALL_LAYER_HXX

#include <vector>
#include <ClanLib/Display/surface.h>

/** */
class IsowallLayer
{
private:
  std::vector<int> tilemap;
  int width;
  int height;

  CL_Surface horz;
  CL_Surface vert;
public:
  IsowallLayer(std::string filename);
  
  void draw();
private:
  IsowallLayer (const IsowallLayer&);
  IsowallLayer& operator= (const IsowallLayer&);
};

#endif

/* EOF */
