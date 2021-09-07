#pragma once

#include "UI/Pieces/QPieces.h"
#include "QChessBoard.h"
#include "Engine/Pieces/Pieces.h"
#include "QEngine.h"
#include "Engine/Engine.h"
#include "Turn.h"
#include "QChessMenu.h"
#include "QChessBackButton.h"
#include "QChessForwardButton.h"
#include "QMove.h"
#include "QSavedGames.h"
#include "QBackButton.h"
#include "Engine/GameType.h"
#include "QPositionInput.h"
#include "QPositionButton.h"

class QGame
{
    QChessMenu* chessMenu;
    QChessBoard* board;
    std::string startingFen_;
    Turn* turn_;
    GameType gameType_;

public:
    QGame(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    Turn* getTurn();
    void startGame(GameType gameType, std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    void startReplay(std::string path);
    void getSavedGamesScreen();
    void resetSquareColors();
    QChessBoard* getChessBoard();
    void MakeMoveBackward();
    void MakeMoveForward();
    void clearMemory();
    GameType getGameType();
    void getStartFromPositionScreen();

private:
    void initializeBoard(ChessBoard* chessBoard);
    void initializePieces(ChessBoard* chessBoard);
    QPiece *getPieceFromEngine(std::shared_ptr<Piece> piece);
};
