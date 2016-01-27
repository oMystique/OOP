#include "frame.h"

Frame::Frame(Vector2f const size,
	Vector2f const pos,
	String const name):
	AppObjects(size, pos, name) {
	CreateFrame();
	temp = { 0.f, 0.f };
}

Frame::~Frame() {
	appObj = nullptr;
}

void Frame::ResetFrame(Vector2f const tSize, Vector2f const tPos) {
	size = tSize;
	pos = tPos;
	CreateFrame();
}


void Frame::SetPointsPosition() {
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
	SetPointsPosition();
}


Vector2f Frame::GetSize() {
	return { frameRect.getGlobalBounds().width, frameRect.getGlobalBounds().height };
}
Vector2f Frame::GetPos() {
	return { NULL, NULL };
}

void Frame::SetEditObject(AppObjects *&appObject) {
	appObj = appObject;
}

void Frame::SetFrameOrigin(Vector2f const mousePos) {
	if (topLeftPoint.getGlobalBounds().contains(mousePos)) {
		temp = { 0.f, 0.f };
	}
	else if (topRightPoint.getGlobalBounds().contains(mousePos)) {
		temp = { -frameRect.getGlobalBounds().width, 0.f };
	}
	else if (botLeftPoint.getGlobalBounds().contains(mousePos)) {
		temp = { 0.f, -frameRect.getGlobalBounds().height };
	}
	else if (botRightPoint.getGlobalBounds().contains(mousePos)) {
		temp = { -frameRect.getGlobalBounds().width, -frameRect.getGlobalBounds().height };
	}
}