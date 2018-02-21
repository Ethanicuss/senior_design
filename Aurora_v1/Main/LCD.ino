/* TODO: Any function that has "Draw" in it.
 *       
 *       This Module will just draw each screen.
 */

#define TFT_DC 9
#define TFT_CS 10
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC);

#define SD_CS 4


void LCDSetup(void) {
  Serial.print("In LCDSetup");
  
  tft.begin(HX8357D);
  
  tft.setRotation(3);
  tft.fillScreen(HX8357_WHITE);
  
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
  }
  Serial.println("OK!");

  //bmpDraw("jumpers.bmp", 0, 0);
}

 void DrawHomeScreen(){
  tft.fillRect(0, 0, 240, 200, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0x981F);
  tft.drawLine(260, 105, 460, 105, HX8357_WHITE);
  tft.drawLine(260, 215, 460, 215, HX8357_WHITE);

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(268, 70);
  tft.print("LESSONS");

  tft.setCursor(295, 170);
  tft.print("LEARN");

  tft.setCursor(310, 283);
  tft.print("PLAY");

//  bmpDraw("play.bmp", 0, 0); 
 }

 /*********** HOME MENU SCREENS **********/
 void DrawLessonsScreen(){
  bmpDraw("lessons.bmp", 0, 0);
  //shwos lessons - shifting, sustains, chords
 }

 void DrawLearnScreen(){
  bmpDraw("learn.bmp", 0, 0);
  //shows song list for learning
 }

 void DrawPlayScreen(){
  tft.fillRect(0, 50, 220, 200, HX8357_WHITE);
  tft.fillRect(240, 0, 240, 320, 0xF81D);
  tft.drawLine(260, 80, 460, 80, 0xFE5F);
  tft.drawLine(260, 160, 460, 160, 0xFE5F);
  tft.drawLine(260, 240, 460, 240, 0xFE5F);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0xF81D);
  tft.setCursor(70, 155);
  tft.print("PLAY");

  tft.setTextColor(0x9CF3);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(20, 180);
  tft.print("SELECT A SONG TO PLAY");
  tft.setCursor(60, 198);
  tft.print("ON YOUR OWN");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setCursor(11, 33);
  tft.print("<");

  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(275, 40);
  tft.print("WONDERWALL");

  tft.setCursor(280, 120);
  tft.print("FREE FALLIN'");

  tft.setCursor(318, 200);
  tft.print("AFRICA");

  tft.setCursor(300, 280);
  tft.print("I'M YOURS");


  tft.setTextColor(0xFE5F);
  tft.setFont(&JosefinSans_Bold8pt7b);
  tft.setCursor(335, 60);
  tft.print("OASIS");

  tft.setCursor(318, 140);
  tft.print("TOM PETTY");

  tft.setCursor(340, 220);
  tft.print("TOTO");

  tft.setCursor(310, 300);
  tft.print("JASON MRAZ");
 }

 void DrawSettingsScreen(){
  bmpDraw("play.bmp", 0, 0);
  //shows settings
 }

 /*********** LESSONS SCREENS ***********/

 void DrawShiftingScreen(){
   bmpDraw("shifting.bmp", 0 , 0);
  // shows shifting 101, 102, 103
 }

 void DrawSustainScreen(){
   bmpDraw("sustain.bmp", 0 , 0);
  // shows sustains 101, 102, 103
 }

 void DrawChordsScreen(){
   bmpDraw("chords.bmp", 0 , 0);  
  // shows chords 101, 102, 103
 }

 /*********** SHIFTING LESSON ***********/
 void DrawShiftingLesson(){
  bmpDraw("lessonpl.bmp", 0 , 0);
  // shows current progress in lesson
 }

 /*********** SUSTAIN LESSON ***********/
 void DrawSustainLesson(){
  // shows current progress in lesson
 }

 /*********** CHORDS LESSON ***********/
 void DrawChordsLesson(){
  // shows current progress in lesson
 }

 /*********** WHILE PLAYING SCREENS******/
 void DrawLearnSong(){
  /* shows current progress while learning song
    
     Should keep track of which song was selected
     just a suggestion:
     switch(song){ // In main you can say song=1, song=2, etc...
      case(1):
        print("Wonderwall");
      case(2):
        print("Hey Jude");
      etc...

     ^ May not be the best way, just my first thought.
  */
  bmpDraw("learnpl.bmp", 0 , 0);
 }

 void DrawPlaySong(int song){
  tft.fillRect(0, 0, 480, 260, HX8357_WHITE);
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);

  tft.setFont(&JosefinSans_BoldItalic20pt7b);
  tft.setTextColor(0x07EE);
  tft.setCursor(360,40);
  tft.print("PLAY");

  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(55, 304);
  tft.print("PAUSE");
  tft.setCursor(310, 304);
  tft.print("QUIT");

  switch(song) {
    case 1:
      tft.setTextColor(0x07EE);
      tft.setCursor(87, 120);
      tft.print("WONDERWALL");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(205, 152);
      tft.print("OASIS");
      break;
      
    case 2:
      tft.setTextColor(0x07EE);
      tft.setCursor(105, 120);
      tft.print("FREE FALLIN'");
    
      tft.setFont(&JosefinSans_Bold12pt7b);
      tft.setTextColor(0x9CF3);
      tft.setCursor(173, 152);
      tft.print("TOM PETTY");
      break;

//    case 3:

  //    break;

   // case 4:

 //     break;
  }
 }
 

 /********** FINSIHED SCREENS *******/
 void DrawFinishedLessons(){
  /* Should show the results of the learning screen
   *  and give you the appropriate buttons
   */
   bmpDraw("lessonen.bmp", 0 , 0);
 }

 void DrawFinishedLearning(){
  /* Should show the results of the learning screen
   *  and give you the appropriate buttons
   */
   bmpDraw("learnpau.bmp", 0 , 0);
   }

 void DrawFinishedPlaying(){
  tft.fillRect(0, 260, 480, 60, 0x9CF3);
  tft.drawLine(241, 268, 241, 312, HX8357_WHITE);
  
  tft.setFont(&JosefinSans_Bold20pt7b);
  tft.setTextColor(HX8357_WHITE);
  tft.setCursor(50, 304);
  tft.print("SONGS");
  tft.setCursor(300, 304);
  tft.print("HOME");

  tft.setTextColor(0x9CF3);
  tft.setCursor(87, 50);
  tft.print("WONDERWALL");
  tft.setFont(&JosefinSans_Bold12pt7b);
  tft.setCursor(205, 78);
  tft.print("OASIS");

  tft.fillRect(75, 90, 330, 94, 0x073F);  
 }

