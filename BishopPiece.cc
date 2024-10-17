#include "BishopPiece.hh"
#include "ChessBoard.hh"
#include <cstring>
#include <sstream>

namespace Student {

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
  if (toRow == m_row && toColumn == m_column) {
    return false;
  }
  ChessPiece *toPiece = m_board.getPiece(toRow, toColumn);
  if (toPiece && toPiece->getColor() == m_color) {
    return false;
  }
  bool isDiag = std::abs(m_row - toRow) == std::abs(m_column - toColumn);
  if (!isDiag) {
    return false;
  }
  bool movingRight = (toColumn - m_column) > 0;
  bool movingDown = (toRow - m_row) > 0;
  int rowToCheck = m_row;
  int colToCheck = m_column;
  if (movingDown && movingRight) {
    rowToCheck++;
    colToCheck++;
    while (rowToCheck < toRow && colToCheck < toColumn) {
      if (m_board.getPiece(rowToCheck, colToCheck)) {
        return false;
      }
      rowToCheck++;
      colToCheck++;
    }
  } else if (movingDown && !movingRight) {
    rowToCheck++;
    colToCheck--;
    while (rowToCheck < toRow && colToCheck > toColumn) {
      if (m_board.getPiece(rowToCheck, colToCheck)) {
        return false;
      }
      rowToCheck++;
      colToCheck--;
    }
  } else if (!movingDown && movingRight) {
    rowToCheck--;
    colToCheck++;
    while (rowToCheck > toRow && colToCheck < toColumn) {
      if (m_board.getPiece(rowToCheck, colToCheck)) {
        return false;
      }
      rowToCheck--;
      colToCheck++;
    }
  } else if (!movingDown && !movingRight) {
    rowToCheck--;
    colToCheck--;
    while (rowToCheck > toRow && colToCheck > toColumn) {
      if (m_board.getPiece(rowToCheck, colToCheck)) {
        return false;
      }
      rowToCheck--;
      colToCheck--;
    }
  }
  return true;
}

const char *BishopPiece::toString() {
  std::stringstream output;
  if (m_color == Color::White) {
    output << "\u2657";
  } else {
    output << "\u265D";
  }
  std::strcpy(m_stringBuffer, output.str().c_str());
  return m_stringBuffer;
}
} // namespace Student