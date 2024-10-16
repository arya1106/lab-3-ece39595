#include "PawnPiece.hh"
namespace Student {
bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
  bool nonAttackValid =
      toColumn == m_column && (toRow == m_row + 1 || toRow == m_row - 1);
  bool attackValid =
      ((toColumn == m_column + 1) || (toColumn == m_column - 1)) &&
      (toRow == m_row + 1 || toRow == m_row - 1);
  return nonAttackValid && attackValid;
};

const char *PawnPiece::toString() {

};
} // namespace Student