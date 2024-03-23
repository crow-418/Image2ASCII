# Image2ASCII Converter

This is a simple Image2ASCII converter implemented in C. The program takes an input image (PNG, JPEG, or JPG) and converts it into ASCII art, displaying it in the terminal. 

## How to Use

1. Clone the repository to your local machine.
2. Navigate to the repository directory.
3. Compile the program using the provided Makefile:

    ```
    make
    ```
4. Run the program by providing the image file as a command-line argument:

    ```
    ./image2ascii image.png/jpeg/jpg
    ```
5. Follow the prompts to enter the desired width and height for the ASCII art.

## Dependencies

- [stb_image](https://github.com/nothings/stb) - This project uses the `stb_image` library for loading images.

## Usage Example

Suppose you have an image named `example.png`. To convert it into ASCII art, you would run:

    ./image2ascii example.png

## ASCII Mapping

The ASCII characters used for representing different shades of gray in the image are as follows:

- `@`: Darkest shade
- `%`: Very dark shade
- `#`: Dark shade
- `*`: Medium shade
- `+`: Light shade
- `=`: Very light shade
- `-`: Even lighter shade
- `:`: Lightest shade

## Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to open an issue or create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
