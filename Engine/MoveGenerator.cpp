#include "MoveGenerator.h"
#include "Game.h"
extern Game* game;

std::list<Move *> MoveGenerator::generateLegalMoves(ChessBoard* chessBoard, std::pair<int, int> startingSquare, Color friendlyPieceColor)
{
    std::list<Move*> legalMoves;

    auto piece = chessBoard->boardSquares[startingSquare.first][startingSquare.second]->getPiece();

    if (piece->getShortName() == "Q" || piece->getShortName() == "R" || piece->getShortName() == "B") {
        MoveGenerator::generateLegalMovesForSlidingPieces(chessBoard, startingSquare, piece, friendlyPieceColor, legalMoves);
    } else if (piece->getShortName() == "P") {
        MoveGenerator::generateLegalMovesForPawn(chessBoard, startingSquare, piece, friendlyPieceColor, legalMoves);
    } else if (piece->getShortName() == "N") {
        MoveGenerator::generateLegalMovesForKnight(chessBoard, startingSquare, piece, friendlyPieceColor, legalMoves);
    } else if (piece->getShortName() == "K") {
        MoveGenerator::generateLegalMovesForKing(chessBoard, startingSquare, piece, friendlyPieceColor, legalMoves);
    }

    MoveGenerator::printLegalMoves(legalMoves);
    return legalMoves;
}

std::list<Move *> MoveGenerator::generateAllLegalMoves(ChessBoard *chessBoard, Color friendlyPieceColor)
{
    std::list<Move*> legalMoves;
//    Color opponentsColor = friendlyPieceColor == Color::White ? Color::Black : Color::White;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            auto piece = chessBoard->boardSquares[x][y]->getPiece();
            if (piece != nullptr) {
                if (chessBoard->boardSquares[x][y]->getPiece()->getColor() == friendlyPieceColor) {
                    if (piece->getShortName() == "Q" || piece->getShortName() == "R" || piece->getShortName() == "B") {
                        MoveGenerator::generateLegalMovesForSlidingPieces(chessBoard, std::make_pair(x, y), piece, friendlyPieceColor, legalMoves);
                    } else if (piece->getShortName() == "P") {
                        MoveGenerator::generateLegalMovesForPawn(chessBoard, std::make_pair(x, y), piece, friendlyPieceColor, legalMoves);
                    } else if (piece->getShortName() == "N") {
                        MoveGenerator::generateLegalMovesForKnight(chessBoard, std::make_pair(x, y), piece, friendlyPieceColor, legalMoves);
                    } else if (piece->getShortName() == "K") {
                        MoveGenerator::generateLegalMovesForKing(chessBoard, std::make_pair(x, y), piece, friendlyPieceColor, legalMoves);
                        MoveGenerator::generateLegalCastleMovesForKing(chessBoard, std::make_pair(x, y), piece, friendlyPieceColor, legalMoves);
                    }
                }
            }
        }
    }
    std::cout << "przed legal" << std::endl;
    MoveGenerator::printLegalMoves(legalMoves);
    return legalMoves;
}



bool MoveGenerator::isKingInCheck(ChessBoard *chessBoard, Color friendlyPieceColor)
{
    std::list<BoardSquare*> attackedSquares;
    getOpponentsAllAttackedSquares(chessBoard, friendlyPieceColor, attackedSquares);
    for (auto square : attackedSquares) {
        if (square->getPiece() != nullptr) {
            if (square->getPiece()->getName() == "King") {
                return true;
            }
        }
    }
    return false;
}

bool MoveGenerator::performMove(ChessBoard* chessBoard, Move *move)
{
    auto piece = chessBoard->boardSquares[move->from.first][move->from.second]->getPiece();
    chessBoard->boardSquares[move->to.first][move->to.second]->setPiece(piece);
    chessBoard->boardSquares[move->from.first][move->from.second]->resetPiece();


    if (piece->didPieceMove() == true)
    {
        piece->setMoved(true);
        return false;
    }
    return true;
}

