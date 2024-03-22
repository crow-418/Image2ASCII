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
     
    int width, height, sizeOfPixels;
    unsigned char *image_data = stbi_load(argv[1], &width, &height, &sizeOfPixels, STBI_grey); 

    if (image_data) {
        for (int rowIndex = 0; rowIndex < height; rowIndex++) {
            for (int columnIndex = 0; columnIndex < width; columnIndex++) {
                unsigned char pixel_value = image_data[rowIndex * width + columnIndex];
                int index = pixel_value * (strlen(gscale) - 1) / 255; 
                printf("%c", gscale[index]);               
            }
            printf("\n");
        }
        stbi_image_free(image_data);
        
        return EXIT_SUCCESS;
    }


    return EXIT_FAILURE;
}
