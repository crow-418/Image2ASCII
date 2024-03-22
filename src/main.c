#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid use. Please run as:\n");
        printf("./image2ascii image.png/jpeg/jpg\n");
        return 1;
    }

    const char *gscale = "@%#*+=-:.";
    unsigned int targetWidth;
    unsigned int targetHeight;

    printf("What is the desired width?\n");
    scanf("%d", &targetWidth);
    printf("What is the desired height?\n");
    scanf("%d", &targetHeight);
     
    int width, height, numChannels;
    unsigned char *image_data = stbi_load(argv[1], &width, &height, &numChannels, STBI_grey); 

    if (image_data == NULL) {
        printf("Error loading image.\n");
        return 1;
    }

    float widthRatio = (float)width / targetWidth;
    float heightRatio = (float)height / targetHeight;
    if (image_data) {
        for (size_t rowIndex = 0; rowIndex < targetHeight; rowIndex++) {
            for (size_t columnIndex = 0; columnIndex < targetWidth; columnIndex++) {
                int imgX = (int)(columnIndex * widthRatio);
                int imgY = (int)(rowIndex * heightRatio);

                unsigned char pixel_value = image_data[imgY * width + imgX];
                int index = (int)(strlen(gscale) * (pixel_value / 255.0f)); 
                putchar(gscale[index]);               
            }
            putchar('\n');
        }
        
        stbi_image_free(image_data);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
