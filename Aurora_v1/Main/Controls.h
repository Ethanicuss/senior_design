#ifndef CONTROLS_H
#define CONTROLS_H
void StartSong(String songName);
void Quit(void);
void SetupInterrupt(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency);
#endif

