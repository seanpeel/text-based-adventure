#include "Util.h"

#include <string>

bool Util::hasEnding(std::string const& str, std::string const& endStr) {
	if (str.length() >= endStr.length()) {
		return (0 == str.compare(str.length() - endStr.length(), endStr.length(), endStr));
	}
	else {
		return false;
	}
}
