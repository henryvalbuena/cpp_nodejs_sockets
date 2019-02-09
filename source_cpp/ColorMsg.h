/*
This modules takes a ctring and puts it into the ostream with
color code for xterm terminals
*/

#ifndef SICT_COLORMSG
#define SICT_COLORMSG
#include <iostream>
#include <cstring>
namespace sict {
	const size_t color_size = 3;
	const size_t term_size = 5;

	class ColorMsg {
		enum Code { red, green, cyan, blue };
		const char _xterm_begin[term_size + 1];
		const char _xterm_end[term_size + 1];
		const char _red[color_size + 1];
		const char _green[color_size + 1];
		const char _cyan[color_size + 1];
        const char _blue[color_size + 1];
		char* msg;
		Code code;
	public:
		ColorMsg() : _xterm_begin("\33[1;"), _xterm_end("\33[0m"),
			_red("31m"), _green("32m"), _cyan("36m"), _blue("94m"), 
            msg(nullptr), code(red) {};
		~ColorMsg();
		// Append the message with color code for red
		// returns a const ColorMsg & for ostream
		// cascading
		const ColorMsg& Red(const char* message);
		// Append the message with color code for green
		// returns a const ColorMsg & for ostream
		// cascading
		const ColorMsg& Green(const char* message);
		// Append the message with color code for cyan
		// returns a const ColorMsg & for ostream
		// cascading
		const ColorMsg& Cyan(const char* message);
		// Append the message with color code for blue
		// returns a const ColorMsg & for ostream
		// cascading
        const ColorMsg& Blue(const char* message);
		// Insert to the ostream current object data
		// color code and message
		void display(std::ostream& os) const;
	};
	// Insertion operator overload for ColorMsg
	std::ostream& operator<<(std::ostream& os, const ColorMsg& color);
}
#endif // SICT_COLORMSG