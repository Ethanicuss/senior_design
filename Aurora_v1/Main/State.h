#ifndef STATE_H
#define STATE_H
enum Button {NONE = 0, Btn1 = 1, Btn2 = 2, Btn3 = 3, Btn4 = 4, Btn5 = 5, Btn6 = 6, Btn7 = 7, Btn8 = 8, BackBtn = 9};
enum State {HOME = 0, LESSONS = 1, LEARN = 2, PLAY = 3, SETTINGS = 4, SHIFTING = 5, SUSTAIN = 6, CHORDS = 7, PLAYING_LESSON = 8, LEARNING_SONG = 9, PLAYING_SONG = 10, FINISHED_LESSON = 11, FINISHED_LEARNING = 12, FINISHED_PLAYING = 13, PAUSED = 14, CHOOSE_BPM = 15, REC_RED = 16, REC_BLUE = 17, REC_GREEN = 18, REC_PURPLE = 19, REC_OPEN = 20, REC_TEMPO = 21, REC_NEXT = 22, REC_MODE = 23, DOWNLOADS = 24, DOWNLOADS_LEARN = 25, DOWNLOADS_PLAY = 26};

extern enum Button BtnPressed;
extern enum State CurrState;
extern enum State PreState;

extern int Ycoor;
extern int Xcoor;

#endif