void MoveGenerator::getOpponentsAllAttackedSquares(ChessBoard *chessBoard, Color friendlyPieceColor, std::list<BoardSquare *> &attackedSquares)
{
    std::list<Move*> legalMoves;
    Color opponentsColor = friendlyPieceColor == Color::White ? Color::Black : Color::White;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            auto piece = chessBoard->boardSquares[x][y]->getPiece();
            if (piece != nullptr) {
                if (chessBoard->boardSquares[x][y]->getPiece()->getColor() != friendlyPieceColor) {
                    if (piece->getShortName() == "Q" || piece->getShortName() == "R" || piece->getShortName() == "B") {
                        MoveGenerator::generateLegalMovesForSlidingPieces(chessBoard, std::make_pair(x, y), piece, opponentsColor, legalMoves);
                    } else if (piece->getShortName() == "P") {
                        MoveGenerator::generateAttackingMovesForPawn(chessBoard, std::make_pair(x, y), piece, opponentsColor, legalMoves);
                    } else if (piece->getShortName() == "N") {
                        MoveGenerator::generateLegalMovesForKnight(chessBoard, std::make_pair(x, y), piece, opponentsColor, legalMoves);
                    } else if (piece->getShortName() == "K") {
                        MoveGenerator::generateLegalMovesForKing(chessBoard, std::make_pair(x, y), piece, opponentsColor, legalMoves);
                    }
                }
            }
        }
    }
    for (auto move : legalMoves) {
        attackedSquares.push_back(chessBoard->boardSquares[move->to.first][move->to.second]);
    }
}

void MoveGenerator::generateLegalMovesForSlidingPieces(ChessBoard *chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move*>& legalMoves)
{
    auto directions = piece->getDirectionsOffsets();

    for (auto direction : directions) {
        int currentRow = startingSquare.first;
        int currentCol = startingSquare.second;
        currentRow += direction[0];
        currentCol += direction[1];

        while (currentRow < 8 && currentRow >= 0 && currentCol < 8 && currentCol >= 0) {
            if (chessBoard->boardSquares[currentRow][currentCol]->getPiece() != nullptr) {
                if (chessBoard->boardSquares[currentRow][currentCol]->getPiece()->getColor() == friendlyPieceColor) {
                    break;
                }
                legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));

                break;
            }
            legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));
            currentRow += direction[0];
            currentCol += direction[1];
        }
    }
}

void MoveGenerator::generateLegalMovesForPawn(ChessBoard *chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move *> &legalMoves)
{
    MoveGenerator::generateForwardMovesForPawn(chessBoard, startingSquare, piece, friendlyPieceColor, legalMoves);
    MoveGenerator::generateAttackingMovesForPawn(chessBoard, startingSquare, piece, friendlyPieceColor, legalMoves);
}

void MoveGenerator::generateLegalMovesForKing(ChessBoard *chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move *> &legalMoves)
{
    auto directions = piece->getDirectionsOffsets();

    for (auto direction : directions) {
        int currentRow = startingSquare.first + direction[0];
        int currentCol = startingSquare.second + direction[1];

        if (currentRow < 0 || currentRow > 7 || currentCol < 0 || currentCol > 7) {
            continue;
        }

        if (chessBoard->boardSquares[currentRow][currentCol]->getPiece() != nullptr) {
            if (chessBoard->boardSquares[currentRow][currentCol]->getPiece()->getColor() == friendlyPieceColor) {
                continue;
            }
            legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));
            continue;
        }
        legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));
    }


}

void MoveGenerator::generateLegalMovesForKnight(ChessBoard *chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move *> &legalMoves)
{
    auto directions = piece->getDirectionsOffsets();

    for (auto direction : directions) {
        int currentRow = startingSquare.first + direction[0];
        int currentCol = startingSquare.second + direction[1];
        if (currentRow < 0 || currentRow > 7 || currentCol < 0 || currentCol > 7) {
            continue;
        }

        if (chessBoard->boardSquares[currentRow][currentCol]->getPiece() != nullptr) {
            if (chessBoard->boardSquares[currentRow][currentCol]->getPiece()->getColor() == friendlyPieceColor) {
                continue;
            }
            legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));
            continue;
        }
        legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));
    }
}

void MoveGenerator::generateForwardMovesForPawn(ChessBoard *chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move *> &legalMoves)
{
    std::vector<int> directions;

    if (friendlyPieceColor == Color::White) {
        directions = {1, 0};
    } else {
        directions = {-1, 0};
    }

    int currentRow = startingSquare.first;
    int currentCol = startingSquare.second;

    currentRow += directions[0];

    if (currentRow < 0 || currentRow > 7 || currentCol < 0 || currentCol > 7) {
        return;
    }

    if (chessBoard->boardSquares[currentRow][currentCol]->getPiece() == nullptr) {
        legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));

        if (!piece->didPieceMove()) {
            currentRow += directions[0];;
            if (chessBoard->boardSquares[currentRow][currentCol]->getPiece() == nullptr) {
                legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));
            }
        }
    }
}

