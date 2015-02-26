/*
 Gadget Factory
 Example showing how to load an image using Alvaro's ZPUino VGA Adapter
 To learn more about using DesignLab please visit http://learn.gadgetfactory.net

 Related library documentation:
    Use the Adafruit GFX library to program this VGA adapter.
    https://learn.adafruit.com/adafruit-gfx-graphics-library/overview

 Special Notes:
   To use the SD card you need to select a hardware option that includes an SD card such as the ZPUino_Wings circuit or the Computing_Shield2 circuit.
   Be sure you have uncommented the CSPIN associated with your circuit.
   
   You can load the images from a SD card or SmallFS (SmallFS copies anything in the sketches smallfs folder into SPI Flash and then main memory).
   Just uncomment the method you want to use in the setup section.
   If using the SD card you can find example images in this sketches directory by pressing CTRL-K.
   The PNG demo is recommended to be done from the SD card.
   
   If downloading from SD card you can bypass the long time it takes to load the smallfs file by holding left shift while presseing "Upload" icon. It should say - Upload To Memory.
   
 created 2015
 by Alvaro Lopes
 http://www.gadgetfactory.net
 
 This example code is in the public domain.
 */
 
//Uncomment to use with a Computing Shield on Papilio DUO
#define circuit Computing_Shield2
#define CSPIN 16

//Uncomment to use with a LogicStart Shield on Papilio DUO
//#define circuit LogicStart_Shield2

//Uncomment to use with a Arcade MegaWing on Papilio Pro
//#define circuit Arcade_MegaWing2

//Uncomment to use with a LogicStart MegaWing on Papilio Pro
//#define circuit LogicStart_MegaWing2

//Uncomment to use with a VGA Wing connected to AH Wingslot and SD card connected to CL on Papilio DUO or Papilio Pro
//#define circuit ZPUino_Wings
//#define CSPIN WING_CL4

#include "jpeglib.h"
#include "SPI.h"
#include "FatFS.h"
#include "png.h"
#include "zlib.h"
#include "ZPUino_GFX.h"
#include "Adafruit_GFX.h"
#include "PLL.h"
#include "Timer.h"
#include "SmallFS.h"

ZPUino_GFX gfx;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting app");
  SmallFS.begin();
  gfx.begin();
  Serial.println("Starting spi");
  SPI.begin();
  // put your setup code here, to run once:
  Serial.println("Starting FatFS");

  FatFS.begin(SPI, CSPIN);
  SPI.setClockDivider(SPI_CLOCK_DIV2);

  Serial.println("Reading image");
  //readpng("/sd/image.png");
  //readjpeg("/sd/image.jpg");
  readjpeg("/smallfs/image.jpg");
}

void loop() {
  // put your main code here, to run repeatedly:
}

int width, height;

png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

#define COLOR_BYTES 2
#define COLOR_WEIGHT_R 5
#define COLOR_WEIGHT_G 6
#define COLOR_WEIGHT_B 5

#define COLOR_SHIFT_R (COLOR_WEIGHT_B+COLOR_WEIGHT_G)
#define COLOR_SHIFT_G (COLOR_WEIGHT_B)
#define COLOR_SHIFT_B 0


unsigned short *imgbuf;

int readpng(const char*name)
{
    unsigned char header[8];
    int y;

    FILE *f = fopen(name, "rb");

    if (!f) {
        perror("fopen");
        return -1;
    }

    fread(header, 1, 8, f);

    if (png_sig_cmp(header, 0, 8)) {
        fprintf(stderr,"Invalid PNG file");
        fclose(f);
        return -1;
    }
    fprintf(stderr,"Initialize read struct\r\n");
    /* initialize stuff */
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    fprintf(stderr,"Initialized read struct\r\n");

    if (!png_ptr) {
        fprintf(stderr,"Cannot read struct\n");
        return -1;
    }

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        fprintf(stderr,"Cannot create struct\n");
        return -1;
    }

    png_init_io(png_ptr, f);
    png_set_sig_bytes(png_ptr, 8);

    png_read_info(png_ptr, info_ptr);

    width = png_get_image_width(png_ptr, info_ptr);
    height = png_get_image_height(png_ptr, info_ptr);
    color_type = png_get_color_type(png_ptr, info_ptr);
    bit_depth = png_get_bit_depth(png_ptr, info_ptr);

    number_of_passes = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);

    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
    for (y=0; y<height; y++)
        row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr,info_ptr));

    png_read_image(png_ptr, row_pointers);
    printf("All read\r\n");
    printf("Image information:\r\n\r\n");
    printf("Width:     %d\r\n", width);
    printf("Height:    %d\r\n", height);
    printf("ColorType: %d\r\n", color_type);
    printf("Bit Depth: %d\r\n", bit_depth);
    fclose(f);

    printf("Converting to packed pixel, please wait....");
