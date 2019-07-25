1.  A header file for the standard input/output library. 

2.  Use instead of unsigned chars, shorts, ints and long longs. 
    Docuements your intents as you will be storing small numbers instead of chars.
    
3.  BYTE - 1 byte
    DWORD - 4 bytes
    LONG - 4 bytes
    WORD - 2 bytes

4.  HEX - 0x42 0x4D

5.  bfSize - BITMAPFILEHEADER Size
    Whole BMP, includes headerfile, which includes bisize.
    
    biSize - BITMANINFOHEADER size
    biSize is constant, 40 bytes.
    
6.  Negative biHeight means the bitmap is a top-down DIB. 
    Origin at top left corner.

7.  biBitCount defines the number of bits in each pizel and max number of colors in the BMP.

8.  For example; if the user does not have write permission, or if the memory is full.

9.  Because we only need to copy one structure at a time, for each read so to speak.

10. 3 (width) x 3 (bytes per pixel) = 9 bytes. Must add 3 to make it a multiple of 4.

11. To move the position pointer through the file system.

12. Indicates the current position of the pointer.
