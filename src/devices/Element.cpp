/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**
 * @file		Element.cpp
 * @since		Jun 22, 2018
 * @author		Patricio A. Rossi (MeduZa)
 * @copyright	Copyright © 2018 Patricio A. Rossi (MeduZa)
 */

#include "Element.hpp"

using namespace LEDSpicer::Devices;

Element::Element(const string& name, uint8_t* pin) : name(name), pins{pin} {
	pins.shrink_to_fit();
}

Element::Element(
		const string& name,
		uint8_t* pinR,
		uint8_t* pinG,
		uint8_t* pinB
	) :
		name(name),
		pins{pinR, pinG, pinB
	} {
	pins.shrink_to_fit();
}

Element::Element(Element* other) : name(other->name) {
	for (auto p : other->pins)
		pins.push_back(nullptr);
}

void Element::setColor(const Color& color) {
	if (pins.size() == 3) {
		*pins[Color::Channels::Red] = color.getR();
		*pins[Color::Channels::Green] = color.getG();
		*pins[Color::Channels::Blue] = color.getB();
	}
	else {
		*pins[SINGLE_PIN] = color.getMonochrome();
	}
}

LEDSpicer::Color Element::getColor() {
	Color color;
	if (pins.size() == 1)
		color.set(*pins[SINGLE_PIN], *pins[SINGLE_PIN], *pins[SINGLE_PIN]);
	else
		color.set(
			*pins[Color::Channels::Red],
			*pins[Color::Channels::Green],
			*pins[Color::Channels::Blue]
		);
	return color;
}

void Element::setPinValue(uint8_t pinNumber, uint8_t val) {
	*pins[pinNumber] = val;
}

void Element::linkPin(uint8_t* val) {
	pins.push_back(val);
}

uint8_t Element::getPinValue(uint8_t pinNumber) const {
	return *pins[pinNumber];
}

uint8_t* const Element::getPin(uint8_t pinNumber) const {
	if (pinNumber > pins.size())
		throw Error("Invalid pin number");
	return pins[pinNumber];
}

const vector<uint8_t*>& Element::getPins() const {
	return pins;
}

uint8_t Element::size() const {
	return pins.size();
}

string Element::getName() {
	return name;
}