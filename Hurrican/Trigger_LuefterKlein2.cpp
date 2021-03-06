// --------------------------------------------------------------------------------------
// Der kleine, kaputte Luefter
// --------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Trigger_LuefterKlein2.h"

// --------------------------------------------------------------------------------------
// Konstruktor
// --------------------------------------------------------------------------------------

GegnerLuefterKlein2::GegnerLuefterKlein2(int Wert1, int Wert2, bool Light)
{
	Handlung		= GEGNER_STEHEN;
	Value1			= Wert1;
	Value2			= Wert2;
	ChangeLight		= Light;
	Destroyable		= false;
	ForceLight		= true;
	OwnDraw			= true;
	Energy			= 100;
	AnimEnde		= 11;
	BackGround		= true;

	if (Value1 == 0)
		AnimSpeed = 0.5f;
	else
		AnimSpeed = Value1 / 10.0f;
}

// --------------------------------------------------------------------------------------
// Rendern
// --------------------------------------------------------------------------------------

void GegnerLuefterKlein2::DoDraw(void)
{
	D3DCOLOR Color = pTileEngine->LightValue(xPos, yPos, GegnerRect[GegnerArt], ForceLight);
	pGegnerGrafix[GegnerArt]->RenderSprite((float)(xPos-pTileEngine->XOffset), 
									  	   (float)(yPos-pTileEngine->YOffset), 
										   AnimPhase, Color, false);
}

// --------------------------------------------------------------------------------------
// "Bewegungs KI"
// --------------------------------------------------------------------------------------

void GegnerLuefterKlein2::DoKI(void)
{
	SimpleAnimation();	
}

// --------------------------------------------------------------------------------------
// LuefterKlein2 explodiert
// --------------------------------------------------------------------------------------

void GegnerLuefterKlein2::GegnerExplode(void)
{
}
