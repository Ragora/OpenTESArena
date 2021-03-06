#ifndef CHOOSE_NAME_PANEL_H
#define CHOOSE_NAME_PANEL_H

#include <string>

#include "Panel.h"

// If Escape is pressed here, just go to the class list (even if the user went
// the answer questions path instead).

// I looked into SDL_StartTextInput(), but I don't quite get it yet. I'll just
// listen for plain English characters for now, since international characters are
// way outside the project scope right now.

// No numbers or symbols (i.e., @, #, $) are allowed in the name for now.

class Button;
class CharacterClass;
class Renderer;
class Surface;
class TextBox;

class ChooseNamePanel : public Panel
{
private:
	static const int MAX_NAME_LENGTH;

	std::unique_ptr<Surface> parchment;
	std::unique_ptr<TextBox> titleTextBox, nameTextBox;
	std::unique_ptr<Button> backToClassButton, acceptButton;
	std::unique_ptr<CharacterClass> charClass;
	std::string name;	
protected:
	virtual void handleEvents(bool &running) override;
	virtual void handleMouse(double dt) override;
	virtual void handleKeyboard(double dt) override;
public:
	ChooseNamePanel(GameState *gameState, const CharacterClass &charClass);
	virtual ~ChooseNamePanel();

	virtual void tick(double dt, bool &running) override;
	virtual void render(Renderer &renderer) override;
};

#endif
