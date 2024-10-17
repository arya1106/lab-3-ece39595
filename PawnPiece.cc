#include "PawnPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <cstring>
#include <sstream>

namespace Student {

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
  bool canDoubleMove =
      (m_color == Color::Black && m_row == 1) ||
      (m_color == Color::White && m_row == (m_board.getNumRows() - 2));
  ChessPiece *toPiece = m_board.getPiece(toRow, toColumn);
  if (toPiece && toPiece->getColor() == m_color) {
    // attacking same color
    return false;
  } else if (!toPiece && (toColumn != m_column)) {
    // moving horiz without attacking
    return false;
  }
  if (canDoubleMove) {
    if (m_color == Color::Black) {
      bool validMove =
          toColumn == m_column && (toRow == m_row + 2 || toRow == m_row + 1);
      return validMove && toPiece == nullptr;
    } else {
      bool validMove =
          toColumn == m_column && (toRow == m_row - 2 || toRow == m_row - 1);
      return validMove && toPiece == nullptr;
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
    bool out =
        (toPiece && attackValidBlack) || (!toPiece && nonAttackValidBlack);
    return out;
  } else {
    bool out =
        (toPiece && attackValidWhite) || (!toPiece && nonAttackValidWhite);
    return out;
  }
};

const char *PawnPiece::toString() {
  std::stringstream output;
  if (m_color == Color::White) {
    output << "\u2659";
  } else {
    output << "\u265F";
  }
  std::strcpy(m_stringBuffer, output.str().c_str());
  return m_stringBuffer;
};
} // namespace Student