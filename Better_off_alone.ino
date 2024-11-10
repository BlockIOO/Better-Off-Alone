#include "pitches.h"
int Music = 8; //4.5
int bpm = 180;
int notelen = 60000/(bpm*4); //bar = 16

// notes in the melody:
int melody[] = {
  //1
  NOTE_B4,0,//2
  0,NOTE_AS4,//2
  NOTE_B4,0,//2
  0,//1
  //5
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,//5
  0,NOTE_FS5,0,NOTE_FS5,0,NOTE_DS5,//6
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,//5
  0,NOTE_E5,0,NOTE_E5,0,NOTE_DS5,//6
  //5 again
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,//5
  0,NOTE_FS5,0,NOTE_FS5,0,NOTE_DS5,//6
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,//5
  0,NOTE_E5,0,NOTE_E5,0,NOTE_DS5,//6
  //9
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,NOTE_B4,0,NOTE_B4,//8
  0,NOTE_AS4,0,NOTE_FS4,NOTE_FS5,0,NOTE_FS5,0,NOTE_DS5,//9
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,NOTE_B4,0,NOTE_B4,//8
  0,NOTE_AS4,0,NOTE_FS4,NOTE_E5,0,NOTE_E5,0,NOTE_DS5,//9
  //13
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,NOTE_B4,0,NOTE_B4,//8
  0,NOTE_AS4,0,NOTE_FS4,NOTE_FS5,0,NOTE_FS5,0,NOTE_DS5,//9
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,NOTE_B4,0,NOTE_B4,//8
  0,NOTE_AS4,0,NOTE_FS4,NOTE_E5,0,NOTE_E5,0,NOTE_DS5,//9
  //13 again
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,NOTE_B4,0,NOTE_B4,//8
  0,NOTE_AS4,0,NOTE_FS4,NOTE_FS5,0,NOTE_FS5,0,NOTE_DS5,//9
  NOTE_B4,0,NOTE_B4,NOTE_GS4,0,NOTE_B4,0,NOTE_B4,//8
  0,NOTE_AS4,0,NOTE_FS4,NOTE_E5,0,NOTE_E5,0,NOTE_DS5,//9
  //17
  NOTE_B4//1
};
//semi quavers, 4 in a crotchet, 16 in a bar
int noteDurations[] = {
  //1
  4,12,
  14,2,
  4,12,
  16,
  //5
  2,2,2,2,8,
  8,2,1,2,1,2,
  2,2,2,2,8,
  8,2,1,2,1,2,
  //5 again
  2,2,2,2,8,
  8,2,1,2,1,2,
  2,2,2,2,8,
  8,2,1,2,1,2,
  //9
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,1,2,1,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,1,2,1,2,
  //13
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,1,2,1,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,1,2,1,2,
  //13 again
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,1,2,1,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,1,2,1,2,
  //16
  12
};
void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < (sizeof(melody)/sizeof(int))/*154*/; thisNote++) {
    int noteDuration = noteDurations[thisNote]*notelen;
    tone(Music, melody[thisNote],noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(Music);
  }
}
void loop() {
  // no need to repeat the melody.
}
