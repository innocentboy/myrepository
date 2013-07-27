#define PRESSED (1)
#define RELEASED (0)
#define ESC (1)
typedef int BOOLEAN;
char *Keys_Tbl[88] = {
/* 1..8 */ "Escape", "1", "2", "3", "4", "5", "6", "7",
/* 9..15 */ "8", "9", "0", "-", "=", "Backspace", "Tab",
/* 16..25 */ "q", "w", "e", "r", "t", "y", "u", "i", "o", "p",

/* 26..29 */ "[", "]", "Enter/KeypadEnter", "Left/RightCtrl",
/* 30..39 */ "a", "s", "d", "f", "g", "h", "j", "k", "l", ";",
/* 40..42 */ "'", "`", "LeftShift/PrintScreen",
/* 43..45 */ "\\(101-keyOnly)/#(102-keyOnly)", "z", "x",
/* 46..53 */ "c", "v", "b", "n", "m", ",", ".", "/",
/* 54..55 */ "RightShift", "Keypad*/PrintScreen",
/* 56..59 */ "Left/RightAlt", "Spacebar", "Caps Lock", "F1",
/* 60..67 */ "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9",
/* 68..70 */ "F10", "NumLock/Pause", "ScrollLock",
/* 71..72 */ "Home/Keypad7", "UpArrow/Keypad8",
/* 73..74 */ "PageUp/Keypad9", "Keypad-",
/* 75..76 */ "LeftArrow/Keypad4", "Keypad5",
/* 77..78 */ "RightArrow/Keypad6", "Keypad+",
/* 79..80 */ "End/Keypad1", "DownArrow/Keypad2",
/* 81..82 */ "PageDown/Keypad3", "Insert/Keypad0",
/* 83..85 */ "Delete/Keypad.", "undefined", "undefined",
/* 86..88 */ "\(102-keyOnly)", "F11", "F12"
};
BOOLEAN Key_Stat[88];
int main( void )
{
int i, key;
while( (key=inportb(0x60))!=ESC )
{
/* Store the status of keys... */
if ( key<128 )
Key_Stat[key-1] = PRESSED;
else
Key_Stat[key-1-128] = RELEASED;
/* Now, show the status... */
for ( i=0; i<88 ; ++i )
if ( Key_Stat[i]==PRESSED )
printf( "%s ", Keys_Tbl[i] );
printf( "\n" );
}
return(0);
} /*--main( )----------*/