#if 0
    /* Allocate a linear buffer for the image */
    imgbuf = (uint16_t*)malloc(width*height*2);
    printf("Alloc: 0x%08x\n", imgbuf);
#else
    imgbuf = gfx.getFramebuffer();
#endif
    int x;
    unsigned short v;

    for (y=0; y<height; y++) {
        png_byte* row = row_pointers[y];
        for (x=0; x<width; x++) {
            png_byte* ptr = &(row[x*3]);
            /* printf("Pixel at position [ %d - %d ] has RGB values: %02x - %02x - %02x\n",
             x, y, ptr[0], ptr[1], ptr[2]);*/

            /* weight each of the RGB. We dont support 8 BPP */

            ptr[0] = (ptr[0] >> (8 - COLOR_WEIGHT_R));
            ptr[1] = (ptr[1] >> (8 - COLOR_WEIGHT_G));
            ptr[2] = (ptr[2] >> (8 - COLOR_WEIGHT_B));

            v = (ptr[0]<<(COLOR_SHIFT_R)) + (ptr[1]<<COLOR_SHIFT_G) + (ptr[2]<<COLOR_SHIFT_B);
            *imgbuf++=v;
        }
    }

    /* Release memory */

    for (y=0; y<height; y++) {
        png_byte* row = row_pointers[y];
        free(row);
    }
    free(row_pointers);
    printf("done.\r\n");
    //printf("Displaying image...\r\n");
    /* Display it */
    //memcpy( gfx.getFramebuffer(), imgbuf, 640*480*2);
    return 0;
}


void jpeg_error(jpeg_common_struct*)
{
    printf("Error reading JPEG\r\n");
    while (1) {
    }
}

int readjpeg(const char *file)
{
    jpeg_decompress_struct cinfo;

    jpeg_error_mgr defaultErrorManager;

    cinfo.err = jpeg_std_error(&defaultErrorManager);

    defaultErrorManager.error_exit = &jpeg_error;

    FILE* pFile = fopen(file, "rb");
    if (!pFile)
        return -1;

    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, pFile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    printf("JPEG image info: %d x %d\n", cinfo.image_width, cinfo.image_height);

    unsigned row_stride = cinfo.output_width * cinfo.output_components;

    unsigned char *buffer = (unsigned char*)malloc(row_stride);

    unsigned short v;
    uint16_t *imgbuf = gfx.getFramebuffer();
 
    while(cinfo.output_scanline < cinfo.image_height)
    {
        int s = jpeg_read_scanlines(&cinfo, &buffer, 1);
        printf("%d\r\n",cinfo.output_scanline);
        unsigned char *ptr = buffer;
        int x;
        for (x=0; x<cinfo.image_width; x++) {
            uint16_t r = (ptr[0] >> (8 - COLOR_WEIGHT_R));
            uint16_t g = (ptr[1] >> (8 - COLOR_WEIGHT_G));
            uint16_t b = (ptr[2] >> (8 - COLOR_WEIGHT_B));
            v = (r<<(COLOR_SHIFT_R)) + (g<<COLOR_SHIFT_G) + (b<<COLOR_SHIFT_B);
            *imgbuf=v;
            ptr+=3;
            imgbuf++;
        }
    }
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(pFile);
    free(buffer);
    printf("All done\r\n");
    return 0;

}
