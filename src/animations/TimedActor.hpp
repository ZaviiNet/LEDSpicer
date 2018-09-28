/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**
 * @file		TimedActor.hpp
 * @ingroup
 * @since		Sep 16, 2018
 * @author		Patricio A. Rossi (MeduZa)
 * @copyright	Copyright © 2018 Patricio A. Rossi (MeduZa)
 */

#include "Actor.hpp"

#ifndef TIMEDACTOR_HPP_
#define TIMEDACTOR_HPP_ 1

namespace LEDSpicer {
namespace Animations {

/**
 * LEDSpicer::TimedActor
 *
 * Class to add timing functionality to actors.
 */
class TimedActor: public Animations::Actor {

public:

	TimedActor(umap<string, string>& parameters, Group* const group);

	~TimedActor() {}

protected:

	uint8_t
		/// Current change frame factor.
		changeFrame = 1,
		/// Total number of frames to actually move to the next actor frame.
		changeFrameTotal;

	void virtual advanceActorFrame();
};

}} /* namespace LEDSpicer */

#endif /* TIMEDACTOR_HPP_ */