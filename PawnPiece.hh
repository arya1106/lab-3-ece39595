#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student {
class PawnPiece : public ChessPiece {
private:
  bool canDoubleMove = false;

public:
  bool canMoveToLocation(int toRow, int toColumn);
  const char *toString();
};
} // namespace Student

#endif
