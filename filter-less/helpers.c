#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ave_maria = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0); // 3.0 from the guide

            image[i][j].rgbtRed = ave_maria;
            image[i][j].rgbtGreen = ave_maria;
            image[i][j].rgbtBlue = ave_maria;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // sepia formula
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            int *sepia[3] = {&sepiaRed, &sepiaGreen, &sepiaBlue}; // implemented array to avoid three if statements, and applied pointers for modification

            for (int v = 0; v < 3; v++) // for loop that caps if greater than 255
            {
                if (*sepia[v] > 255)
                {
                    *sepia[v] = 255;
                }
            }
            image[i][j].rgbtRed = sepiaRed; // replace red component with sepia version
            image[i][j].rgbtGreen = sepiaGreen; // replace green component with sepia version
            image[i][j].rgbtBlue = sepiaBlue; // replace blue component with sepia version
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // first half only
        {
            RGBTRIPLE temp = image[i][j]; // temporary variable for swapping
            image[i][j] = image[i][width - j - 1]; // store the opposite counterpart to the current index of the pixel
            image[i][width - j - 1] = temp; // complete the swap
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // create a storage for modified pixel values to avoid editing the original image because it will serve as the basis for the neighboring pixels as you loop
            temp[i][j] = image[i][j];
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // initialize
            float pixel_counter = 0;

            int red_add = 0;
            int green_add = 0;
            int blue_add = 0;

            // scan nine neighboring pixels of every pixel
            for (int h = -1; h <= 1; h++)
            {
                for (int w = -1; w <= 1; w++)
                {
                    // i - 1 yields an x value of -1, which points outside of the image
                    // j - 1 yields a y value of -1, which also points outside of the image
                    int neighborX = i + h;
                    int neighborY = j + w;

                    // ignores invalid pixels - negative x, negative y, greater than width and height are neighbors outside the original frame
                    if (neighborX < 0 || neighborY < 0 || neighborX > width - 1 || neighborY > height - 1)
                    {
                        continue;
                    }

                    pixel_counter++; // counts the number of valid neighbors

                    red_add = red_add + image[neighborX][neighborY].rgbtRed;
                    green_add = green_add + image[neighborX][neighborY].rgbtGreen;
                    blue_add = blue_add + image[neighborX][neighborY].rgbtBlue;

                    // average values calculated will fill up the empty temp of image copy
                    // original image needs to be unedited while on the process of calculating the average of the neighboring pixels
                    temp[i][j].rgbtRed = round(red_add / pixel_counter);
                    temp[i][j].rgbtGreen = round(green_add / pixel_counter);
                    temp[i][j].rgbtBlue = round(blue_add / pixel_counter);

                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j]; // replace original pixels with blurred or preprocessed pixels
        }
    }
    return;
}
