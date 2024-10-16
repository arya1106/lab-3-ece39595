#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <assert.h>
#include <iostream>

void test_part1_4x4_1() {
  // Config file content:
  // 0
  // 4 4
  // w r 3 2
  // b b 1 3
  // b r 1 1
  // w r 2 3
  // ~
  // isValidScan

  // Corresponding code
  Student::ChessBoard sBoard(4, 4);
  std::cout << sBoard.displayBoard().str();
  sBoard.createChessPiece(White, Rook, 3, 2);
  std::cout << sBoard.displayBoard().str();
  sBoard.createChessPiece(Black, Bishop, 1, 3);
  std::cout << sBoard.displayBoard().str();
  sBoard.createChessPiece(Black, Rook, 1, 1);
  std::cout << sBoard.displayBoard().str();
  sBoard.createChessPiece(White, Rook, 2, 3);
  std::cout << sBoard.displayBoard().str();

  // Calls isValidMove() from every position to every
  // other position on the chess board for all pieces.

  return;
}

int main() {
  test_part1_4x4_1();
  return EXIT_SUCCESS;
}
