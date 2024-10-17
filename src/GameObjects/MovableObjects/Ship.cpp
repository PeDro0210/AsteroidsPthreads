#include "../../Ui/Ui.h"
#include "MovableObjects.h"

Ship::Ship(int id)
    : MovableObject(0, 0, FacingUp), // Pass the settings reference
      id(id), orientation(FacingUp), icon('A'), lifes(3) {
  // Constructor body (optional)
}
