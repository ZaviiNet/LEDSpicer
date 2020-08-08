/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**
 * @file      Restrictor.cpp
 * @since     Jul 7, 2020
 * @author    Patricio A. Rossi (MeduZa)
 *
 * @copyright Copyright © 2020 Patricio A. Rossi (MeduZa)
 *
 * @copyright LEDSpicer is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * @copyright LEDSpicer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * @copyright You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Restrictor.hpp"

using namespace LEDSpicer::Restrictors;

void Restrictor::initialize() {
	LogDebug("Initializing Restrictor " + getName());
	connect();
	claimInterface();
}

void Restrictor::terminate() {
	LogDebug("Disconnect " + getName());
	disconnect();
}

Restrictor::Ways Restrictor::str2ways(const string& ways) {
	if (ways == "1" or ways == "2" or ways == "strange2")
		return Ways::w2;
	if (ways == "vertical2")
		return Ways::w2v;
	if (ways == "3 (half4)" or ways == "4")
		return Ways::w4;
	if (ways == "4x")
		return Ways::w4x;
	if (ways == "16" or ways == "analog")
		return Ways::analog;
	if (ways == "mouse")
		return Ways::mouse;
	return Ways::w8;
}

string Restrictor::ways2str(Ways ways) {
	switch (ways) {
	case Ways::w2:
		return "horizontal 2 ways";
	case Ways::w2v:
		return "vertical 2 ways";
	case Ways::w4:
		return "4 ways";
	case Ways::w4x:
		return "diagonal 4 ways";
	case Ways::w8:
		return "8 ways";
	case Ways::analog:
		return "analog";
	case Ways::mouse:
		return "mouse";
	}
	return "";
}

