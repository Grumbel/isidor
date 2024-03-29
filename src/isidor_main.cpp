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
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include "isotile_layer.hpp"

#include "datadir.hpp"
#include "isowall_layer.hpp"
#include "isidor_main.hpp"

IsidorMain::IsidorMain()
{
}

IsidorMain::~IsidorMain()
{
}

int
IsidorMain::main(int argc, char** argv)
{
  std::cout << "Isidor V0.0 - " << isidor::g_datadir << std::endl;
  try {
    CL_SetupCore::init();
    CL_SetupDisplay::init();
    CL_SetupGL::init();

    {
      CL_DisplayWindow window("Isidor V0.1", 800, 600);

      IsotileLayer layer1(isidor::g_datadir + "/maps/wtest.png");
      IsotileLayer layer2(isidor::g_datadir + "/maps/tilemap2.png");
      IsotileLayer layer3(isidor::g_datadir + "/maps/tilemap3.png");
      IsotileLayer layer4(isidor::g_datadir + "/maps/tilemap4.png");
      IsowallLayer layer5(isidor::g_datadir + "/maps/wtest2.png");

      while (!CL_Keyboard::get_keycode(CL_KEY_ESCAPE))
      {
        CL_Display::clear();
        layer1.draw(0);
        layer2.draw(0);
        layer3.draw(0);
        layer4.draw(0);
        layer5.draw();
        CL_Display::flip();
        CL_System::keep_alive();
      }
    }

    CL_SetupGL::deinit();
    CL_SetupDisplay::deinit();
    CL_SetupCore::deinit();
  } catch(CL_Error& err) {
    std::cout << "CL_Error: " << err.message << std::endl;
  }

  std::cout << "Thanks for using Isidor!" << std::endl;
  return 0;
}

/* EOF */
