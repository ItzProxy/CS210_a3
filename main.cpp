#include "main.h"
// This is the prototype for the function that does all
// the editing.
int editor();
// This is the prototype for a special function, written
// in C, that reads one character at a time from the
// keyboard without requiring that Enter be pressed after
// each character is entered. JUST USE IT.
char getch();

int main()
{
	return editor();
}

// Valid keys recognized by the editor are:
// Any printable character
// Backspace - move cursor to the left deleting one character
// Delete - delete one character at the current cursor position
// Home - move cursor to the beginning of the text
// End - move cursor to the end of the text
// Move Cursor Left - move cursor one character to the left
// Move Cursor Right - move cursor one character top the right
int editor()
{
	list gg;
	char c;
	int i;
	int j;
	// Characters are stored in text [1] to text [64].
	char text[MAX_TEXT_LENGTH];
	// First valid character in text [] is at position 1.
	int cursorPosition = 1;

	// The system function is used to execute any valid
	// UNIX/Linux command from a program. This invocation of
	// system will execute the clear command so that you
	// start with a clear screen. Type clear at the Linux
	// command prompt to see what happens.
	//system ("clear");

	// Prepare the screen for input. The carat character
	// (i.e., '^') indicates the cursor position.
	cout << " " << endl;
	cout << "^" << endl;

	// This while loop allows a line of text to be edited until
	// a termination character is entered (i.e., '.', '?', '!').
	while (1)
	{
		// Reads a character from the keyboard.
		c = getch();
		// The Backspace key was pressed.
		if (c == 8)
		{
			if (cursorPosition > 1)
			{
				cursorPosition--;
				if (cursorPosition == gg.getLen() - 1)
				{
					text[cursorPosition] = ' ';
					gg.insertTail(' ');
					gg.insertTail(' ');
				}
				else
				{
					gg.backdelNode();
				}
			}
		}
		// One of the cursor control keys was pressed.
		else if (c == 27)
		{
			// This gets rid of a character in the input stream
			// that you don't need.
			c = getch();
			// This gets a character that you do need.
			c = getch();
			// One of the Insert, Delete, Home, End, PgUp, or PgDn
			// keys was pressed. The Insert, PgUp, and PgDn keys
			// are ignored.
			if (c >= 49 && c <= 54)
			{
				// The Home key was pressed.
				if (c == 49)
				{
					gg.resetToHead();
					cursorPosition = 1;
				}
				// The Delete key was pressed.
				else if (c == 51)
				{
					if (cursorPosition < gg.getLen() + 1)
					{
						if (gg.getLen() >= 1)
						{
							int temp = gg.getLen();
							temp--;
							gg.setLen(temp);
						}
						gg.deleteNode();
					}
				}
				// The End key was pressed.
				else if (c == 52)
				{
					gg.findTail();
				}
				// This gets rid of a character in the input stream
				// that you don't need.
				c = getch();
			}
			// The Move Cursor Right key was pressed.
			else if (c == 67)
			{
				if (cursorPosition < gg.getLen() + 1)
				{
					cursorPosition++;
					gg.iterateRight();
				}
			}
			// The Move Cursor Left key was pressed.
			else if (c == 68)
			{
				if (cursorPosition > 1)
				{
					cursorPosition--;
					gg.iterateLeft();
				}
			}
		}
		// The key corresponding to a printable character
		// was pressed.
		else if (c > 31 && c < 127)
		{
			if (gg.getLen() < MAX_TEXT_LENGTH)
			{
				text[cursorPosition] = c;
				gg.insert(c);
				cursorPosition++;
			}
		}
		// Clears the screen after each keystroke to make it
		// appear as though all the input is occurring on the
		// same line. Comment this out to see what is really
		// happening.
		//system ("clear");
		// Print text [] to the screen.
		i = 1;
		j = 1;
		gg.iteratePrint();
		/*
		while (i <= gg.getLen())
		{
		j = i;
		cout << gg.readP();
		// Clear all characters from text [] following the
		// termination character.
		if (gg.readP() == '.' || gg.readP() == '?' || gg.readP() == '!'){
		gg.setLen(i);
		break;
		}
		i++;
		}
		*/
		cout << endl;
		// If a termination character key was pressed, break out of
		// the outermost while loop.
		if (gg.readP() == '.' || gg.readP() == '?' || gg.readP() == '!')
		{
			break;
		}
		// Position the cursor.
		i = 1;
		while (i < cursorPosition)
		{
			i++;
			cout << " ";
		}
		cout << "^" << endl;
	}

	return 0;
}

// This is a special function, written in C, that reads
// one character at a time from the keyboard without
// requiring that Enter be pressed after each character
// is entered. YOU DON'T NEED TO KNOW HOW IT WORKS AND
// YOU SHOULDN'T CHANGE IT IN ANY WAY!
char getch()
{
	char buffer = 0;
	struct termios old = { 0 };

	fflush(stdout);
	if (tcgetattr(0, &old) < 0)
	{
		perror("tcsetattr()");
	}
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old) < 0)
	{
		perror("tcsetattr ICANON");
	}
	if (read(0, &buffer, 1) < 0)
	{
		perror("read ()");
	}
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &old) < 0)
	{
		perror("tcsetattr ~ICANON");
	}

	return buffer;
}
