#include "ftxui/screen/box.hpp"

#include <algorithm>

namespace ftxui {
/// @return the biggest Box contained in both |a| and |b|.
/// @ingroup screen
// static
Box Box::Intersection(Box a, Box b) {
  return Box{
      std::max(a.x_min, b.x_min),
      std::min(a.x_max, b.x_max),
      std::max(a.y_min, b.y_min),
      std::min(a.y_max, b.y_max),
  };
}

/// @return whether (x,y) is contained inside the box.
/// @ingroup screen
bool Box::Contain(int x, int y) {
  return x_min <= x &&  //
         x_max >= x &&  //
         y_min <= y &&  //
         y_max >= y;
}

}  // namespace ftxui

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
