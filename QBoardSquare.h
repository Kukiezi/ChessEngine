#pragma once

#include <QGraphicsRectItem>
#include "UI/Pieces/QPieces.h"

class QBoardSquare: public QGraphicsRectItem
{
    bool dragged_;
    Color color_;
    QPiece* piece_ = NULL;
    static const int rectSize_ = 100;
    int row_;
    int col_;
    std::pair<int, int> from_;
    std::pair<int, int> to_;
public:
    bool & dragged() {return dragged_;}
    void dragged(bool dragged) {dragged_ = dragged;}

    Color & color() {return color_;}
    void color(Color color) {color_ = color;}

    QPiece* piece() {return piece_;}
    void piece(QPiece* piece) {piece_ = piece;}

    static int rectSize() {return rectSize_;}

    int row() const {return row_; }
    void row(int row) {
        if (row < 0 || row > 7) {
            throw std::invalid_argument("invalid argument for row");
        }
        row_ = row;
    }

    int col() const {return col_;}
    void col(int col) {
        if (col < 0 || col > 7) {
            throw std::invalid_argument("invalid argument for col");
        }
        col_ = col;
    }
    std::pair<int, int> from() const & {return from_; }
    void from(std::pair<int, int> from) {from_ = from;}

    std::pair<int, int> to() const & {return to_; }
    std::pair<int, int> to(std::pair<int, int> to) {to_ = to;}

    QBoardSquare(Color color, int x, int y, int row, int col);
    QEngine& engine = QEngine::getInstance();
    QPiece *getPiece();
    void setColor(Color color);
    void setPiece(QPiece* piece);
    void removePiece();
};

