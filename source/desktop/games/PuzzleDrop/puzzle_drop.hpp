// just practicing

#ifndef _PUZZLE_DROP_H_
#define _PUZZLE_DROP_H_

#include<iostream>
#include<string>


namespace puzzle {

    enum class BlockType { BLOCK_NULL=0, BLOCK_CLEAR, RED1, RED2, RED3, GREEN1, GREEN2, GREEN3, BLUE1, BLUE2, BLUE3 };

    class Piece;

    class Block {
        int x,y;
        BlockType type;
    public:
        Block();
        Block(const Block &b);
        Block(Block &&b) = delete;
        Block &operator=(const Block &b);
        Block &operator=(Block &&b);
        Block &operator=(const BlockType &t);
        Block(int xx, int yy, BlockType t);
        int getX() const;
        int getY() const;
        BlockType getType() const;
        bool operator==(const Block &b);
        bool operator==(const BlockType &type);
        friend class Piece;
        friend std::ostream &operator<<(std::ostream &out, Block &b);
    };

    enum Direction { D_DOWN=1, D_UP =2 };

    class Piece {
    public:
        Piece();
        void newPiece(int start_x, int start_y);
        void randColors();
        void moveLeft();
        void moveRight();
        void moveDown();
        void shift(Direction dir);
        Block blocks[3];
        friend std::ostream &operator<<(std::ostream &out, Piece &p);
    };

    class Grid {
    public:
        Grid(int w, int h);
        ~Grid();
        void clearGrid();
        Block *grid(int x, int y);
        int getWidth() const;
        int getHeight() const;
        Piece &getPiece();
        void keyLeft();
        void keyRight();
        void keyDown();
        void keyShiftUp();
        void keyShiftDown();
        void update();
    protected:
        Block **blocks;
        Piece piece;
        int grid_w, grid_h;
        
        bool checkPiece(int x, int y);
        void setPiece();
        void procBlocks();
        void procMoveDown();
    };

}


#endif

