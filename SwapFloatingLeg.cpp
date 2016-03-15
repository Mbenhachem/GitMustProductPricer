
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include "SwapFloatingLeg.h"

using namespace QuantLib;


boost::shared_ptr<IborIndex> SwapFloatingLeg::getfloating_index() const
{
	return this->floating_index;
}

DayCounter SwapFloatingLeg::getfloatingLegDayCounter() const
{
	return this->floatingLegDayCounter;
}

Frequency SwapFloatingLeg::getfloatingLegFrequency() const
{
	return this->floatingLegFrequency;
}

void SwapFloatingLeg::setfloatingLegFrequency(Frequency floatingLegFrequency)
{
	this->floatingLegFrequency = floatingLegFrequency;
}

void SwapFloatingLeg::setfloatingLegDayCounter(DayCounter floatingLegDayCounter)
{
	this->floatingLegDayCounter = floatingLegDayCounter;
}

void SwapFloatingLeg::setfloating_index(boost::shared_ptr<IborIndex> floating_index)
{
	this->floating_index = floating_index;
}

SwapFloatingLeg::SwapFloatingLeg(boost::shared_ptr<IborIndex> Floating_index, DayCounter FloatingLegDayCounter, Frequency FloatingLegFrequency)
: floating_index(Floating_index), floatingLegDayCounter(FloatingLegDayCounter), floatingLegFrequency(FloatingLegFrequency)
{
}

Schedule SwapFloatingLeg::floatSchedule(Date settlementDate, Date maturity) const
{
	return Schedule(settlementDate, maturity, Period(floatingLegFrequency),
		TARGET(), ModifiedFollowing, ModifiedFollowing,
		DateGeneration::Forward, false);
}