//OpenGLΕp·ιL[{[h
#pragma once
#include "Wave.h"
//ιΎ
void Keyboard(unsigned char key, int x, int y);



void Keyboard(unsigned char key, int x, int y)
{
	if ( false == flagStart && false == flagObsControl)
	{
		return;
	}

	float R;

	switch (key)
	{
	case 'w':
		if (rigid[0].vPos.x >= rect.size.x / 2.0 - rect.obs_left)
		{
			direction = -1.0;
		}
		rigid[0].vVel.x = direction * obsSpeed * 5;
		
		break;
	case 's':
		if (rigid[0].vPos.x <= -rect.size.x / 2.0 + rect.obs_left)
		{
			direction = 1.0;
		}
		rigid[0].vVel.x = direction * obsSpeed * 5;
		break;
	case 'a':
		R = rect.size.x / 6.0 - rect.obs_left;//ρ]Όa
		rigid[0].vVel.x = obsSpeed * 5 * rigid[0].vPos.y / R;
		rigid[0].vVel.y = -obsSpeed * 5 * rigid[0].vPos.x / R;

		break;
	case 'd':
		R = rect.size.x / 6.0 + rect.obs_left;//ρ]Όa
		rigid[0].vVel.x = -obsSpeed * 5 * rigid[0].vPos.y / R;
		rigid[0].vVel.y = obsSpeed * 5 * rigid[0].vPos.x / R;

		break;

	case 'z':
		//’§μ
		Jump();

		break;

	default:
		break;
	}

	
	rigid[0].vPos += rigid[0].vVel * deltaT;
	CalcLine();
}