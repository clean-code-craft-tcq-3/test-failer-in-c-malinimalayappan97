#include <stdio.h>
#include <assert.h>

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

const char* majorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors =
    sizeof(majorColorNames) / sizeof(majorColorNames[0]);

int numberOfMinorColors =
    sizeof(minorColorNames) / sizeof(minorColorNames[0]);

typedef struct {
    enum MajorColor majorColorValue;
    enum MinorColor minorColorValue;
} ColorPair;



int printColorMap() {    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", ((i*5)+j+1), majorColorNames[i], minorColorNames[j]);
        }
    }
    return i * j;
}


ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColorValue = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColorValue =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.minorColorValue == expectedMinor);
    assert(colorPair.majorColorValue == expectedMajor);
}

int main() {
    printColorMap();
    testNumberToPair(25,VIOLET,SLATE);
    testNumberToPair(1,WHITE,BLUE);
    testNumberToPair(19,YELLOW,BROWN);
    
    printf("All is well (maybe!)\n");
    return 0;
}
