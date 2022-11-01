# Notes

## Definition

24 bit BMP files uses 8 bits to represent each RGB color, this translates to 255 possible values for red, blue and green. It also can be represented by 2 hexadecimal numbers;

A 24 bit BMP file can be divided in 24 bits, each representing a color;

BMP's also have headers at the beginning of the file, the first of which is called BITMAPFILEHEADER and has 14 bytes(112 bits). The second, BITMAPINFOHEADER, is 40 bytes long (320);

Immediately following these headers is the actual bitmap: an array of bytes, triples of which represent a pixel’s color. However, BMPstores these triples backwards (i.e., as BGR), with 8 bits for blue,followed by 8 bits for green, followed by 8 bits for red;

A bitmap can be represented as a 2-dimensional array of pixels:where the image is an array of rows, each row is an array of pixels;

## Filtering

Filtering an image is basically altering it's pixels in some way that a particular effects is apparent in the result;

### Grayscale

Take the average of the red, green, and blue values to determine what shade of grey to make the new pixel.

### Sepia

For each pixel, the sepia color values should be calculated based on the original color values per the below.

sepiaRed = .393 * originalRed + .769 * originalGreen + .189 *originalBlue
sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 *originalBlue
sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 *originalBlue

### Reflection

Any pixels on the left side of the image should end up on the right, and vice versa.

### Blur

The new value of each pixel would be the average of the values of all of the pixels that are within 1 row and column of the original pixel (forming a 3x3 box).

## Pseudocode

Loop through all pixels in given img and alter them according to the filter;
