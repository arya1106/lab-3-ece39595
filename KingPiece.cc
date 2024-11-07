#include "KingPiece.hh"
#include "ChessPiece.hh"

namespace Student {

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column)
      : ChessPiece(board, color, row, column) {
        board.kings.emplace_back(this);
      }

KingPiece::~KingPiece() {
  m_board.kings.erase(std::find(m_board.kings.begin(), m_board.kings.end(), this));
}

bool KingPiece::canMoveToLocation(int toRow, int toColumn) {
  if (toRow == m_row && toColumn == m_column) {
    return false;
  }
  ChessPiece *toPiece = m_board.getPiece(toRow, toColumn);
  if (toPiece && toPiece->getColor() == m_color) {
    return false;
  }
  if (abs(toRow-m_row) <= 1 && abs(toColumn-m_column) <= 1) {
    return true;
  }
  return false;
}
const char *KingPiece::toString() {
  if (m_color == Color::White) {
    return "♔";
  } else {
    return "♚";
  }
}
} // namespace Student