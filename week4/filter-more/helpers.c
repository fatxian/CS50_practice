#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Step 1: 複製原始影像到 copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Step 2: 對每個像素計算 Gx 和 Gy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 邊界處理：如果是邊界像素，就設為黑
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                image[i][j].rgbtRed = 0;
                image[i][j].rgbtGreen = 0;
                image[i][j].rgbtBlue = 0;
                continue;
            }

            // 紅色
            int Gx_red =
                -1 * copy[i - 1][j - 1].rgbtRed + 0 * copy[i - 1][j].rgbtRed + 1 * copy[i - 1][j + 1].rgbtRed +
                -2 * copy[i][j - 1].rgbtRed     + 0 * copy[i][j].rgbtRed     + 2 * copy[i][j + 1].rgbtRed +
                -1 * copy[i + 1][j - 1].rgbtRed + 0 * copy[i + 1][j].rgbtRed + 1 * copy[i + 1][j + 1].rgbtRed;

            int Gy_red =
                -1 * copy[i - 1][j - 1].rgbtRed + -2 * copy[i - 1][j].rgbtRed + -1 * copy[i - 1][j + 1].rgbtRed +
                 0 * copy[i][j - 1].rgbtRed     + 0 * copy[i][j].rgbtRed     + 0 * copy[i][j + 1].rgbtRed +
                 1 * copy[i + 1][j - 1].rgbtRed + 2 * copy[i + 1][j].rgbtRed + 1 * copy[i + 1][j + 1].rgbtRed;

            // 綠色
            int Gx_green =
                -1 * copy[i - 1][j - 1].rgbtGreen + 0 * copy[i - 1][j].rgbtGreen + 1 * copy[i - 1][j + 1].rgbtGreen +
                -2 * copy[i][j - 1].rgbtGreen     + 0 * copy[i][j].rgbtGreen     + 2 * copy[i][j + 1].rgbtGreen +
                -1 * copy[i + 1][j - 1].rgbtGreen + 0 * copy[i + 1][j].rgbtGreen + 1 * copy[i + 1][j + 1].rgbtGreen;

            int Gy_green =
                -1 * copy[i - 1][j - 1].rgbtGreen + -2 * copy[i - 1][j].rgbtGreen + -1 * copy[i - 1][j + 1].rgbtGreen +
                 0 * copy[i][j - 1].rgbtGreen     + 0 * copy[i][j].rgbtGreen     + 0 * copy[i][j + 1].rgbtGreen +
                 1 * copy[i + 1][j - 1].rgbtGreen + 2 * copy[i + 1][j].rgbtGreen + 1 * copy[i + 1][j + 1].rgbtGreen;

            // 藍色
            int Gx_blue =
                -1 * copy[i - 1][j - 1].rgbtBlue + 0 * copy[i - 1][j].rgbtBlue + 1 * copy[i - 1][j + 1].rgbtBlue +
                -2 * copy[i][j - 1].rgbtBlue     + 0 * copy[i][j].rgbtBlue     + 2 * copy[i][j + 1].rgbtBlue +
                -1 * copy[i + 1][j - 1].rgbtBlue + 0 * copy[i + 1][j].rgbtBlue + 1 * copy[i + 1][j + 1].rgbtBlue;

            int Gy_blue =
                -1 * copy[i - 1][j - 1].rgbtBlue + -2 * copy[i - 1][j].rgbtBlue + -1 * copy[i - 1][j + 1].rgbtBlue +
                 0 * copy[i][j - 1].rgbtBlue     + 0 * copy[i][j].rgbtBlue     + 0 * copy[i][j + 1].rgbtBlue +
                 1 * copy[i + 1][j - 1].rgbtBlue + 2 * copy[i + 1][j].rgbtBlue + 1 * copy[i + 1][j + 1].rgbtBlue;

            // 最後顏色處理（Gx² + Gy² 開根號）
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Clamp to 255
            image[i][j].rgbtRed = red > 255 ? 255 : red;
            image[i][j].rgbtGreen = green > 255 ? 255 : green;
            image[i][j].rgbtBlue = blue > 255 ? 255 : blue;
        }
    }
}
