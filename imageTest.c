// imageTest - A program that performs some image processing.
//
// This program is an example use of the image8bit module,
// a programming project for the course AED, DETI / UA.PT
//
// You may freely use and modify this code, NO WARRANTY, blah blah,
// as long as you give proper credit to the original and subsequent authors.
//
// João Manuel Rodrigues <jmr@ua.pt>
// 2023

#include <assert.h>
#include <errno.h>
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image8bit.h"
#include "instrumentation.h"

int main(int argc, char* argv[]) {
  program_name = argv[0];
  if (argc != 3) {
    error(1, 0, "Usage: imageTest input.pgm output.pgm");
  }


  ImageInit();
  
  printf("# LOAD image\n");
  InstrReset(); // to reset instrumentation
  Image img1 = ImageLoad(argv[1]);
  if (img1 == NULL) {
    error(2, errno, "Loading %s: %s", argv[1], ImageErrMsg());
  }

  // Try changing the behaviour of the program by commenting/uncommenting
  // the appropriate lines.

  /// Geometric transformations
  int x = 0;
  int y = 0;
  Image img2 = ImageCrop(img1,0,0, ImageWidth(img1)/6, ImageHeight(img1)/6);
  //int x ;
  //x= 0;
  //int y ;
 // y= 0;
  //img2 = ImageCrop(img1,x,y, ImageWidth(img1)/6, ImageHeight(img1)/6);

  //img2 = ImageRotate(img1);
  //if (img2 == NULL) {
  //  error(2, errno, "Rotating img2: %s", ImageErrMsg());
  //}

  //img2 = ImageMirror(img1);


  /// Pixel transformations
  //ImageNegative(img2);

  //ImageThreshold(img2, 100);
  //ImageThreshold(img2, 150);

  //ImageBrighten(img2, 1.3);
  //ImageBrighten(img2, 0.7);


  /// Operations on two images
  //img1 = ImageCrop(img2, ImageWidth(img2)/4, ImageHeight(img2)/4, ImageWidth(img2)/2, ImageHeight(img2)/2);
  
  //ImagePaste(img2, 40, 40, img1);

  //ImageBlend(img2, 40, 40, img1, 0.5);

  //if (ImageMatchSubImage(img1,  5*ImageWidth(img1)/6, 5*ImageHeight(img1)/6, img2)) {
   // printf("Match!\n")
  //} else {
   // printf("No match!\n");
  //}

 // if (ImageLocateSubImage(img1, &x, &y ,img2)) {
  // printf("Match!\n");
  //} else {
   //printf("No match!\n");
  //}

  /// Filtering

  ImageBlur(img1, 18, 18 );

  if (ImageSave(img1, argv[2]) == 0) {
    error(2, errno, "%s: %s", argv[2], ImageErrMsg());
  }

  //InstrPrintFile(); // to print instrumentation to a file
  InstrPrint(); // to print instrumentation
  ImageDestroy(&img1);
  ImageDestroy(&img2);
  return 0;
}

