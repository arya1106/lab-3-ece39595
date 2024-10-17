#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student {
class PawnPiece : public ChessPiece {

public:
  PawnPiece(ChessBoard &board, Color color, int row, int column)
      : ChessPiece(board, color, row, column) {
    m_type = Type::Pawn;
  }

public:
  bool attacking = false;

public:
  bool canMoveToLocation(int toRow, int toColumn);
  const char *toString();
};
} // namespace Student

#endif
