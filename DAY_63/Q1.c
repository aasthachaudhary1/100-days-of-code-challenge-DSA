/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
void dfs(int** image, int m, int n, int r, int c, int oldColor, int newColor)
{
    if(r < 0 || r >= m || c < 0 || c >= n)
        return;

    if(image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    dfs(image, m, n, r+1, c, oldColor, newColor);
    dfs(image, m, n, r-1, c, oldColor, newColor);
    dfs(image, m, n, r, c+1, oldColor, newColor);
    dfs(image, m, n, r, c-1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
{
    int oldColor = image[sr][sc];

    if(oldColor != color)
        dfs(image, imageSize, imageColSize[0], sr, sc, oldColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}
