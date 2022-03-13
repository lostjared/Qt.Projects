#include"puzzle_drop.hpp"

namespace puzzle {


// *** Block

    Block::Block() : x{0}, y{0}, type{BlockType::BLOCK_NULL} {}

    Block::Block(int xx, int yy, BlockType t) : x{xx}, y{yy}, type{t} {}

    Block::Block(const Block &b) : x{b.x}, y{b.y}, type{b.type} {}
    
    Block &Block::operator=(const Block &b) {
        x = b.x;
        y = b.y;
        type = b.type;
        return *this;
    }

    Block &Block::operator=(Block &&b) {
        x = b.x;
        y = b.y;
        type = b.type;
        return *this;
    }

    Block &Block::operator=(const BlockType &t) {
        type = t;
        return *this;
    }


    bool Block::operator==(const Block &b) {
        if(type == b.type)
            return true;
        return false;
    }

    bool Block::operator==(const BlockType &t) {
        if(type == t)
            return true;
        return false;
    }

    int Block::getX() const {
        return x;
    }
    
    int Block::getY() const {
        return y;
    }
    
    BlockType Block::getType() const {
        return type;
    }

    std::ostream &operator<<(std::ostream &out, Block &b) {
        out << "Block [ x:" << b.x << " y: " << b.y << "]  ";
        return out;
    }


// *** Piece

    Piece::Piece() {

    }

    void Piece::newPiece(int start_x, int start_y) {
        blocks[0].x = start_x;
        blocks[0].y = start_y;
        blocks[1].x = start_x;
        blocks[1].y = start_y+1;
        blocks[2].x = start_x;
        blocks[2].y = start_y+2;
        randColors();
    }

    void Piece::randColors() {
        blocks[0].type = static_cast<BlockType>(2+rand()%9);
        blocks[1].type = static_cast<BlockType>(2+rand()%9);
        blocks[2].type = static_cast<BlockType>(2+rand()%9);
    }

    void Piece::shift(Direction dir) {
        BlockType b[3];
        b[0] = blocks[0].type;
        b[1] = blocks[1].type;
        b[2] = blocks[2].type;
        if(dir == D_DOWN) {
            blocks[0].type = b[2];
            blocks[1].type = b[0];
            blocks[2].type = b[1];
        } else if(dir == D_UP) {
            blocks[0] = b[1];
            blocks[1] = b[2];
            blocks[2] = b[0];
        }
    }

    void Piece::moveLeft() {
        for(int i = 0; i < 3; ++i)
            blocks[i].x--;
    }
    void Piece::moveRight() {
        for(int i = 0; i < 3; ++i)
            blocks[i].x++;
    }
    void Piece::moveDown() {
        for(int i = 0; i < 3; ++i)
            blocks[i].y++;
    }

    std::ostream &operator<<(std::ostream &out, Piece &p) {
        out << "Piece: " << p.blocks[0] << p.blocks[1] << p.blocks[2] << "\n";
        return out;
    }



// *** Grid

    Grid::Grid(int w, int h) : grid_w{w}, grid_h{h} {
        blocks = new Block*[w];
        for(int i = 0; i < grid_w; ++i) {
            blocks[i] = new Block[h];
        }
        clearGrid();
        piece.newPiece(w/2, 0);
    }

    void Grid::clearGrid() {
        for(int i = 0; i < getWidth(); ++i) {
            for(int z = 0; z < getHeight(); ++z) {
                blocks[i][z] = Block(i, z, BlockType::BLOCK_NULL);
            }
        }
    }
    
    Grid::~Grid() {
        if(blocks != nullptr) {
            for(int i = 0; i < getWidth(); ++i)
                delete [] blocks[i];
            delete [] blocks;
        }
    }

    int Grid::getWidth() const {
        return grid_w;
    }
    
    int Grid::getHeight() const {
        return grid_h;
    }

    Block *Grid::grid(int x, int y) {
        if(x >= 0 && x < grid_w && y >= 0 && y < grid_h) {
            return &blocks[x][y];
        }
        return nullptr;
    }

    Piece &Grid::getPiece() {
        return piece;
    }

    void Grid::keyLeft() {
        if(checkPiece(-1, 0)) {
            piece.moveLeft();
        }
    }
    void Grid::keyRight() {
        if(checkPiece(1, 0)) {
            piece.moveRight();
        }
    }

    void Grid::keyDown() {
        if(checkPiece(0, 1)) {
            piece.moveDown();
        } else {
            setPiece();
            piece.newPiece(grid_w/2, 0);
        }
    }

    void Grid::keyShiftUp() {
        piece.shift(D_UP);
    }

    void Grid::keyShiftDown() {
        piece.shift(D_DOWN);
    }

    bool Grid::checkPiece(int x, int y) {
        for(int i = 0; i < 3; ++i) {
            Block *b = grid(piece.blocks[i].getX()+x, piece.blocks[i].getY()+y);
            if(b == nullptr || (b->getType() != BlockType::BLOCK_NULL && b->getType() != BlockType::BLOCK_CLEAR)) {
                return false;
            }
        }
        return true;
    }

    void Grid::setPiece() {
        for(int i = 0; i < 3; ++i) {
            int px = piece.blocks[i].getX();
            int py = piece.blocks[i].getY();
            Block *b = grid(px, py);
            if(b != nullptr) {
                *b = piece.blocks[i].getType();
            }
        }
    }

    void Grid::update() {
    
        procBlocks();
    }

    void Grid::procBlocks() {
    
    }

    void Grid::procMoveDown() {
    
    }

}
