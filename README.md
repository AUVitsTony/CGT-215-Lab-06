CGT-215 Lab 06

This lab is a C++ program that combines two images by replacing the green screen background of a character image with another background image.

Lab 06

This lab focuses on using the SFML library, nested loops, pixels, and color values to create a combined image.

This lab uses:
-SFML/Graphics.hpp to load and display images
-string to store the image file locations
-Texture to load the background and character images
-Image to access and modify individual pixels
-getSize() to find the image dimensions
-getPixel() to read the color of a pixel
-Two nested for loops to go through every pixel
-An if statement to check for the green screen color
-setPixel() to replace green pixels with background pixels
-RenderWindow and Sprite to display the final combined image
