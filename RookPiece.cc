#include "RookPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <cstring>
#include <sstream>

namespace Student {
bool RookPiece::canMoveToLocation(int toRow, int toColumn) {
  bool horiz = (m_row == toRow) && (m_column != toColumn);
  bool vert = (m_row != toRow) && (m_column == toColumn);
  ChessPiece *toPiece = m_board.getPiece(toRow, toColumn);
  if (toPiece && toPiece->getColor() == m_color) {
    return false;
  }

  if (horiz) {
    bool movingRight = (toColumn - m_column) > 0;
    if (movingRight) {
      for (int colToCheck = m_column + 1; colToCheck < toColumn; colToCheck++) {
        if (m_board.getPiece(m_row, colToCheck)) {
          return false;
        }
      }
    } else {
      for (int colToCheck = m_column - 1; colToCheck < toColumn; colToCheck--) {
        if (m_board.getPiece(m_row, colToCheck)) {
          return false;
        }
      }
    }
    return true;
  } else if (vert) {
    bool movingDown = (toRow - m_row) > 0;
    if (movingDown) {
      for (int rowToCheck = m_row + 1; rowToCheck < toRow; rowToCheck++) {
        if (m_board.getPiece(rowToCheck, m_column)) {
          return false;
        }
      }
    } else {
      for (int rowToCheck = m_row - 1; rowToCheck > toRow; rowToCheck--) {
        if (m_board.getPiece(rowToCheck, m_column)) {
          return false;
        }
      }
    }
    return true;
  } else {
    return false;
  }
}

const char *RookPiece::toString() {
  std::stringstream output;
  if (m_color == Color::White) {
    output << "\u2656";
  } else {
    output << "\u265C";
  }
  std::strcpy(m_stringBuffer, output.str().c_str());
  return m_stringBuffer;
}
} // namespace Student