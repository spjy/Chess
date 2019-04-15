TARGETS=bishop.o king.o pawn.o player.o queen.o rook.o board.o piece.o

all: $(TARGETS)
	g++ $(TARGETS) -o output

bishop.o: ./src/Bishop.cpp
	g++ -c ./src/Bishop.cpp -I./include -o ./src/Bishop.o

king.o: ./src/King.cpp
	g++ -c ./src/King.cpp -I./include -o ./src/King.o

pawn.o: ./src/Pawn.cpp
	g++ -c ./src/Pawn.cpp -I./include -o ./src/Pawn.o

player.o: ./src/Player.cpp
	g++ -c ./src/Player.cpp -I./include -o ./src/Player.o

queen.o: ./src/Queen.cpp
	g++ -c ./src/Queen.cpp -I./include -o ./src/Queen.o

rook.o: ./src/Rook.cpp
	g++ -c ./src/Rook.cpp -I./include -o ./src/Rook.o

board.o: ./src/Board.cpp
	g++ -c ./src/Board.cpp -I./include -o ./src/Board.o

piece.o: ./src/Piece.cpp
	g++ -c ./src/Piece.cpp -I./include -o ./src/Piece.o

clean:
