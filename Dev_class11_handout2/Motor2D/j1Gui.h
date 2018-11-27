#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

//class InteractiveUI
//{
//public:
//	void Draw();
//	void OnClick();
//
//private:
//	SDL_Texture * tex;
//	iPoint position;
//};
//
//class NoneInteractiveUI
//{
//public:
//	void Draw();
//
//private:
//	iPoint position;
//};
//
//class Label : public NoneInteractiveUI
//{
//public:
//};
//
//class Image : public NoneInteractiveUI
//{
//private:
//	SDL_Texture * tex;
//};
//
//class Button : public InteractiveUI
//{
//public:
//	enum STATE
//	{
//		IDLE,
//		HOVERED,
//		PRESSED
//	};
//
//	Label title;
//};
//
//class CheckBox : public InteractiveUI
//{
//public:
//	bool active = false;
//	Label title;
//};
//
//class InputText : public InteractiveUI
//{
//	Label input;
//	Label title;
//	bool active = false;
//};
class InteractiveUI
{
public:
	
	void OnClick();
	void Draw();

private:
	SDL_Texture * tex;
	iPoint position;
};

class NoneInteractiveUI
{
public:
	void Draw();

private :
	iPoint position;
};

class Label : public NoneInteractiveUI
{

public:
};

class Image : public NoneInteractiveUI
{
public:
	SDL_Texture * tex;
};

class Button : public InteractiveUI
{
public:
	enum STATE
	{
		IDLE,
		HOVERED,
		PRESSED
	};

	Label title;
};

class CheckBox : public InteractiveUI
{
public:
	bool active = false;
	Label title;
};

class InputText : public InteractiveUI
{
	Label input;
	Label title;
	bool active = false;
};


// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions

	void CreateImage(int x, int y);

	const SDL_Texture* GetAtlas() const;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
	p2List<InteractiveUI*> buttons;
	p2List<NoneInteractiveUI*> staticUI;
};

#endif // __j1GUI_H__