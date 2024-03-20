#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int average = (int)(0.5 + (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }

    return;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid use. Please run as:\n");
        printf("./image2ascii image.png/jpeg/jpg\n");
        return 1;
    }
  
    const char *gscale1 = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~i!lI;:,\"^`";
    char *infile = argv[1];
     
    FILE *inptr = fopen(infile, "r");

    return EXIT_SUCCESS;
}
