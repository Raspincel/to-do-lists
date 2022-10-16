#pragma once
#ifndef ARROW_H
#define ARROW_H

#include "BaseArrow.h"


// TODO: un-overload draw()
class Arrow : public BaseArrow 
{
private:

	// initial setup
	void setArrow() override;
	void setStandardTexture() override;
	void setTextCoords() override;

	// when hovering over the arrow
	void setHoverTexture() override;

public:
	Arrow() : BaseArrow()
	{
		setArrow();
		setStandardTexture();
		setTextCoords();
	}

	void arrowInteraction() override;
	
};

#endif // !ARROW_H
