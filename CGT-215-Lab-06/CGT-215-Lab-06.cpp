// CGT-215-Lab-06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {

    // Step 1: Set the locations of our two images.
    // The background is the picture we want behind the character.
    // The foreground is the character with a green screen.
    string background = "images1/backgrounds/winter.png";
    string foreground = "images1/characters/yoda.png";


    // Step 2: Load the background image into a texture.
    Texture backgroundTex;

    // Check if the background image was loaded successfully.
    if (!backgroundTex.loadFromFile(background)) {
        cout << "Couldn't Load Background Image" << endl;
        return 1;
    }


    // Step 3: Load the character image into another texture.
    Texture foregroundTex;

    // Check if the character image was loaded successfully.
    if (!foregroundTex.loadFromFile(foreground)) {
        cout << "Couldn't Load Foreground Image" << endl;
        return 1;
    }


    // Step 4: Convert the textures into images.
    // Images allow us to read and change individual pixels.
    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();

    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage();


    // Step 5: Get the size of the background image.
    // x is the width and y is the height.
    Vector2u sz = backgroundImage.getSize();


    // Step 6: Find the green screen color.
    // We assume the top-left corner is part of the green screen.
    Color greenScreen = foregroundImage.getPixel(0, 0);


    // Step 7: Go through every pixel in the image.
    // The first loop goes through each row (y).
    for (int y = 0; y < sz.y; y++) {

        // The second loop goes through each column (x).
        for (int x = 0; x < sz.x; x++) {

            // Get the current pixel from the character image.
            Color currentPixel = foregroundImage.getPixel(x, y);

            // Check if the current pixel matches the green screen.
            if (currentPixel == greenScreen) {

                // Get the pixel at the same position
                // from the background image.
                Color backgroundPixel = backgroundImage.getPixel(x, y);

                // Replace the green pixel with the background pixel.
                foregroundImage.setPixel(x, y, backgroundPixel);
            }
        }
    }


    // Step 8: Create a window to display the finished image.
    RenderWindow window(VideoMode(1024, 768), "Lab 06 - Image Compositing");


    // Step 9: Create a texture for our finished image.
    Texture tex1;

    // Load the modified foreground image into the texture.
    tex1.loadFromImage(foregroundImage);


    // Step 10: Create a sprite to display the texture.
    Sprite sprite1;
    sprite1.setTexture(tex1);


    // Step 11: Keep the window open until the user closes it.
    while (window.isOpen()) {

        // Check for window events.
        Event event;

        while (window.pollEvent(event)) {

            // Close the window if the user clicks X.
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Clear the previous frame.
        window.clear();

        // Draw the completed image.
        window.draw(sprite1);

        // Display everything in the window.
        window.display();
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
