#include "ColorMsg.h"

namespace sict {
	ColorMsg::~ColorMsg() {
		delete[] msg;
	}
	const ColorMsg& ColorMsg::Red(const char* msg) {
		if (msg != nullptr) {
			this->msg = new char[strlen(msg) + 1];
			std::strcpy(this->msg, msg);
			code = red;
		}
        return *this;
	}
	const ColorMsg& ColorMsg::Green(const char* msg) {
		if (msg != nullptr) {
			this->msg = new char[strlen(msg) + 1];
			std::strcpy(this->msg, msg);
			code = green;
		}
        return *this;
	}
	const ColorMsg& ColorMsg::Cyan(const char* msg) {
		if (msg != nullptr) {
			this->msg = new char[strlen(msg) + 1];
			std::strcpy(this->msg, msg);
			code = cyan;
		}
        return *this;
	}
	const ColorMsg& ColorMsg::Blue(const char* msg) {
		if (msg != nullptr) {
			this->msg = new char[strlen(msg) + 1];
			std::strcpy(this->msg, msg);
			code = blue;
		}
        return *this;
	}
	void ColorMsg::display(std::ostream& os) const {
		os << _xterm_begin;
		switch (code) {
		case Code::red:
			os << _red;
			break;
		case Code::green:
			os << _green;
			break;
		case Code::cyan:
			os << _cyan;
			break;
        case Code::blue:
			os << _blue;
			break;
		};
		os << msg << _xterm_end;
	}
	std::ostream& operator<<(std::ostream& os, const ColorMsg& color) {
		color.display(os);
		return os;
	}
}