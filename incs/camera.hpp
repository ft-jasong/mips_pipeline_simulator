#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "structs.hpp"
# include "../raylib/src/raylib.h"

bool	init_camera(Camera2D &camera);
bool	manipulate_camera(Camera2D &camera);

#endif