#include "PawnPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <sstream>

namespace Student {

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
  bool canDoubleMove =
      (m_color == Color::Black && m_row == 1) ||
      (m_color == Color::White && m_row == (m_board.getNumRows() - 2));
  if (canDoubleMove) {
    if (m_color == Color::Black) {
      return toColumn == m_column && (toRow == m_row + 2 || toRow == m_row + 1);
    } else {
      return toColumn == m_column && (toRow == m_row - 2 || toRow == m_row - 1);
    }
  }

  bool nonAttackValidWhite = toColumn == m_column && toRow == m_row - 1;
  bool nonAttackValidBlack = toColumn == m_column && toRow == m_row + 1;
  bool attackValidWhite =
      ((toColumn == m_column + 1) || (toColumn == m_column - 1)) &&
      toRow == m_row - 1;
  bool attackValidBlack =
      ((toColumn == m_column + 1) || (toColumn == m_column - 1)) &&
      toRow == m_row + 1;

  if (m_color == Color::Black) {
    bool out = (attacking && attackValidBlack) || nonAttackValidBlack;
    attacking = false;
    return out;
  } else {
    bool out = (attacking && attackValidWhite) || nonAttackValidWhite;
    attacking = false;
    return out;
  }
};

const char *PawnPiece::toString() {
  std::stringstream output;
  if (m_color == Color::Black) {
    output << "\u2659" << getColChar() << getRowChar();
  } else {
    output << "\u265F" << getColChar() << getRowChar();
  }
  std::strcpy(m_stringBuffer, output.str().c_str());
  return m_stringBuffer;
};
} // namespace Student