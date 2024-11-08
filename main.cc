#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <csignal>
#include <iostream>
#include <sys/signal.h>

void isValidScanS(Student::ChessBoard &board) {
  for (int i = 0; i < board.getNumRows(); i++) {
    for (int j = 0; j < board.getNumCols(); j++) {
      Student::ChessPiece *piece = board.getPiece(i, j);
      if (piece) {
        for (int a = 0; a < board.getNumRows(); a++) {
          for (int b = 0; b < board.getNumCols(); b++) {
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
  isValidScanS(sBoard);

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
  isValidScanS(sBoard);
}

void test_part_4x4_5() {
  Student::ChessBoard sBoard(4, 4);
  sBoard.createChessPiece(Black, Bishop, 0, 1);
  sBoard.createChessPiece(Black, Bishop, 1, 1);
  sBoard.createChessPiece(Black, Bishop, 2, 1);
  sBoard.createChessPiece(White, Pawn, 2, 0);
  // Calls isValidMove() from every position to every
  // other position on the chess board for all pieces.
  std::cout << sBoard.displayBoard().str() << std::endl;
  isValidScanS(sBoard);
}

void test_part_6x6_2() {

  Student::ChessBoard sBoard(6, 6);
  sBoard.createChessPiece(Black, Rook, 2, 2);
  sBoard.createChessPiece(White, Bishop, 1, 1);
  sBoard.createChessPiece(White, Bishop, 0, 0);
  sBoard.createChessPiece(White, Rook, 1, 4);
  sBoard.createChessPiece(White, Pawn, 3, 3);
  sBoard.createChessPiece(Black, Pawn, 2, 1);

  // Calls isValidMove() from every position to every
  // other position on the chess board for all pieces.
  std::cout << sBoard.displayBoard().str() << std::endl;
  isValidScanS(sBoard);
}

void test() {
  Student::ChessBoard sBoard(4, 4);

  sBoard.createChessPiece(White, Bishop, 2, 2);
  sBoard.createChessPiece(White, Rook, 1, 0);
  sBoard.createChessPiece(White, Pawn, 1, 1);
  sBoard.createChessPiece(Black, Pawn, 0, 1);

  sBoard.movePiece(1,0,3,0);
  
  sBoard.movePiece(0,1,1,1);
  sBoard.movePiece(2,2,3,3);
  sBoard.movePiece(1,1,2,1);
  sBoard.movePiece(2,3,0,3);
  sBoard.movePiece(3,0,3,2);
  sBoard.movePiece(2,1,3,1);
  sBoard.movePiece(3,2,2,2);
  sBoard.movePiece(0,0,3,2);
  sBoard.movePiece(2,0,0,2);
  sBoard.displayBoard();
}

void test1() {
  Student::ChessBoard sBoard(4, 4);

  sBoard.createChessPiece(White, Rook, 3, 2);
  sBoard.createChessPiece(Black, Bishop, 1, 3);
  sBoard.createChessPiece(Black, Rook, 1, 1);
  sBoard.createChessPiece(White, Rook, 2, 3);
  sBoard.createChessPiece(Black, King, 0, 0);
  sBoard.createChessPiece(White, King, 3, 0);

  sBoard.movePiece(3,0,2,0);
  isValidScanS(sBoard);
  sBoard.movePiece(1,3,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,3,1,3);
  isValidScanS(sBoard);
  sBoard.movePiece(1,1,0,1);
  isValidScanS(sBoard);
  sBoard.movePiece(1,2,0,3);
  isValidScanS(sBoard);
  sBoard.movePiece(2,0,3,0);
  isValidScanS(sBoard);
  sBoard.movePiece(0,1,2,1);
  isValidScanS(sBoard);
  sBoard.movePiece(3,2,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,1,0,1);
  isValidScanS(sBoard);
  sBoard.movePiece(0,1,3,2);
  isValidScanS(sBoard);
  sBoard.movePiece(1,3,1,0);
  isValidScanS(sBoard);
  sBoard.movePiece(0,0,1,0);
  isValidScanS(sBoard);
  sBoard.movePiece(0,2,3,2);
  isValidScanS(sBoard);
  sBoard.movePiece(1,0,1,1);
  isValidScanS(sBoard);
  sBoard.movePiece(2,0,3,3);
  isValidScanS(sBoard);
  sBoard.movePiece(3,2,3,1);
  isValidScanS(sBoard);
  sBoard.movePiece(1,1,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(3,1,3,2);
  isValidScanS(sBoard);
  sBoard.movePiece(0,2,0,3);
  isValidScanS(sBoard);
  sBoard.movePiece(1,3,2,3);
  isValidScanS(sBoard);
  sBoard.movePiece(3,2,2,2);
  isValidScanS(sBoard);
  sBoard.movePiece(0,3,1,3);
  isValidScanS(sBoard);
  sBoard.movePiece(3,0,2,0);
  isValidScanS(sBoard);
  sBoard.movePiece(0,1,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,3,1,0);
  isValidScanS(sBoard);
  sBoard.movePiece(2,0,3,1);
  isValidScanS(sBoard);
  sBoard.movePiece(1,3,0,3);
  isValidScanS(sBoard);
  sBoard.movePiece(2,2,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(0,3,1,3);
  isValidScanS(sBoard);
  sBoard.movePiece(3,1,1,2);
  isValidScanS(sBoard);
  sBoard.movePiece(0,2,0,1);
  isValidScanS(sBoard);
  sBoard.movePiece(1,3,1,2);
  isValidScanS(sBoard);
  sBoard.movePiece(0,1,2,1);
  isValidScanS(sBoard);
  sBoard.movePiece(1,2,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,0,0,0);
  isValidScanS(sBoard);
  sBoard.movePiece(3,1,2,0);
  isValidScanS(sBoard);
  sBoard.movePiece(0,2,1,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,0,3,0);
  isValidScanS(sBoard);
  sBoard.movePiece(1,2,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(0,1,1,1);
  isValidScanS(sBoard);
  sBoard.movePiece(2,1,2,3);
  isValidScanS(sBoard);
  sBoard.movePiece(0,2,0,1);
  isValidScanS(sBoard);
  sBoard.movePiece(2,3,2,0);
  isValidScanS(sBoard);
  sBoard.movePiece(0,1,1,2);
  isValidScanS(sBoard);
  sBoard.movePiece(1,2,0,0);
  isValidScanS(sBoard);
  sBoard.movePiece(2,0,2,2);
  isValidScanS(sBoard);
  sBoard.movePiece(1,2,1,3);
  isValidScanS(sBoard);
  sBoard.movePiece(2,2,2,0);
  isValidScanS(sBoard);
  sBoard.movePiece(1,3,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,2,2,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,0,2,1);
  isValidScanS(sBoard);
  sBoard.movePiece(0,2,0,3);
  isValidScanS(sBoard);
  sBoard.movePiece(3,0,2,0);
  isValidScanS(sBoard);
  sBoard.movePiece(0,3,0,2);
  isValidScanS(sBoard);
  sBoard.movePiece(3,0,2,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,1,1,1);
  isValidScanS(sBoard);
  sBoard.movePiece(0,2,0,3);
  isValidScanS(sBoard);
  sBoard.movePiece(1,1,0,1);
  isValidScanS(sBoard);
  sBoard.movePiece(0,3,1,3);
  isValidScanS(sBoard);
  sBoard.movePiece(1,0,3,3);
  isValidScanS(sBoard);
  sBoard.movePiece(0,1,2,1);
  isValidScanS(sBoard);
  sBoard.movePiece(1,3,1,2);
  isValidScanS(sBoard);
  sBoard.movePiece(2,1,1,1);
  isValidScanS(sBoard);
  sBoard.movePiece(1,2,0,2);
  isValidScanS(sBoard);
  sBoard.displayBoard();
}

void test2() {
  Student::ChessBoard sBoard(8, 8);
  sBoard.createChessPiece(Black, Rook, 3, 0);
  sBoard.createChessPiece(Black, Rook, 3, 5);
  sBoard.createChessPiece(Black, Pawn, 5, 3);
  sBoard.createChessPiece(White, Rook, 1, 1);
  sBoard.createChessPiece(White, Bishop, 2, 2);
  sBoard.createChessPiece(White, Pawn, 3, 3);
  sBoard.createChessPiece(Black, Rook, 0, 3);
  sBoard.createChessPiece(White, Bishop, 2, 3);
  sBoard.createChessPiece(White, Rook, 3, 5);
  sBoard.createChessPiece(Black, Bishop, 2, 1);
  sBoard.createChessPiece(Black, Rook, 4, 0);
  sBoard.createChessPiece(White, Pawn, 1, 3);
  sBoard.createChessPiece(White, Bishop, 5, 0);
  sBoard.createChessPiece(White, Pawn, 4, 6);
  sBoard.createChessPiece(White, Pawn, 1, 3);
  sBoard.createChessPiece(Black, Rook, 6, 0);
  sBoard.createChessPiece(Black, King, 5, 7);
  sBoard.createChessPiece(White, King, 1, 4);
  isValidScanS(sBoard);
  sBoard.movePiece(1, 4, 2, 5);
  sBoard.movePiece(3, 0, 3, 1);
  sBoard.movePiece(3, 5, 3, 6);
  sBoard.movePiece(0, 4, 0, 6);
  sBoard.movePiece(4, 0, 4, 6);
  sBoard.movePiece(1, 1, 2, 1);
  sBoard.movePiece(4, 6, 4, 7);
  sBoard.movePiece(6, 2, 1, 1);
  isValidScanS(sBoard);
  sBoard.movePiece(2, 1, 1, 1);
  sBoard.movePiece(3, 1, 6, 1);
  sBoard.movePiece(1, 1, 5, 1);
  sBoard.movePiece(7, 7, 7, 1);
  sBoard.movePiece(4, 7, 3, 7);
  sBoard.movePiece(3, 6, 1, 6);
  sBoard.movePiece(0, 3, 0, 6);
  sBoard.movePiece(0, 1, 4, 3);
  isValidScanS(sBoard);
  sBoard.movePiece(2, 2, 3, 1);
  sBoard.movePiece(3, 7, 3, 4);
  sBoard.movePiece(5, 1, 5, 3);
  sBoard.movePiece(2, 2, 1, 3);
  sBoard.movePiece(3, 4, 5, 4);
  sBoard.movePiece(2, 3, 3, 2);
  sBoard.movePiece(6, 1, 6, 3);
  sBoard.movePiece(1, 5, 1, 5);
  isValidScanS(sBoard);
  sBoard.movePiece(5, 0, 4, 1);
  sBoard.movePiece(0, 6, 0, 4);
  sBoard.movePiece(3, 2, 0, 5);
  sBoard.movePiece(3, 3, 4, 2);
  sBoard.movePiece(0, 4, 2, 4);
  sBoard.movePiece(2, 5, 3, 6);
  sBoard.movePiece(6, 3, 6, 5);
  sBoard.movePiece(3, 0, 3, 5);
  isValidScanS(sBoard);
  sBoard.movePiece(5, 3, 4, 3);
  sBoard.movePiece(2, 4, 3, 4);
  sBoard.movePiece(3, 6, 2, 7);
  sBoard.movePiece(2, 3, 6, 1);
  sBoard.movePiece(6, 5, 6, 6);
  sBoard.movePiece(3, 1, 6, 4);
  sBoard.movePiece(6, 0, 5, 0);
  sBoard.movePiece(0, 0, 1, 3);
  isValidScanS(sBoard);
  sBoard.movePiece(1, 6, 1, 4);
  sBoard.movePiece(6, 6, 0, 6);
  sBoard.movePiece(6, 4, 4, 6);
  sBoard.movePiece(5, 6, 4, 2);
  sBoard.movePiece(5, 7, 6, 7);
  sBoard.movePiece(4, 1, 5, 2);
  sBoard.movePiece(5, 0, 3, 0);
  sBoard.movePiece(2, 2, 2, 3);
  isValidScanS(sBoard);
  sBoard.movePiece(5, 2, 6, 3);
  sBoard.movePiece(3, 4, 3, 3);
  sBoard.movePiece(4, 3, 4, 1);
  sBoard.movePiece(2, 6, 0, 6);
  sBoard.movePiece(5, 4, 3, 4);
  sBoard.movePiece(1, 3, 0, 3);
  sBoard.movePiece(3, 3, 5, 3);
  sBoard.movePiece(4, 5, 4, 7);
  isValidScanS(sBoard);
  sBoard.movePiece(4, 1, 6, 1);
  sBoard.movePiece(3, 4, 6, 4);
  sBoard.movePiece(6, 1, 6, 2);
  sBoard.movePiece(0, 5, 2, 1);
  sBoard.movePiece(6, 7, 7, 7);
  sBoard.movePiece(4, 6, 1, 3);
  sBoard.movePiece(3, 0, 3, 7);
  sBoard.movePiece(7, 7, 2, 5);
  isValidScanS(sBoard);
  sBoard.displayBoard();
}

int main() {
  // test_part1_4x4_1();
  // test_part_4x4_3();
  // test_part_4x4_5();
  // test_part_6x6_2();
  // test();
  //test1();
  test2();
  return EXIT_SUCCESS;
}