// This function opens a Windows Bitmap (BMP) file and
// displays it at the given coordinates.  It's sped up
// by reading many pixels worth of data at a time
// (rather than pixel by pixel).  Increasing the buffer
// size takes more of the Arduino's precious RAM but
// makes loading a little faster.  20 pixels seems a
// good balance.

#define BUFFPIXEL 20

void bmpDraw(char *filename, uint8_t x, uint16_t y) {

  File     bmpFile;
  int      bmpWidth, bmpHeight;   // W+H in pixels
  uint8_t  bmpDepth;              // Bit depth (currently must be 24)
  uint32_t bmpImageoffset;        // Start of image data in file
  uint32_t rowSize;               // Not always = bmpWidth; may have padding
  uint8_t  sdbuffer[3*BUFFPIXEL]; // pixel buffer (R+G+B per pixel)
  uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
  boolean  goodBmp = false;       // Set to true on valid header parse
  boolean  flip    = true;        // BMP is stored bottom-to-top
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0, startTime = millis();

  if((x >= tft.width()) || (y >= tft.height())) return;

  Serial.println();
  Serial.print(F("Loading image '"));
  Serial.print(filename);
  Serial.println('\'');

  // Open requested file on SD card
  if ((bmpFile = SD.open(filename)) == NULL) {
    Serial.print(F("File not found"));
    return;
  }

  // Parse BMP header
  if(read16(bmpFile) == 0x4D42) { // BMP signature
    Serial.print(F("File size: ")); Serial.println(read32(bmpFile));
    (void)read32(bmpFile); // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile); // Start of image data
    Serial.print(F("Image Offset: ")); Serial.println(bmpImageoffset, DEC);
    // Read DIB header
    Serial.print(F("Header size: ")); Serial.println(read32(bmpFile));
    bmpWidth  = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    if(read16(bmpFile) == 1) { // # planes -- must be '1'
      bmpDepth = read16(bmpFile); // bits per pixel
      Serial.print(F("Bit Depth: ")); Serial.println(bmpDepth);
      if((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

        goodBmp = true; // Supported BMP format -- proceed!
        Serial.print(F("Image size: "));
        Serial.print(bmpWidth);
        Serial.print('x');
        Serial.println(bmpHeight);

        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * 3 + 3) & ~3;

        // If bmpHeight is negative, image is in top-down order.
        // This is not canon but has been observed in the wild.
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = false;
        }

        // Crop area to be loaded
        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= tft.width())  w = tft.width()  - x;
        if((y+h-1) >= tft.height()) h = tft.height() - y;

        // Set TFT address window to clipped image bounds
        tft.setAddrWindow(x, y, x+w-1, y+h-1);

        for (row=0; row<h; row++) { // For each scanline...

          // Seek to start of scan line.  It might seem labor-
          // intensive to be doing this on every line, but this
          // method covers a lot of gritty details like cropping
          // and scanline padding.  Also, the seek only takes
          // place if the file position actually needs to change
          // (avoids a lot of cluster math in SD library).
          if(flip) // Bitmap is stored bottom-to-top order (normal BMP)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else     // Bitmap is stored top-to-bottom
            pos = bmpImageoffset + row * rowSize;
          if(bmpFile.position() != pos) { // Need seek?
            bmpFile.seek(pos);
            buffidx = sizeof(sdbuffer); // Force buffer reload
          }

          for (col=0; col<w; col++) { // For each pixel...
            // Time to read more pixel data?
            if (buffidx >= sizeof(sdbuffer)) { // Indeed
              bmpFile.read(sdbuffer, sizeof(sdbuffer));
              buffidx = 0; // Set index to beginning
            }

            // Convert pixel from BMP to TFT format, push to display
            b = sdbuffer[buffidx++];
            g = sdbuffer[buffidx++];
            r = sdbuffer[buffidx++];
            tft.pushColor(tft.color565(r,g,b));
          } // end pixel
        } // end scanline
        Serial.print(F("Loaded in "));
        Serial.print(millis() - startTime);
        Serial.println(" ms");
      } // end goodBmp
    }
  }

  bmpFile.close();
  if(!goodBmp) Serial.println(F("BMP format not recognized."));
}

// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.

uint16_t read16(File &f) {
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(File &f) {
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}
