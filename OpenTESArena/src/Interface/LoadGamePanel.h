#ifndef LOAD_GAME_PANEL_H
#define LOAD_GAME_PANEL_H

#include "Panel.h"

class Button;
class Renderer;
class Surface;
class TextBox;

class LoadGamePanel : public Panel
{
private:
	std::unique_ptr<TextBox> underConstructionTextBox;
	std::unique_ptr<Button> backButton;
	// up/down arrow buttons, saved game buttons...
protected:
	virtual void handleEvents(bool &running) override;
	virtual void handleMouse(double dt) override;
	virtual void handleKeyboard(double dt) override;
public:
	// This could get the game data boolean from the game state itself to determine
	// whether to return to the main menu or the pause menu.
	LoadGamePanel(GameState *gameState);
	virtual ~LoadGamePanel();

	virtual void tick(double dt, bool &running) override;
	virtual void render(Renderer &renderer) override;
};

#endif
