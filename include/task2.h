#define COLS 76
#define ROWS 24

void clearMatrix(char(*arr)[COLS]); // filling the matrix with spaces
void fillMatrix(char(*arr)[COLS]); // filling upper left quadrant with stars
void setMatrix(char(*arr)[COLS]); // copy symbols to other parts of the matrix
void printMatrix(char(*arr)[COLS]); //print all matrix
