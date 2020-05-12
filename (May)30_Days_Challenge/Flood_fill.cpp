// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

// At the end, return the modified image.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int color = -1;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        if(color == -1) color = image[sr][sc];

        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || color == newcolor || image[sr][sc] != color)
            return image;
        
        image[sr][sc] = newcolor;
        image = floodFill(image, sr+1, sc, newcolor);
        image = floodFill(image, sr-1, sc, newcolor);
        image = floodFill(image, sr, sc+1, newcolor);
        image = floodFill(image, sr, sc-1, newcolor);
        
        return image;
    }
};