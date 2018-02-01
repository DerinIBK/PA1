/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 *
 * @author CS 221: Basic Algorithms and Data Structures
**/

#include "chain.h"
#include "block.h"
#include "PNGutil.h"
#include "cs221util/PNG.h"
using namespace cs221util;

int main() {
   PNG png1;

   png1.readFromFile("images/rosegarden.png");
   PNG result1 = grayscale(png1);
   result1.writeToFile("images/out-ubcRose.png");
    printf("GOT IT1\n");
   Block b;
   b.build(png1,0,150,450,225);
   b.render(result1,450,300);
   result1.writeToFile("images/out-blocktest.png");
    printf("GOT IT2\n");
   Chain c(png1,1,16);
   for (int i = 1; i < c.size(); i*=2){
      c.moveToBack(1+c.size()*(i-1)/i, c.size()/(2*i));
   }
   PNG result2 = c.render(1,16);
   result2.writeToFile("images/out-moveToBack.png");
    printf("GOT IT3\n");
   Chain d(png1,2,8);
   d.swap(2,15);
   PNG result3 = d.render(2,8);
   result3.writeToFile("images/out-swapEasy.png");
    printf("GOT IT4\n");
   Chain e(png1,4,18);
    printf("GOT IT OG\n");
   Chain g(e);
   printf("GOT IT OG COPY\n");
   Chain f(result1,4,18);
   g.twist(f);
   PNG result6 = g.render(4,18);
   PNG result7 = f.render(4,18);
   result6.writeToFile("images/out-twistSame1.png");
   result7.writeToFile("images/out-twistSame2.png");

   return 0;
}
