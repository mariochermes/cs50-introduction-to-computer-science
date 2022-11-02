#include "helpers.h"
#include "math.h"

int gx_kernel(int x, int y, int color_value);
int gy_kernel(int x, int y, int color_value);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Gets the average of the color values in one pixel
            BYTE avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // Each color value them receives the average
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary two dimensional array to store pixels momentarily
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        // Loops to the half of each row
        for (int j = 0; j < width / 2; j++)
        {
            // Stores the first half pixel in temp
            temp[i][j] = image[i][j];
            // Assigns to the pixel treated in the left half its symmetric equivalent in the right half
            image[i][j] = image[i][width - j - 1];
            // Attribute the initial left half pixel to the right half pixel
            image[i][width - j - 1] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Populate an auxiliary array from where to get the original values from, since we will be modifing the image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Sum of all values for each color
            int sumBlue = 0, sumGreen = 0, sumRed = 0;
            int count = 0;
            // Loops from the previous row to the next one
            for (int k = i - 1; k <= i + 1; k++)
            {
                // if it is one of the top or bottom edges, jump to the next iteration
                if (k == - 1 || k == height)
                {
                    continue;
                }
                // Loops from the previous column to the next one
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // if it is one of the left or right edges, jump to the next iteration
                    if (l == - 1 || l == width)
                    {
                        continue;
                    }

                    // Sums the color value in each pixel around the current one
                    sumBlue += copy[k][l].rgbtBlue;
                    sumGreen += copy[k][l].rgbtGreen;
                    sumRed += copy[k][l].rgbtRed;
                    count++;
                }
            }
            // Assigns the averages for each color around the pixel to the pixel color values
            image[i][j].rgbtBlue = round((float)sumBlue / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtRed = round((float)sumRed / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    BYTE const maxValue = 255;

    // Populate an auxiliary array from where to get the original values, since we will be modifing the image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Sobel Operator matrices for Gx and Gy
    int kernelGx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int kernelGy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initializes the values for weighted sums
            double gxBlue = 0;
            double gyBlue = 0;
            double gxGreen = 0;
            double gyGreen = 0;
            double gxRed = 0;
            double gyRed = 0;

            // Loops from the previous row to the next one
            for (int k = i - 1, row = 0; k <= i + 1; k++, row++)
            {
                // Loops from the previous column to the next one
                for (int l = j - 1, column = 0; l <= j + 1; l++, column++)
                {
                    // if it is one of the edges, the pixel is considered black
                    if ((k == - 1 || k == height) || (l == - 1 || l == width))
                    {
                        continue;
                    }
                    // Get the gx and gy for every color in the current pixel
                    gxBlue += kernelGx[row][column] * copy[k][l].rgbtBlue;
                    gyBlue += kernelGy[row][column] * copy[k][l].rgbtBlue;

                    gxGreen += kernelGx[row][column] * copy[k][l].rgbtGreen;
                    gyGreen += kernelGy[row][column] * copy[k][l].rgbtGreen;

                    gxRed += kernelGx[row][column] * copy[k][l].rgbtRed;
                    gyRed += kernelGy[row][column] * copy[k][l].rgbtRed;
                }
            }
            // Aplies the Sobel formula to get the final value
            int sobelBlue = round(sqrt(pow(gxBlue, 2) + pow(gyBlue, 2)));
            int sobelGreen = round(sqrt(pow(gxGreen, 2) + pow(gyGreen, 2)));
            int sobelRed = round(sqrt(pow(gxRed, 2) + pow(gyRed, 2)));

            // Check if the value is higher than 255 and cap it at that
            image[i][j].rgbtBlue = (sobelBlue > maxValue) ? maxValue : sobelBlue;
            image[i][j].rgbtGreen = (sobelGreen > maxValue) ? maxValue : sobelGreen;
            image[i][j].rgbtRed = (sobelRed > maxValue) ? maxValue : sobelRed;
        }
    }
    return;
}