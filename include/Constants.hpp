enum class Color {
  WHITE,
  BLACK
};

struct Movement {
  bool forward;
  bool backward;
  bool diagonal;
  bool left;
  bool right;
  bool knight;
  bool oneSpace;
  bool twoSpaces;
  bool unlimitedSpaces;
};

struct Position {
  int column;
  int row;
};