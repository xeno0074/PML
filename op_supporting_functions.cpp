#include "interface.h"

//	Check if a string is a valid name for an identifier
bool Interface::INTERFACE::CheckIdentifier(std::string identifier) {
	bool valid = true;
	if (!((identifier[0] > 64 && identifier[0] < 91)
		|| identifier[0] == 95
		|| (identifier[0] > 96 && identifier[0] < 123))
		) {
		valid = false;
		return valid;
	}
	for (int i = 1; i < identifier.length(); i++)
		if (!((int(identifier[i]) > 64 && identifier[i] < 91)
			|| identifier[i] == 95
			|| (identifier[i] > 96 && identifier[i] < 123)
			|| (identifier[i] > 47 && identifier[i] < 58))
			) {
			valid = false;
			return valid;
		}
	return valid;
}

bool Interface::INTERFACE::CheckExpressionSeparator(char separator) {
	bool valid = true;

	return valid;
}