void MoveGenerator::generateAttackingMovesForPawn(ChessBoard *chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move *> &legalMoves)
{
    std::vector<std::vector<int>> directions;

    if (friendlyPieceColor == Color::White) {
        directions = {{1, 1}, {1, -1}};
    } else {
        directions = {{-1, -1}, {-1, 1}};
    }

    for (auto direction : directions) {
        int currentRow = startingSquare.first + direction[0];
        int currentCol = startingSquare.second + direction[1];

        if (currentRow < 0 || currentRow > 7 || currentCol < 0 || currentCol > 7) {
            continue;
        }

        if (chessBoard->boardSquares[currentRow][currentCol]->getPiece() != nullptr) {
            if (chessBoard->boardSquares[currentRow][currentCol]->getPiece()->getColor() != friendlyPieceColor) {
                legalMoves.push_back(new Move(startingSquare, std::make_pair(currentRow, currentCol)));
            }
        }
    }
}

void MoveGenerator::printLegalMoves(std::list<Move *> &legalMoves)
{
    for (auto move : legalMoves) {
        std::cout << move->from.first << move->from.second << " - " << move->to.first << move->to.second << std::endl;
    }
}

bool MoveGenerator::isSquareUnderAttack(int row, int col, std::list<BoardSquare*> attackedSquares)
{
    for (auto square : attackedSquares) {
        if (square->row == row && square->col == col) {
            return true;
        }
    }
    return false;
}

void MoveGenerator::generateLegalCastleMovesForKing(ChessBoard *chessBoard, std::pair<int, int> startingSquare, std::shared_ptr<Piece> piece, Color friendlyPieceColor, std::list<Move *> &legalMoves)
{
    std::list<BoardSquare*> attackedSquares;
    MoveGenerator::getOpponentsAllAttackedSquares(chessBoard, friendlyPieceColor, attackedSquares);
    if (!piece->didPieceMove()) {
        if (friendlyPieceColor == Color::White) {
            // queen side castle for white
            int row = 0;
            int col = 4;
            while (col >= 0) {
                col--;
                if (col == 0 && chessBoard->boardSquares[row][col]->getPiece() != nullptr && !chessBoard->boardSquares[row][col]->getPiece()->didPieceMove() && !isSquareUnderAttack(row, col, attackedSquares)) {
                    legalMoves.push_back(new Move(std::make_pair(0, 4), std::make_pair(row, col + 1), true));
                }
                if (chessBoard->boardSquares[row][col]->getPiece() != nullptr || isSquareUnderAttack(row, col, attackedSquares)) {
                    break;
                }
            }
            // king side castle for white
            row = 0;
            col = 4;
            while (col <= 7) {
                col++;
                if (col == 7 && chessBoard->boardSquares[row][col]->getPiece() != nullptr && !chessBoard->boardSquares[row][col]->getPiece()->didPieceMove() && !isSquareUnderAttack(row, col, attackedSquares)) {
                    legalMoves.push_back(new Move(std::make_pair(0, 4), std::make_pair(row, col - 1), true));
                }
                if (chessBoard->boardSquares[row][col]->getPiece() != nullptr || isSquareUnderAttack(row, col, attackedSquares)) {
                    break;
                }
            }
        } else if (friendlyPieceColor == Color::Black) {
            // queen side castle for black
            int row = 7;
            int col = 4;
            while (col >= 0) {
                col--;
                if (col == 0 && chessBoard->boardSquares[row][col]->getPiece() != nullptr && !chessBoard->boardSquares[row][col]->getPiece()->didPieceMove() && !isSquareUnderAttack(row, col, attackedSquares)) {
                    legalMoves.push_back(new Move(std::make_pair(7, 4), std::make_pair(row, col + 1), true));
                }
                if (chessBoard->boardSquares[row][col]->getPiece() != nullptr || isSquareUnderAttack(row, col, attackedSquares)) {
                    break;
                }
            }
            // queen side castle for white
            row = 7;
            col = 4;
            while (col <= 7) {
                col++;
                if (col == 7 && chessBoard->boardSquares[row][col]->getPiece() != nullptr && !chessBoard->boardSquares[row][col]->getPiece()->didPieceMove() && !isSquareUnderAttack(row, col, attackedSquares)) {
                    legalMoves.push_back(new Move(std::make_pair(7, 4), std::make_pair(row, col - 1), true));
                }
                if (chessBoard->boardSquares[row][col]->getPiece() != nullptr || isSquareUnderAttack(row, col, attackedSquares)) {
                    break;
                }
            }
        }
    }
}


