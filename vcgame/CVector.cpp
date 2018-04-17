/* source: https://github.com/DK22Pac/plugin-sdk */

#include "vc_game.h"

float CVector::Normalise() 
{
	return (( float (*)(CVector*))(g_libGTAVC+0x180138+1))(this);
}