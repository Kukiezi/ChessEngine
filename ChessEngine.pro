QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Engine/BoardSquare.cpp \
    Engine/ChessBoard.cpp \
    Engine/Engine.cpp \
    Engine/FenService.cpp \
    Engine/Game.cpp \
    Engine/Move.cpp \
    Engine/MoveGenerator.cpp \
    Engine/MoveValidator.cpp \
    Engine/Pieces/Bishop.cpp \
    Engine/Pieces/King.cpp \
    Engine/Pieces/Knight.cpp \
    Engine/Pieces/Pawn.cpp \
    Engine/Pieces/Piece.cpp \
    Engine/Pieces/Queen.cpp \
    Engine/Pieces/Rook.cpp \
    Fen.cpp \
    Color.cpp \
    Consts.cpp \
    QBoardSquare.cpp \
    QChessBoard.cpp \
    QGame.cpp \
    UI/Pieces/QBishop.cpp \
    UI/Pieces/QKing.cpp \
    UI/Pieces/QKnight.cpp \
    UI/Pieces/QPawn.cpp \
    UI/Pieces/QPiece.cpp \
    UI/Pieces/QQueen.cpp \
    UI/Pieces/QRook.cpp \
    main.cpp \
    boardwindow.cpp

HEADERS += \
    Engine/BoardSquare.h \
    Engine/ChessBoard.h \
    Engine/Engine.h \
    Engine/FenService.h \
    Engine/Game.h \
    Engine/Move.h \
    Engine/MoveGenerator.h \
    Engine/MoveValidator.h \
    Engine/Pieces/Bishop.h \
    Engine/Pieces/King.h \
    Engine/Pieces/Knight.h \
    Engine/Pieces/Pawn.h \
    Engine/Pieces/Piece.h \
    Engine/Pieces/Pieces.h \
    Engine/Pieces/Queen.h \
    Engine/Pieces/Rook.h \
    Fen.h \
    Color.h \
    Consts.h \
    QBoardSquare.h \
    QChessBoard.h \
    QGame.h \
    UI/Pieces/QBishop.h \
    UI/Pieces/QKing.h \
    UI/Pieces/QKnight.h \
    UI/Pieces/QPawn.h \
    UI/Pieces/QPiece.h \
    UI/Pieces/QPieces.h \
    UI/Pieces/QQueen.h \
    UI/Pieces/QRook.h \
    boardwindow.h

FORMS += \
    boardwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
