#include "ChessBoard.hh"
#include "BishopPiece.hh"
#include "Chess.h"
#include "ChessPiece.hh"
#include "KingPiece.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include <algorithm>
#include <vector>

using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol)
    : numRows(numRow), numCols(numCol),
      board(numRows, std::vector<ChessPiece *>(numCol, nullptr)) {}

ChessBoard::~ChessBoard() {
  std::for_each(board.begin(), board.end(), [](std::vector<ChessPiece *> &row) {
    std::for_each(row.begin(), row.end(), [](ChessPiece *ptr) { delete ptr; });
  });
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow,
                                  int startColumn) {
  switch (ty) {
  case Pawn:
    board.at(startRow).at(startColumn) =
        new PawnPiece(*this, col, startRow, startColumn);
    break;
  case Bishop:
    board.at(startRow).at(startColumn) =
        new BishopPiece(*this, col, startRow, startColumn);
    break;
  case Rook:
    board.at(startRow).at(startColumn) =
        new RookPiece(*this, col, startRow, startColumn);
    break;
  case King:
    board.at(startRow).at(startColumn) =
        new KingPiece(*this, col, startRow, startColumn);
    break;
  }
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow,
                           int toColumn) {
  ChessPiece *fromPiece = getPiece(fromRow, fromColumn);
  if (!fromPiece || !fromPiece->canMoveToLocation(toRow, toColumn)) {
    return false;
  }

  ChessPiece *toPiece = getPiece(toRow, toColumn);
  if (toPiece)
  {
    delete toPiece;
  }

  board[toRow][toColumn] = fromPiece;
  board[fromRow][fromColumn] = NULL;
  
  return true;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow,
                             int toColumn) {
  ChessPiece *fromPiece = getPiece(fromRow, fromColumn);
  // ChessPiece *toPiece = getPiece(toRow, toColumn);

  // if (toPiece && (toPiece->getType() == Type::Pawn)) {
  //   // special case for pawn attacking
  //   ((PawnPiece *)toPiece)->attacking = true;
  //   return fromPiece->canMoveToLocation(toRow, toColumn);
  // } else if (toPiece) {
  //   // check to make sure you're not attacking your own pieces
  //   return (!(toPiece->getColor() == fromPiece->getColor())) &&
  //          (fromPiece->canMoveToLocation(toRow, toColumn));
  // } else {
  return fromPiece->canMoveToLocation(toRow, toColumn);
  // }
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
  if (ChessPiece *defPiece = getPiece(row, column)) {
    for (int rowToCheck = 0; rowToCheck < numRows; rowToCheck++) {
      for (int colToCheck = 0; colToCheck < numCols; colToCheck++) {
        ChessPiece *attackPiece = getPiece(rowToCheck, colToCheck);
        if (pieceUnderThreatSingle(defPiece, attackPiece)) {
          return true;
        }
      }
    }
  }
  return false;
}

std::ostringstream ChessBoard::displayBoard() {
  std::ostringstream outputString;
  // top scale
  outputString << "  ";
  for (int i = 0; i < numCols; i++) {
    outputString << i;
  }
  outputString << std::endl << "  ";
  // top border
  for (int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl;

  for (int row = 0; row < numRows; row++) {
    outputString << row << "|";
    for (int column = 0; column < numCols; column++) {
      ChessPiece *piece = board.at(row).at(column);
      outputString << (piece == nullptr ? " " : piece->toString());
    }
    outputString << "|" << std::endl;
  }

  // bottom border
  outputString << "  ";
  for (int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl << std::endl;

  return outputString;
}

bool ChessBoard::pieceUnderThreatSingle(ChessPiece *defPiece,
                                        ChessPiece *attackPiece) {
  if ((!attackPiece) || attackPiece->getColor() == defPiece->getColor()) {
    return false;
  }
  return attackPiece->canMoveToLocation(defPiece->getRow(),
                                        defPiece->getColumn());
}
