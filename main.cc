#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <csignal>
#include <iostream>
#include <sys/signal.h>

void isValidScan(Student::ChessBoard &board) {
  for (int i = 0; i < board.getNumRows(); i++) {
    for (int j = 0; j < board.getNumCols(); j++) {
      Student::ChessPiece *piece = board.getPiece(i, j);
      if (piece) {
        for (int a = 0; a < board.getNumRows(); a++) {
          for (int b = 0; b < board.getNumCols(); b++) {
            if (a == 1 && b == 1 && i == 2 && j == 1) {
              raise(SIGTRAP);
            }
            std::cout << piece->toString() << " at " << piece->getRow() << ","
                      << piece->getColumn() << " can move to " << a << "," << b
                      << ": " << piece->canMoveToLocation(a, b) << std::endl;
          }
        }
      }
    }
  }
}

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
  sBoard.createChessPiece(White, Rook, 1, 0);
  sBoard.createChessPiece(Black, Bishop, 2, 1);
  sBoard.createChessPiece(Black, Rook, 1, 2);
  sBoard.createChessPiece(White, Rook, 2, 3);

  // Calls isValidMove() from every position to every
  // other position on the chess board for all pieces.
  std::cout << sBoard.displayBoard().str() << std::endl;
  isValidScan(sBoard);

  return;
}

void test_part_4x4_3() {
  Student::ChessBoard sBoard(4, 4);
  sBoard.createChessPiece(White, Bishop, 2, 2);
  sBoard.createChessPiece(White, Rook, 1, 0);
  sBoard.createChessPiece(White, Pawn, 1, 1);
  sBoard.createChessPiece(Black, Pawn, 0, 1);

  // Calls isValidMove() from every position to every
  // other position on the chess board for all pieces.
  std::cout << sBoard.displayBoard().str() << std::endl;
  isValidScan(sBoard);
}

int main() {
  // test_part1_4x4_1();
  test_part_4x4_3();
  return EXIT_SUCCESS;
}
