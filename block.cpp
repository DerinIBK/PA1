#include "block.h"
#include <vector>
#include <cmath>

// Return the width of a block
int Block::width() const{
   return data.size();
}

// Return the height of a block
int Block::height() const{
   return data.at(0).size();
}


// Draws the current block at position (upLeftX,upLeftY) in im.
// Draw means replace the pixels
void Block::render(PNG & im, int upLeftX, int upLeftY) const {

   // Iterate through im, starting from a certain corner
   for (int x = 0; x < width(); x++){
       for(int y = 0; y < height(); y++){

            // The individual pixel of the image that we will be modifying
            HSLAPixel *pixel = im.getPixel(x+upLeftX, y+upLeftY);

            // Block pixel
            HSLAPixel blockPixel = data.at(x).at(y);

            // now pointing to the blocks values for saturation, luminance, hue and alpha
            pixel->s = blockPixel.s;
            pixel->l = blockPixel.l;
            pixel->h = blockPixel.h;
            pixel->a = blockPixel.a;
            
        }
    }
   return;
}

// Grab the block data and store it into the data vector
// You can find the data vector in the block.h file
// From im, grabs the rows by cols block of pixels whose upper left corner is position (upLeftX,upLeftY).
// (0,0) is the upper left position of the image
void Block::build(PNG & im, int upLeftX, int upLeftY, int cols, int rows) {  

    // Iterate through the section of the image you are examining right now
    for (int x = upLeftX; x < cols + upLeftX; x++) {

        // Declare a vector of HSLAPixel's
        vector<HSLAPixel> vector;
        
        for (int y = upLeftY; y < rows + upLeftY; y++) {
            // Get the pixel at point (x,y)
            HSLAPixel *pixel = im.getPixel(x, y);
            // Put that pixel's value in the vector (dereference)
            vector.push_back(*pixel);
        }
        // Add the vector to the back of data vector
        data.push_back(vector);
    }
   return;
}