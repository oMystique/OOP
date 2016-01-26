#include "frame.h"

Frame::Frame(Vector2f const size,
	Vector2f const pos,
	String const name):
	AppObjects(size, pos, name) {
	CreateFrame();
}

void Frame::CreateFrame() {
	frameRect.setFillColor(DEFAULT_FRAME_COLOR);
	frameRect.setOutlineColor(DEFAULT_FRAME_OUTLINE_COLOR);
	frameRect.setOutlineThickness(GET_HALF);
	frameRect.setSize(size);
	topLeftPoint.setRadius(FRAME_POINT_RADIUS);
	topLeftPoint.setOrigin(topLeftPoint.getGlobalBounds().width / GET_HALF,
							topLeftPoint.getGlobalBounds().height / GET_HALF);
	topLeftPoint.setFillColor(Color::Red);
	topRightPoint.setRadius(FRAME_POINT_RADIUS);
	topRightPoint.setOrigin(topLeftPoint.getGlobalBounds().width / GET_HALF,
		topLeftPoint.getGlobalBounds().height / GET_HALF);
	topRightPoint.setFillColor(Color::Red);
	botLeftPoint.setRadius(FRAME_POINT_RADIUS);
	botLeftPoint.setOrigin(topLeftPoint.getGlobalBounds().width / GET_HALF,
		topLeftPoint.getGlobalBounds().height / GET_HALF);
	botLeftPoint.setFillColor(Color::Red);
	botRightPoint.setRadius(FRAME_POINT_RADIUS);
	botRightPoint.setOrigin(topLeftPoint.getGlobalBounds().width / GET_HALF,
		topLeftPoint.getGlobalBounds().height / GET_HALF);
	botRightPoint.setFillColor(Color::Red);
	SetFramePosition();
}

void Frame::SetFramePosition() {
	frameRect.setPosition(pos);
	topLeftPoint.setPosition(frameRect.getGlobalBounds().left,
							frameRect.getGlobalBounds().top);
	topRightPoint.setPosition(frameRect.getGlobalBounds().left +
								frameRect.getGlobalBounds().width,
							frameRect.getGlobalBounds().top);
	botLeftPoint.setPosition(frameRect.getGlobalBounds().left,
							frameRect.getGlobalBounds().top +
								frameRect.getGlobalBounds().height);
	botRightPoint.setPosition(frameRect.getGlobalBounds().left +
								frameRect.getGlobalBounds().width,
							frameRect.getGlobalBounds().top +
								frameRect.getGlobalBounds().height);
}

