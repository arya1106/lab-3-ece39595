#include "BishopPiece.hh"
#include <cstring>
#include <sstream>

namespace Student {

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
  return std::abs(m_row - toRow) == std::abs(m_column - toColumn);
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