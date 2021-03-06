#ifndef CHOOSE_ATTRIBUTES_PANEL_H
#define CHOOSE_ATTRIBUTES_PANEL_H

#include <string>

#include "Panel.h"

// This panel is for choosing character creation attributes and the portrait.

// I think it should be used for level-up purposes, since distributing points is
// basically identical to setting your character's original attributes.

// Maybe there could be a "LevelUpPanel" for that instead.

class Button;
class CharacterClass;
class Renderer;
class TextBox;

enum class CharacterGenderName;
enum class CharacterRaceName;

class ChooseAttributesPanel : public Panel
{
private:
	std::unique_ptr<TextBox> nameTextBox, raceTextBox, classTextBox;
	std::unique_ptr<Button> backToRaceButton, doneButton, incrementPortraitButton, 
		decrementPortraitButton;
	std::unique_ptr<CharacterClass> charClass;
	std::unique_ptr<CharacterGenderName> gender;
	std::unique_ptr<CharacterRaceName> raceName;
	std::string name;
	int portraitIndex;
protected:
	virtual void handleEvents(bool &running) override;
	virtual void handleMouse(double dt) override;
	virtual void handleKeyboard(double dt) override;
public:
	ChooseAttributesPanel(GameState *gameState, const CharacterClass &charClass, 
		const std::string &name, CharacterGenderName gender, CharacterRaceName raceName);
	virtual ~ChooseAttributesPanel();

	virtual void tick(double dt, bool &running) override;
	virtual void render(Renderer &renderer) override;
};

#endif
