#ifndef LCD_H
#define LCD_H

bool LCDSetup(void);
extern int currentLessonType = 0;
extern int currentLesson = 0;
extern int currentLearn = 0;
extern int currentPlay = 0;
extern int currentPcent = -1;
extern bool paused = true;

#endif
