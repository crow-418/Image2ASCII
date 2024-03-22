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
    int targetWidth = 120;
    int targetHeight = 50;
     
    int width, height, numChannels;
    unsigned char *image_data = stbi_load(argv[1], &width, &height, &numChannels, STBI_grey); 

    if (image_data == NULL) {
        printf("Error loading image.\n");
        return 1;
    }

    float widthRatio = (float)width / targetWidth;
    float heightRatio = (float)height / targetHeight;
    if (image_data) {
        for (int rowIndex = 0; rowIndex < targetHeight; rowIndex++) {
            for (int columnIndex = 0; columnIndex < targetWidth; columnIndex++) {
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
