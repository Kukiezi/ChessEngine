#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include "Color.cpp"
#include <QGraphicsPixmapItem>

class Piece : public QGraphicsPixmapItem
{
    std::string name_;
    int value_;
    Color color_;
    std::string image_;

public:
    Piece(Color _color);

    virtual std::string getName() const;
    virtual std::string getImage() const;
    virtual int getValue() const;


    Color getColor();
    void setColor(Color color);

    void print();

    std::string getColorText();
};

#endif // PIECE_H
