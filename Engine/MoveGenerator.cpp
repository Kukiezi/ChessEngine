#include "MoveGenerator.h"

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


