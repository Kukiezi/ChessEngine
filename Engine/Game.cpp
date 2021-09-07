#include "Game.h"

Game::Game(std::__1::string fenString, GameType gameType)
{
    setChessBoard(std::make_unique<ChessBoard>());
    FenService::addPieceToBoardFromFenString(fenString, chessBoard_);
    std::string turn = FenService::getStartingTurnFromFenString(fenString);
    this->gameType = gameType;
    if (turn == "w") {
        turn_ = &player1_;
    } else {
        turn_ = &player2_;
    }
    gameState_ = GameState::IN_PROGRESS;
}

ChessBoard* Game::getChessBoard()
{
    return chessBoard_.get();
}

ChessBoard Game::getChessBoardCopy()
{
    return *chessBoard_;
}

void Game::setNextTurn()
{
    if (*turn_ == player1_) {
        turn_ = &player2_;
        return;
    }

    turn_ = &player1_;
}

std::shared_ptr<Move> Game::getLastCastleMove()
{
    auto move = listOfMoves[listOfMoves.size() - 1];
    if (move->isCastleMove) {
        return move;
    }
    return NULL;
}

bool Game::makeMove(std::shared_ptr<Move> move)
{
    if (gameState_ == GameState::FINISHED) {
        std::cout << "Game HAS FINISHED" << std::endl;
        return false;
    }
    if (!MoveValidator::isMoveLegal(getChessBoard(), move, *turn_)) {
        return false;
    }

    auto piece = chessBoard_->boardSquares[move->from.first][move->from.second]->getPiece();

    chessBoard_->boardSquares[move->to.first][move->to.second]->setPiece(piece);
    chessBoard_->boardSquares[move->from.first][move->from.second]->resetPiece();

    if (piece->getShortName() == "K" && move->isCastleMove) {
        auto castlePiece = chessBoard_->boardSquares[move->castleFrom.first][move->castleFrom.second]->getPiece();
        chessBoard_->boardSquares[move->castleTo.first][move->castleTo.second]->setPiece(castlePiece);
        chessBoard_->boardSquares[move->castleFrom.first][move->castleFrom.second]->resetPiece();
        castlePiece->setMoved(true);
    }

    // Transform pawn to queen if reached the other side of the board
    if (piece->getShortName() == "P" && *turn_ == Color::White && move->to.first == 7) {
        std::cout << "wszedlem" << std::endl;
        chessBoard_->boardSquares[move->to.first][move->to.second]->resetPiece();
        std::shared_ptr<Piece> newPiece = std::make_unique<Queen>(Color::White);
        chessBoard_->boardSquares[move->to.first][move->to.second]->setPiece(newPiece);
    }
    if (piece->getShortName() == "P" && *turn_ == Color::Black && move->to.first == 0) {
        std::cout << "wszedlem" << std::endl;
        chessBoard_->boardSquares[move->to.first][move->to.second]->resetPiece();
        std::shared_ptr<Piece> newPiece = std::make_unique<Queen>(Color::Black);
        chessBoard_->boardSquares[move->to.first][move->to.second]->setPiece(newPiece);
    }

    piece->setMoved(true);
    setNextTurn();

    listOfMoves.push_back(move);
    listOfMovesInPGN.push_back(move->getChessCoordinatesFromBoardCoordinates());

    ifGameIsOverSaveGameAndSetUpLabel();

    return true;
}

bool Game::makeMoveWithoutLegalChecks(std::shared_ptr<Move> move)
{
    auto piece = chessBoard_->boardSquares[move->from.first][move->from.second]->getPiece();

    chessBoard_->boardSquares[move->to.first][move->to.second]->setPiece(piece);
    chessBoard_->boardSquares[move->from.first][move->from.second]->resetPiece();
    return true;
}

std::shared_ptr<Move> Game::getAIMove()
{
    if (gameState_ == GameState::FINISHED) {
        std::cout << "Game HAS FINISHED" << std::endl;
        return NULL;
    }

    auto legalMoves = MoveValidator::getAllLegalMoves(getChessBoard(), *turn_);

    int index = rand() % legalMoves.size();
    std::vector<Move*> list ;
    for (auto move : legalMoves) {
        list.push_back(move);
    }
    auto move = list[index];

    auto piece = chessBoard_->boardSquares[move->from.first][move->from.second]->getPiece();

    chessBoard_->boardSquares[move->to.first][move->to.second]->setPiece(piece);
    chessBoard_->boardSquares[move->from.first][move->from.second]->resetPiece();

    if (piece->getShortName() == "K" && move->isCastleMove) {
        auto castlePiece = chessBoard_->boardSquares[move->castleFrom.first][move->castleFrom.second]->getPiece();
        chessBoard_->boardSquares[move->castleTo.first][move->castleTo.second]->setPiece(castlePiece);
        chessBoard_->boardSquares[move->castleFrom.first][move->castleFrom.second]->resetPiece();
        castlePiece->setMoved(true);
    }

    piece->setMoved(true);
    setNextTurn();

    listOfMovesInPGN.push_back(move->getChessCoordinatesFromBoardCoordinates());

    ifGameIsOverSaveGameAndSetUpLabel();

    auto retMove = std::shared_ptr<Move>(list[index]);
    return retMove;
}

std::shared_ptr<Move> Game::createMove(std::string moveString)
{
    std::shared_ptr<Move> move = std::make_shared<Move>(moveString);
    return move;
}

std::shared_ptr<Move> Game::createMove(std::pair<int, int> from, std::pair<int, int> to)
{
    std::shared_ptr<Move> move = std::make_shared<Move>(from, to);
    return move;
}

void Game::setChessBoard(std::shared_ptr<ChessBoard> chessBoard)
{
    chessBoard_ = chessBoard;
}

void Game::printChessBoard()
{
    getChessBoard()->printChessBoard();
}

Color Game::getTurn()
{
    return *turn_;
}

std::unique_ptr<Game> Game::getGame()
{
    return std::unique_ptr<Game>(this);
}

bool Game::exportGameToFile()
{
    std::ofstream outfile ("Game" + std::to_string(std::time(0)) + ".txt");
    for (auto move : listOfMovesInPGN) {
        outfile << move<< std::endl;
    }
    outfile.close();
    return true;
}

bool Game::isGameOver()
{
    return gameState_ == GameState::FINISHED;
}

void Game::ifGameIsOverSaveGameAndSetUpLabel()
{
    if (MoveValidator::isGameOver(getChessBoard(), *turn_)) {
        gameState_ = GameState::FINISHED;
        if (gameType == GameType::NORMAL || gameType == GameType::AI) {
            exportGameToFile();
        }
        setGameResultLabel();
    }
}

void Game::setGameResultLabel()
{
    if (MoveGenerator::isKingInCheck(getChessBoard(), player1_)) {
        turn_ = &blackWon;
        return;
    }

    if (MoveGenerator::isKingInCheck(getChessBoard(), player2_)) {
        turn_ = &whiteWon;
        return;
    }
    turn_ = &draw;
}
