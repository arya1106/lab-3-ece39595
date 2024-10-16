#include "BishopPiece.hh"
#include <cstring>
#include <sstream>

namespace Student {

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
  return std::abs(m_row - toRow) == std::abs(m_column - toColumn);
}

const char *BishopPiece::toString() {
  std::stringstream output;
  if (m_color == Color::Black) {
    output << "\u2657" << getColChar() << getRowChar();
  } else {
    output << "\u265D" << getColChar() << getRowChar();
  }
  std::strcpy(m_stringBuffer, output.str().c_str());
  return m_stringBuffer;
}
} // namespace Student