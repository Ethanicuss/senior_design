#ifndef LCD_H
#define LCD_H

bool LCDSetup(void);
extern int currentLessonType = 0;
extern int currentLesson = 0;
extern int currentLearn = 0;
extern int currentPlay = 0;
extern int currentPcent = -1;
extern int currentPage = 0;
extern bool paused = true;
extern bool openStrings[6] = {false, false, false, false, false, false};

#endif
