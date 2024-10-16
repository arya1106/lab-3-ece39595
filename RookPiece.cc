#include "RookPiece.hh"
#include <sstream>

namespace Student {
bool RookPiece::canMoveToLocation(int toRow, int toColumn) {
  return (m_row == toRow) ^ (m_column == toColumn);
}

const char *RookPiece::toString() {
  std::stringstream output;
  if (m_color == Color::Black) {
    output << "\u2656" << getColChar() << getRowChar();
  } else {
    output << "\u265C" << getColChar() << getRowChar();
  }
  std::strcpy(m_stringBuffer, output.str().c_str());
  return m_stringBuffer;
}
} // namespace Student