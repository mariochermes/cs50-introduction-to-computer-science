#include <math.h>
#include "helpers.h"


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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Maximum value a color can have
    BYTE const maxValue = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Aplies the sepia formula to each color value
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);

            // Uses ternary operators to check if the result of the formula is higher than 255
            image[i][j].rgbtBlue = (sepiaBlue > maxValue) ? maxValue : sepiaBlue;
            image[i][j].rgbtGreen = (sepiaGreen > maxValue) ? maxValue : sepiaGreen;
            image[i][j].rgbtRed = (sepiaRed > maxValue) ? maxValue : sepiaRed;
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
