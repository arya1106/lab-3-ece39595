#include "KingPiece.hh"
#include "ChessPiece.hh"
namespace Student {
bool KingPiece::canMoveToLocation(int toRow, int toColumn) { return true; }
const char *KingPiece::toString() {
  if (m_color == Color::White) {
    return "♔";
  } else {
    return "♚";
  }
}
} // namespace Student