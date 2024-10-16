#include "ChessPiece.hh"
namespace Student {

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column)
    : m_board(board), m_color(color), m_row(row), m_column(column) {}

Color ChessPiece::getColor() { return m_color; }

Type ChessPiece::getType() { return m_type; }

int ChessPiece::getRow() { return m_row; }

int ChessPiece::getColumn() { return m_column; }

void ChessPiece::setPosition(int row, int colmun) {
  m_row = row;
  m_column = colmun;
}
} // namespace Student